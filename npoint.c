#include "npoint.h"

typedef struct _NPoint { 
    char *name; 
    float *coord; 
    int dim; 
};

NPoint * npoint_ini(int dim) {
    NPoint *np = NULL;
    
    np = (NPoint *) malloc(siceof(NPoint));
    if(!np) return NULL;
    
    np->dim = dim;
    return np;
}

void npoint_free(NPoint *) {
}

Float npoint_getCoordinate(const NPoint * p) {
    if(!p) return NULL;
    
    return p->coord;
}

const char* npoint_getName(const NPoint * p) {
    if(!p) return NULL;
    
    return p->name;
}

int npoint_getDimensions(const NPoint * p) {
    if(!p) return NULL;
    
    return p->dim;
}

Status npoint_setCoordinate(NPoint * p, const int dim, const float v) {
    if(!p) return ERROR;
    else {
        p->dim = dim;
        p->coord = v;
        return OK;
    }
}

Status npoint_setName(NPoint *p, const char* name) {
    if(!p) return ERROR;
    else {
        ctrcpy(p->name, name);
        return OK;
    }
}

NPoint * npoint_copy(const NPoint * src) {
    Npoint *p = npoint_ini(scr->dim);
    if(!p) return NULL;
    p->coord = scr->coord;
    ctrcpy(p->name, scr->name);
    return p;
}

int npoint_print(FILE *pf, const NPoint *p) {
}

int npoint_cmp(const NPoint * p1, const NPoint * p2) {
}
