#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Point deep_searchRec(Map m, Point p_in, Move strategy[4]){
    if (p_in == NULL) return NULL;
    if (point_isOutput(p_in)) return p_in;
    
    point_setSymbol(p_in,VISITED);
    
    for each movement in strategy{
        p_vecino = map_getNeighborPoint(m, p_in, strategy[movement]);
        if (p_vecino != NULL) {
            if ((point_getSymbol(p_vecino) != BARRIER) && (point_getSymbol(p_vecino) != VISITED) && (point_getSymbol(p_vecino) != VISITING)) {
                point_setParent(p_vecino, p_in);
                if ( !point_isOutput(p_vecino)) {
                    point_setSymbol( p_vecino, VISITING);
                }
                paux = deep_searchRec(p_map, p_vecino, strategy);
                if ( paux != NULL ){
                    fprintf(stdout,"SOLUCIÓN \n");
                    return paux;
                }   
            }
        }
    }
    
    return NULL;
}
