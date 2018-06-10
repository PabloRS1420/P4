#include "tree.h"

typedef struct _NodeBT {
    void* info;
    struct _NodeBT* left;
    struct _NodeBT* right;
} NodeBT;

struct _Tree {
    NodeBT *root;
    destroy_element_function_type   destroy_element_function;
    copy_element_function_type      copy_element_function;
    print_element_function_type     print_element_function;
    cmp_element_function_type       cmp_element_function;
};

NodeBT *node_ini() {
    NodeBT *pn = NULL; 
    pn = (NodeBT *) malloc(sizeof(NodoAB)); 
    if (!pn) return NULL;
    
    info(pn) = left(pn) = right(pn) = NULL;
    return pn; 
}

void node_destroy(NodeBT *pn) {
    if (pn) {
        free(pn->info);
        free(pn);
    }
}

Tree *tree_ini(destroy_element_function_type f1, copy_element_function_type f2, print_element_function_type f3, cmp_element_function_type f4) {
    Tree *t = NULL;
    t = (tree *) malloc(siceof(tree));
    
    t->root = NULL;
    t->destroy_element_function = f1;
    t->copy_element_function = f2;
    t->print_element_function = f3;
    t->cmp_element_function = f4;
    
    return t;
}

void tree_destroy(Tree *pa) {
    destroy_element_function((Tree *)pa);
}

Status tree_insert(Tree *pa, const void *po) {
    if (!pa || !po) return ERROR;
    return tree_insert_rec(&root(pa), po);
}
Status tree_insert_rec(NodeBT **ppn, Element *pe) {
    int cmp;

    if (*ppn == NULL) {   //Encontrado lugar donde insertar: nodo nuevo apuntado por *ppn
        *ppn = node_ini();
        if (*ppn == NULL)  return ERROR;
        if (((*ppn)->info == copy_element_function((NodeTB *) pe)) == NULL) {
            node_destroy(ppn);
            return ERROR;
        }
        return OK;
    }
    // Si todavía no se ha encontrado el hueco donde insertar, buscarlo en subárbol
    // izquierdo o derecho, según corresponda:
    cmp = cmp_element_function((Int *)pe, (Int *)info(*ppn));
    if (cmp < 0) return tree_insert_rec(&izq(*ppn), pe);
    if (cmp > 0) return tree_insert_rec(&der(*ppn), pe);
    return OK;
    // Solo se sale por aquí si el elemento ya estaba en el árbol (cmp = 0)
}

Bool tree_find(Tree* pa, const void* po) {
    if ( tree_isEmpty(pa) == TRUE) return NULL_BOOLEAN;
    else if (pa->root->info == po) return pa;
    else if (po < pa->root->info) return tree_find(pa->root->left, po)
    else return tree_find(pa->root->right, po)
}

Bool tree_isEmpty( const Tree* pa) {
    if(!pa) return TRUE;
    
    if(!pa->root) return TRUE;
    else return FALSE;
}

int tree_depth(const Tree* pa) {
    int x = tree_numNodes(pa);
    int i, j;
    
    for(i=1, j=1; x <= i; (i*2)+1, j++)
    return j;
}

int tree_numNodes(const Tree* pa) {
    if (tree_isEmpty(pa) == TRUE) return 0;
    int i;
    else {
        i++;
        i = tree_numNodes(pa->root->left);
        i = tree_numNodes(pa->root->right);
        return OK;
    }
}

Status tree_preOrder(FILE* f, const Tree* pa) {
    if (tree_isEmpty(pa) == TRUE) return ERROR;
    else {
        fprintf(f, "%s", pa->root->info);
        tree_preOrder(f, pa->root->left);
        tree_preOrder(f, pa->root->right);
        return OK;
    }
}

Status tree_inOrder(FILE* f, const Tree* pa) {
    if (tree_isEmpty(pa) == TRUE) return ERROR;
    else {
        if (tree_isEmpty(pa->root->left) == FALSE){
            tree_inOrder(f, pa->root->left);
        }
        fprintf(f, "%s", pa->root->info);
        if (tree_isEmpty(pa->root->right) == FALSE){
            tree_inOrder(f, pa->root->right);
        }            
        return OK;
    }
}

Status tree_postOrder(FILE* f, const Tree* pa) {
    if (tree_isEmpty(pa) == TRUE) return ERROR;
    else {
        if (tree_isEmpty(pa->root->left) == FALSE){
            tree_postOrder(f, pa->root->left);
        }
        if (tree_isEmpty(pa->root->right) == FALSE){
            tree_postOrder(f, pa->root->right);
        }            
        fprintf(f, "%s", pa->root->info);
        return OK;
    }
}
