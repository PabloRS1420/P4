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

void tree_destroy(Tree* pa) {
}

Status tree_insert(Tree* pa, const void* po) {
}

Bool tree_find(Tree* pa, const void* po) {
}

Bool tree_isEmpty( const Tree* pa) {
}

int tree_depth(const Tree* pa) {
}

int tree_numNodes(const Tree* pa) {
}

Status tree_preOrder(FILE* f, const Tree* pa) {
}

Status tree_inOrder(FILE* f, const Tree* pa) {
}

Status tree_postOrder(FILE* f, const Tree* pa) {
}
