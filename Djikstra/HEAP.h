#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include "grafo.h"

typedef struct {
    vertice** v;
    int n;
}heap;

heap* heap_alloc(int);
void heap_insert(vertice*v,heap* h,int dist);
vertice* heap_remove(heap*);
void heap_impress(heap*);
void heap_dealoc(heap*);
void reprioriza(heap* h,vertice*v,int dist);
#endif // HEAP_H_INCLUDED
