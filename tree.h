#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

typedef struct _Tree Tree;
/* Tipos de los punteros a función soportados por el árbol */
typedef void (*destroy_element_function_type)(void*);
typedef void (*(*copy_element_function_type)(const void*));
typedef int (*print_element_function_type)(FILE *, const void*);
/* Esta función devuelve un entero menor, igual o mayor que 0 según si el primer argumento es menor, igual o mayor que el segundo argumento */
typedef int (*cmp_element_function_type)(const void*, const void*);

/* Inicializa el árbol reservando memoria */
Tree *tree_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3, cmp_element_function_type f4);

/* Libera el árbol y todos sus elementos */
void tree_destroy(Tree* pa);

/* Inserta en el árbol pa una copia del puntero po, devolviendo ERROR si el elemento ya existía en el árbol */
Status tree_insert(Tree* pa, const void* po);

/* Devuelve TRUE si se puede encontrar po en el árbol pa */
Bool tree_find(Tree* pa, const void* po);

/* Comprueba si un árbol está vacío */
Bool tree_isEmpty( const Tree* pa);

/* Devuelve la profundidad del árbol pa, considerando que un árbol vacío tiene profundidad -1 */
int tree_depth(const Tree* pa);

/* Devuelve el número de nodos del árbol pa, considerando que un árbol vacío tiene 0 nodos */
int tree_numNodes(const Tree* pa);

/******* Funciones de recorrido del árbol ********/
/* Muestra el recorrido de un árbol en orden previo */
Status tree_preOrder(FILE* f, const Tree* pa);

/* Muestra el recorrido de un árbol en orden medio */
Status tree_inOrder(FILE* f, const Tree* pa);

/* Muestra el recorrido de un árbol en orden posterior */
Status tree_postOrder(FILE* f, const Tree* pa);

#endif TREE_H
