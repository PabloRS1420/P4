#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "tree.h"
#include "types.h"


int main(int argc, char const *argv[]){
    int x;
    Tree *pa = NULL;
    FILE *fp = fopen("argv[1]", "r+");
    if(fp == NULL) {
        printf("Error abriendo el archivo");
        return -1;
    }
    
    while(fscanf(fp, "%d", &x)){
        tree_insert(pa, x);
    }
    
    printf("> ./p4_e2 numeros.txt");
    x = tree_numNodes(pa);
    printf("Numero de nodos: %d", x);
    x = tree_depth(pa);
    printf("Profundidad: %d", x);
    printf("> Introduzca un numero: ");
    scanf("%d", &x);
    printf("Numero introducido: %d", x);
    if(tree_find(pa, x) == TRUE) {
        printf("El dato %d se encuentra dentro del Arbol", x);
    }
    else {
        printf("El dato %d no se encuentra dentro del Arbol", x);
    }
    
}