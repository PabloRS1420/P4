#include "map_solver.h"

//Move strategy[] = { RIGHT, LEFT, UP, DOWN };

Move strategies [4][4] = {
    { RIGHT, LEFT, UP, DOWN },
    { DOWN, RIGHT, LEFT, UP },
    { UP, DOWN, RIGHT, LEFT },
    { LEFT, UP, DOWN, RIGHT }
};

int mapsolver_stack(const char* map_file, const Move strat[4]){
    Map *map = map_ini();
    FILE *fp = fopen("map_file", "r+");
    fscanf(fp, "%d %d", &nFil, &nCol);
    map_setSize(map, nFil, nCol);
    
    Stack *s = stack_ini();
    int i;
    Point *p1 = point_ini(0, 0, +);
    p1 = map_getInput(map);
    Point *p2 = point_ini(0, 0, +);
    Point *p3 = point_ini(0, 0, +);
    stack_push(s, p);
    while(stack_isEmpty(s) != TRUE) {
        p2 = point_copy_all(stack_pop(s));
        if(point_getSymbol(p2) != V) {
            point_setSymbol(p2, V);
            map_setPoint(m, p2);
            for(i=0; i<5; i++){
	        p3 = map_getNeighborPoint(map, p2, strat[i]);
                if (point_isOutput(p3) == TRUE) return w;
                if (point_isSpace(p3) == TRUE) stack_push(s, p3);
            }
        }
    }
    return NULL;
}

int mapsolver_queue(const char *map_file, const Move strat[4]){
    Map *map = map_ini();
    FILE *fp = fopen("map_file", "r+");
    fscanf(fp, "%d %d", &nFil, &nCol);
    map_setSize(map, nFil, nCol);
    
    Queue *q = queue_ini(, , );
    int i;
    Point *p1 = point_ini(0, 0, +);
    p1 = map_getInput(map);
    Point *p2 = point_ini(0, 0, +);
    Point *p3 = point_ini(0, 0, +);
    queue_insert(q, p);
    while(queue_isEmpty(q) != TRUE) {
        p2 = point_copy_all(queue_extract(q));
        if(point_getSymbol(p2) != V) {
            point_setSymbol(p2, V);
            map_setPoint(m, p2);
            for(i=0; i<5; i++){
	            p3 = map_getNeighborPoint(map, p2, strat[i]);
		        p3->parent = point_copy(p2);
                if (point_isOutput(p3) == TRUE) return w;
                if (point_isSpace(p3) == TRUE) stack_push(s, p3);
            }
        }
    }
    return NULL;
}

void mapsolver_run(const char* map_file, const Move strat[][4], const int num_strategies){
    int i, x=0;
    char nombre[MAX_NOMBRE-1];
    for(i=0; i<4; i++){
        if(i==0) nombre = "ESTRATEGIA 0213";
        else if(i==0) nombre = "ESTRATEGIA 3021";
        else if(i==0) nombre = "ESTRATEGIA 1302";
        else nombre = "ESTRATEGIA 2130";
        fprintf(stdout, "PILA: %s", nombre);
        x = mapsolver_stack(map_file, Move strat[i]);
        if(!x) fprintf(stdout, "PILA: SALIDA NO ENCONTRADA");
        else fprintf(stdout, "PILA: SALIDA ENCONTRADA. NUMERO DE MOVIMIENTOS: %d", x);
    }
    
    for(i=0; i<4; i++){
        if(i==0) nombre = "ESTRATEGIA 0213";
        else if(i==0) nombre = "ESTRATEGIA 3021";
        else if(i==0) nombre = "ESTRATEGIA 1302";
        else nombre = "ESTRATEGIA 2130";
        fprintf(stdout, "COLA: %s", nombre);
        x = mapsolver_queue(map_file, Move strat[i]);
        if(!x) fprintf(stdout, "COLA: SALIDA NO ENCONTRADA");
        else fprintf(stdout, "COLA: SALIDA ENCONTRADA. NUMERO DE MOVIMIENTOS: %d", x);
    }
}
