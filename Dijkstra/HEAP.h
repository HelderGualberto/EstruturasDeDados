#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include "grafo.h"

typedef struct {
    vertice **vertices;
    int elementos;
}heap;

heap* heap_alloc(int);
void heap_insert(vertice *,heap*);
vertice* heap_remove(heap*);
void reprioriza(vertice* v,heap* h,int newDist);
void heap_impress(heap*);
//void heap_dealoc(no**,int tam);

#endif // HEAP_H_INCLUDED
