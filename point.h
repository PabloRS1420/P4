/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   point.h
 * Author: deped
 *
 * Created on 8 de febrero de 2018, 14:18
 */

#ifndef POINT_H
#define POINT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "types.h"
#define ERRORCHAR 'E'
#define INPUT 'i'
#define VISITED 'v'
#define OUTPUT 'o'
#define BARRIER '+'
#define SPACE ' '
    
typedef struct _Point Point;    
/* Inicializa un punto, reservando memoria y devolviendo el punto inicializado si lo ha hecho correctamente o NULL
si no */
Point *point_ini(int x, int y, char s);
/* Libera la memoria dinámica reservada para un punto*/
void point_destroy(Point *p);
/* Devuelve la coordenada X de un punto dado, o -1 si se produce algún error */
int point_getCoordinateX(const Point *p);
/* Devuelve la coordenada Y de un punto dado, o -1 si se produce algún error */
int point_getCoordinateY(const Point *p);
/* Devuelve el símbolo de un punto dado, o ERRORCHAR si se produce algún error */
char point_getSymbol(const Point *p);
/* Funciones derivadas que indican el tipo de punto que tenemos */
Bool point_isInput(Point *p); 
Bool point_isOutput(Point *p);
Bool point_isBarrier(Point *p);
Bool point_isVisited(Point *p); 
Bool point_isSpace(Point *p);
/* Modifica la coordenda X de un punto dado, devuelve ERROR si se produce algún error */
Status point_setCoordinateX(Point *p, const int x);
/* Modifica la coordenda Y de un punto dado, devuelve ERROR si se produce algún error */
Status point_setCoordinateY(Point *p, const int y;
/* Modifica el símbolo de un punto dado, devuelve ERROR si se produce algún error */
Status point_setSymbol(Point *p, const char s);
/* Devuelve TRUE si los dos puntos pasados como argumentos son iguales (revisando todos sus campos).
 Devuelve FALSE en otro caso. */
Bool point_equals(const Point *p1, const Point *p2);
/* Copia los datos de un punto a otro devolviendo el punto copiado (incluyendo la reserva de la memoria necesaria)
si todo ha ido bien, o NULL en otro caso */
Point *point_copy(const Point *p);
/* Imprime en un fichero dado los datos de un punto con el siguiente formato: [(x,y): symbol]. Por ejemplo, un punto
con símbolo “*”, con coordenada X 3 e Y 7 se representará como [(3, 7): *]. Además, devolverá el número de
caracteres que se han escrito con éxito (mirar documentación de fprintf) */
int point_print(FILE *f, const Point *p); 


#ifdef __cplusplus
}
#endif

#endif /* POINT_H */
