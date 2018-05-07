#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "deep_searchRec.h"

int main(int argc, char const *argv[]) {
    int nFil, nCol, i, j;
    char symbol;
    FILE *fp = fopen("argv[1]", "r+");
    if(fp == NULL) {
        printf("Error abriendo el archivo");
        return -1;
    }
    Map *map = map_ini();
    Point *pAUX = point_ini(0, 0, +);
    Point *pOutput = point_ini(0, 0, +);
    fscanf(fp, "%d %d", &nFil, &nCol);
    map_setSize(map, nFil, nCol);
    
    for(i=0; i<nFil; i++){
        for(j=0; i<nCol; j++){
            fscanf(fp, "%s", symbol);
            point_setCoordinateX(pAux, i);
            point_setCoordinateY(pAux, j);
            point_setSymbol(pAux, symbol);
            map_setPoint(map, pAux);
        }
    }
    
    pAux = map_getInput(map);
    pOutput = deep_searchRec(map, pAux, Move strategy[4]);
