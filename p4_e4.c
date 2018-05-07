#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "tree.h"
#include "npoint.h"
#include "types.h"

int main(int argc, char const *argv[]) {
    int x;
    Status s;
    Tree *pa = NULL;
    FILE *fp = fopen("argv[1]", "r+");
    if(fp == NULL) {
        printf("Error abriendo el archivo");
        return -1;
    }
    
    while(fscanf(fp, "%d", &x)){
        tree_insert(pa, x);
    }
    
    x = tree_numNodes(pa);
    printf("\nNumero de nodos: %d", x);
    x = tree_depth(pa);
    printf("\nProfundidad: %d", x);
	printf("\nOrden previo: ");
    s = tree_preOrder(stdout, pa);
    if(s==ERROR) printf("\n Arbol vacio");
    printf("\nOrden medio: ");
    s = tree_inOrder(stdout, pa);
    if(s==ERROR) printf("\n Arbol vacio");
    printf("\nOrden posterior: ");
    s = tree_postOrder(stdout, pa);
    if(s==ERROR) printf("\n Arbol vacio");
    printf("\n> Introduzca un numero: ");
    scanf("%d", &x);
    printf("\nNumero introducido: %d", x);
    if(tree_find(pa, x) == TRUE) {
        printf("\nEl dato %d se encuentra dentro del Arbol", x);
    }
    else {
        printf("\nEl dato %d NO se encuentra dentro del Arbol", x);
    }
}
