#include "npoint.h"

typedef struct _NPoint { 
    char *name; 
    float *coord; 
    int dim; 
};

NPoint * npoint_ini(int dim) {
}

void npoint_free(NPoint *) {
}

Status npoint_getCoordinate(const NPoint * p, const int dim, float * v) {
}

const char* npoint_getName(const NPoint * p) {
}

int npoint_getDimensions(const NPoint * p) {
}

Status npoint_setCoordinate(NPoint * p, const int dim, const float v) {
}

Status npoint_setName(NPoint *p, const char* name) {
}

NPoint * npoint_copy(const NPoint * src) {
}

int npoint_print(FILE *pf, const NPoint *p) {
}

int npoint_cmp(const NPoint * p1, const NPoint * p2) {
}
