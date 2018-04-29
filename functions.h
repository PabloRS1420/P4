#indef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void destroy_element_function(void *e);
void *copy_element_function(const void *e);
int print_element_function(FILE *f, const void *e);
int cmp_elementlist_function(const void *e1, const void *e2);

#endif FUNCTIONS_H
