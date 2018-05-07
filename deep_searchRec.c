#include "deep_searchRec.h"

Point *deep_searchRec(Map *m, Point *p_in, Move strategy[4]){
    if (p_in == NULL) return NULL;
    if (point_isOutput(p_in)) return p_in;
    
    int i;
    Point *pAux  = point_ini(0,0,+);
    Point *p_vecino = point_ini(0,0,+);
    map_print2(stdout, m);
    point_setSymbol(p_in,VISITED);
    
    for(i=0; i<4; i++) { /*each movement in strategy*/
        p_vecino = map_getNeighborPoint(m, p_in, strategy[movement]);
        if (p_vecino != NULL) {
            if ((point_getSymbol(p_vecino) != BARRIER) && (point_getSymbol(p_vecino) != VISITED) && (point_getSymbol(p_vecino) != VISITING)) {
                point_setParent(p_vecino, p_in);
                if (!point_isOutput(p_vecino)) {
                    point_setSymbol( p_vecino, VISITING);
                }
                pAux = deep_searchRec(m, p_vecino, strategy);
                if (pAux != NULL){
                    fprintf(stdout,"SOLUCIÓN\n");
                    map_destroy(m);
                    point_destroy(pAux);
                    point_destroy(p_vecino);
                    return pAux;
                }   
            }
        }
    }
    return NULL;
}
