#include "map.h"

typedef struct _Map {
    Point *point [4096] [4096];
    int nRows, nCols;
}
 
Map *map_ini (){
    Map *m = NULL;
    m = (Map *) malloc(siceof(Map));
    if(m==NULL) return NULL;

    return m;
}

void map_destroy(Map *map){
    if(map!=NULL) free(map);
}

int map_getNrows(const Map *map){
    if(map==NULL) return NULL;

    return map.nRows;
}

int map_getNcols(const Map *map){
    if(map==NULL) return NULL;

    return map.nCols;
}

Point *map_getInput(const Map *map){
    if(map==NULL) return NULL;
	
    for(i=0; i<map.nRows; i++){
        for(j=0; j<map.nCols; j++){
            if(point_isInput(map->point[i][j]) return map->point[i][j];
        }
    }
}

Point *map_getOutput(const Map *map){
    if(map==NULL) return NULL;
	
    for(i=0; i<map.nRows; i++){
        for(j=0; j<map.nCols; j++){
            if(point_isOutput(map->point[i][j]) return map->point[i][j];
        }
    }
}
			   
Point *map_getNeighborPoint(const Map *map, const Point *p, const Move mov){
    if(map==NULL||p==NULL||mov<0||mov>4) return NULL;
	
    int x = point_getCoordinateX(p);
    int y = point_getCoordinateY(p);
	
    if(mov=="RIGHT") return map->point[x][y+1];
    else if(mov=="UP") return map->point[x+1][y];
    else if(mov=="LEFT") return map->point[x][y-1];
    else if(mov=="DOWN") return map->point[x-1][y];
    else return p;
}
			
Status map_setSize(Map *map, int row, int col){
    if ((map==NULL)||(row<0)||(col<0)||(row*col>4096)) return NULL;
	
    Map.nRows=row;
    Map.nCols=col;
    return OK;
}

Status map_setPoint(Map *map, const Point *p){
    if((map==NULL)||(p==NULL)) return NULL;
	
    int i, j, x, y;
    char symbol;
    if(point_isInput(p)){
        for(i=0; i<Map.nRows; i++){
            for(j=0; j<Map.nCols; j++){
                if((point_getCoordenadaX(p)==point_getCoordenadaX(Map->point[i][j])) &&(point_getCoordenadaY(p)==point_getCoordenadaY(Map->point[i][j]))){
                    Map.point[i][j]=point_copy(p)
                }
                if(point_isInput(Map->point[i][j]==TRUE){
                    Point_destroy(Map->point[i][j]);
                }
            }
        }
    }
    else if(point_isOutput(p)){
        for(i=0; i<Map.nRows; i++){
            for(j=0; j<Map.nCols; j++){
                if((point_getCoordenadaX(p)==point_getCoordenadaX(Map->point[i][j])) &&(point_getCoordenadaY(p)==point_getCoordenadaY(Map->point[i][j]))){
                    Map.point[i][j]=point_copy(p)
                }
                if(point_isOutput(Map->point[i][j]==TRUE){
                    Point_destroy(Map->point[i][j]);
                }
            }
        }
    }
    else{
        for(i=0; i<Map.nRows; i++){
            for(j=0; j<Map.nCols; j++){
                if((point_getCoordenadaX(p)==point_getCoordenadaX(Map->point[i][j])) &&(point_getCoordenadaY(p)==point_getCoordenadaY(Map->point[i][j]))){
                    Map.point[i][j]=point_copy(p)
                }
				else{
                    x=point_getCoordenadaX(p);
                    y=point_getCoordenadaY(p);
                    symbol=point_getsymbol(p);
                    Map->point[x][y]=point_ini(x, y, symbol);
                }
            }
        }
    }
    return OK;
}

int map_print(FILE *f, const Map *map){
    return fprintf(f, "Filas: %d, Columnas: %d", map_getNrows(map), map_getNcols(map));
}

Point *deep_search_pila(Map *map, Point *p){
    Stack *s = stack_ini();
    int i;
    Point *p2 = point_ini(0, 0, +);
    Point *p3 = point_ini(0, 0, +);
    stack_push(s, p);
    while(stack_isEmpty(s) != TRUE) {
        p2 = point_copy_all(stack_pop(s));
        if(point_getSymbol(p2) != V) {
            point_setSymbol(p2, V);
            map_setPoint(m, p2);
            for(i=0; i<5; i++){
	        p3 = map_getNeighborPoint(map, p2, i);
                if (point_isOutput(p3) == TRUE) return w;
                if (point_isSpace(p3) == TRUE) stack_push(s, p3);
            }
        }
    }
    return NULL;
}
		   
Point deep_search_cola(Map *map, Point *p){
    Queue *q = queue_ini(, , );
    int i;
    Point *p2 = point_ini(0, 0, +);
    Point *p3 = point_ini(0, 0, +);
    queue_insert(q, p);
    while(queue_isEmpty(q) != TRUE) {
        p2 = point_copy_all(queue_extract(q));
        if(point_getSymbol(p2) != V) {
            point_setSymbol(p2, V);
            map_setPoint(m, p2);
            for(i=0; i<5; i++){
	        p3 = map_getNeighborPoint(map, p2, i);
		p3->parent = point_copy(p2);
                if (point_isOutput(p3) == TRUE) return w;
                if (point_isSpace(p3) == TRUE) stack_push(s, p3);
            }
        }
    }
    return NULL;
}

