#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "tree.h"
#include "npoint.h"
#include "types.h"

#define MAX_LINE 150

int main(int argc, char const *argv[]) {
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
