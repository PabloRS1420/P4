#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "tree.h"
#include "npoint.h"
#include "types.h"

#define MAX_LINE 150

NPoint *read_point_from_file(FILE * f_in)
{
    NPoint *point;
    int j, dim;
    float aux;
    char name[MAX_LINE];

    fscanf(f_in, "%d", &dim);
    point = npoint_ini(dim);
    for (j = 0; j < dim; j++) {
	fscanf(f_in, "%f", &aux);
	npoint_setCoordinate(point, j, aux);
    }
    fscanf(f_in, "%s\n", name);
    npoint_setName(point, name);

    return point;
}

void destroy_npoint_function(void *e)
{
    npoint_free((NPoint *) e);
}

void *copy_npoint_function(const void *e)
{
    return npoint_copy((NPoint *) e);
}

int print_npoint_function(FILE * f, const void *e)
{
    return npoint_print(f, (NPoint *) e);
}

int cmp_npoint_function(const void *e1, const void *e2)
{
    return npoint_cmp((NPoint *) e1, (NPoint *) e2);
}

int compare(const void *b, const void *a)
{
    NPoint **e1, **e2;
    e1 = (NPoint **) a;
    e2 = (NPoint **) b;
    return npoint_cmp(*e1, *e2);
}

int getNumberLines(FILE * pf)
{
    char line[MAX_LINE];
    int n = 0;
    while (fgets(line, MAX_LINE, pf) != NULL) {
	n++;
    }
    return n;
}

void loadDataFromFile(FILE * pf, NPoint *** pdata)
{
    NPoint **paux = *pdata;
    NPoint *p;

    while (!feof(pf)) {
	p = read_point_from_file(pf);
	*paux = npoint_copy(p);
	paux++;
	npoint_free(p);
    }
}

void balance(NPoint ** data, Tree * t, int first, int last)
{
    int middle = (first + last) / 2;
    NPoint *p;

    if (first <= last) {
	p = *(&(data[0]) + middle);
	if (tree_insert(t, p) == ERROR) {
	    fprintf(stdout, "Point ");
	    npoint_print(stdout, p);
	    fprintf(stdout, " not inserted!\n");
	}

	balance(data, t, first, middle - 1);
	balance(data, t, middle + 1, last);
    }
}

Tree *loadBalancedTreeFromData(NPoint ** data, int n)
{
    Tree *t;

    t = tree_ini(destroy_npoint_function, copy_npoint_function,
		 print_npoint_function, cmp_npoint_function);

    balance(data, t, 0, n - 1);

    return t;
}

Tree *loadTreeFromData(NPoint ** data, int n)
{
    Tree *t;
    NPoint *point;
    int i;

    t = tree_ini(destroy_npoint_function, copy_npoint_function,
		 print_npoint_function, cmp_npoint_function);

    for (i = 0; i < n; i++) {
	point = data[i];
	if (tree_insert(t, point) == ERROR) {
	    fprintf(stdout, "Point ");
	    npoint_print(stdout, point);
	    fprintf(stdout, " not inserted!\n");
	}
    }

    return t;
}

int main(int argc, char const *argv[])
{
    FILE *f_in = NULL, *f_out = NULL;
    Tree *pa = NULL;
    NPoint **data, *point;
    int i, n;
    time_t time;
    double time_in_secs;


    if (argc < 2) {
	printf("Falta el fichero con puntos (un punto por línea).\n");
	return -1;
    }

    f_in = fopen(argv[1], "r");

    if (!f_in) {
	return 1;
    }

    f_out = stdout;

    n = getNumberLines(f_in);
    fclose(f_in);
    fprintf(f_out, "%d líneas leídas\n", n);
    data = (NPoint **) malloc(n * sizeof(NPoint *));
    f_in = fopen(argv[1], "r");
    loadDataFromFile(f_in, &data);
    fclose(f_in);

    /* We want to compare only the last characters, so it works when debugging */
    if (strcmp("p4_e3", argv[0] + (strlen(argv[0]) - strlen("p4_e3"))) ==
	0) {
	time = clock();
	pa = loadTreeFromData(data, n);
	time = clock() - time;
	time_in_secs = ((float) time) / CLOCKS_PER_SEC;
    } else
	if (strcmp
	    ("p4_e3_bal",
	     argv[0] + (strlen(argv[0]) - strlen("p4_e3_bal"))) == 0) {
	qsort(data, n, sizeof(NPoint *), &compare);
	fprintf(f_out, "Datos ordenados\n");
	time = clock();
	pa = loadBalancedTreeFromData(data, n);
	time = clock() - time;
	time_in_secs = ((float) time) / CLOCKS_PER_SEC;
    }

    for (i = 0; i < n; i++) {
	npoint_free(data[i]);
    }
    free(data);

    fprintf(f_out,
	    "\nTiempo de creación del árbol: %ld ticks (%f segundos)\n",
	    (long) time, time_in_secs);
    fprintf(f_out, "Numero de nodos: %d\nProfundidad: %d\n",
	    tree_numNodes(pa), tree_depth(pa));

    /*tree_inOrder(f_out, pa);fprintf(f_out, "\n"); */

    fprintf(stdout,
	    "Introduce un punto para buscar en el árbol (siguiendo el mismo formato que en el fichero de entrada):\n");
    point = read_point_from_file(stdin);
    time = clock();
    if (tree_find(pa, point) == TRUE) {
	fprintf(stdout, "Elemento encontrado!\n");
    } else {
	fprintf(stdout, "Elemento NO encontrado!\n");
    }
    time = clock() - time;
    time_in_secs = ((float) time) / CLOCKS_PER_SEC;
    npoint_free(point);
    fprintf(f_out,
	    "\nTiempo de búsqueda en el árbol: %ld ticks (%f segundos)\n",
	    (long) time, time_in_secs);

    tree_destroy(pa);

    return 0;
}
