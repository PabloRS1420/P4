#ifndef MAP_SOLVER_H
#define MAP_SOLVER_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "map.h"
#include "point.h"

#define MAX_NOMBRE  20

int mapsolver_stack(const char* map_file, const Move strat[4]);
int mapsolver_queue(const char *map_file, const Move strat[4]);
void mapsolver_run(const char* map_file, const Move strat[][4], const int num_strategies);

#endif MAP_SOLVER_H
