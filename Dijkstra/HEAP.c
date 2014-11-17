#include <stdio.h>
#include <stdlib.h>
#include "HEAP.h"
#include <limits.h>

int pai(int i){
    return (i-1)/2;
}
int fesq(int i){
    return (i*2)+1;
}
int fdir(int i){
    return (i*2)+2;
}

void change(int i,int j,heap* h){
    vertice* temp;
    temp = h->vertices[i];
    h->vertices[i] = h->vertices[j];
    h->vertices[j] = temp;

    h->vertices[i]->indice = i;
    h->vertices[j]->indice = j;
}

void build(int i,heap* h){
    int maior,filho;
    while(1){
        maior = h->vertices[i]->dist;

        if(fesq(i) < h->elementos && h->vertices[fesq(i)]->dist < maior){
            maior = h->vertices[fesq(i)]->dist;
            filho = fesq(i);
        }
        if(fdir(i) < h->elementos && h->vertices[fdir(i)]->dist < maior){
            maior = h->vertices[fdir(i)]->dist;
            filho = fdir(i);
        }
        if(maior == h->vertices[i]->dist)
            break;
        else{
            change(i,filho,h);
            i = filho;
        }
    }
}

void inverse_build(heap* h,int i){
    while(pai(i) >= 0){
        if(h->vertices[pai(i)]->dist > h->vertices[i]->dist){
            change(i,pai(i),h);
            i = pai(i);
        }
        else
            break;
    }
}

void reprioriza(vertice* v,heap* h,int newDist){

    v->dist = newDist;

    inverse_build(h,v->indice);
}

void heap_insert(vertice *v,heap* h){

    h->vertices[h->elementos] = v;
    h->vertices[h->elementos]->dist = INT_MAX;
    h->vertices[h->elementos]->indice = h->elementos;

    inverse_build(h,h->elementos);
    h->elementos++;
}

vertice* heap_remove(heap* h){
    if(h->elementos == 0)
        return NULL;
    vertice* temp = h->vertices[0];
    change(0,h->elementos-1,h);
    h->elementos--;

    build(0,h);
    return temp;
}

 heap* heap_alloc(int _size){
    heap *v = malloc(sizeof(heap));
    v->vertices = malloc(sizeof(vertice*)*_size);
    v->elementos = 0;
    return v;
 }

/*
void heap_dealoc(no** heap,int tam){
    int i;
    for(i = 0;i < tam; i++){
        free(heap[i]);
    }
}
*/

void heap_impress(heap *h){
    int i;
    for(i = 0;i < h->elementos;i++){
        printf("%d ",h->vertices[i]->dist);
    }
    printf("\n");
}

