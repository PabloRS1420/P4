#indef DEEP_SEARCHREC_H
#define DEEP_SEARCHREC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "map_solver.h"

Point *deep_searchRec(Map *m, Point *p_in, Move strategy[4]);

#endif
