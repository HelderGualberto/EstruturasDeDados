 #include <stdio.h>
 #include <stdlib.h>
 #include "HEAP.h"

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
    temp = h->v[i];
    h->v[i] = h->v[j];
    h->v[j] = temp;

    h->v[i]->indice = i;
    h->v[j]->indice = j;

}

void build(heap* h){
    int menor,filho;
    int i = 0;

    while(1){
        menor = h->v[i]->dist;

        if(fesq(i) < h->n && h->v[fesq(i)]->dist < menor){
            menor = h->v[fesq(i)]->dist;
            filho = fesq(i);
        }
        if(fdir(i) < h->n && h->v[fdir(i)]->dist < menor){
            menor = h->v[fdir(i)]->dist;
            filho = fdir(i);
        }
        if(menor == h->v[i]->dist)
            break;
        else{
            change(i,filho,h);
            i = filho;
        }
    }
}

void inverse_build(heap* h,int i){
    while(pai(i) >= 0){
        if(h->v[pai(i)]->dist > h->v[i]->dist){
            change(i,pai(i),h);
            i = pai(i);
        }
        else
            break;
    }
}

void reprioriza(heap* h,vertice*v,int dist){
    v->dist = dist;
    inverse_build(h,v->indice);
}

void heap_insert(vertice* v,heap* h,int dist){
    h->v[h->n] = v;
    h->v[h->n]->indice = h->n;
    (h->n)++;
    reprioriza(h,v,dist);
}

vertice* heap_remove(heap* h){
    if(h->n == 0)
        return NULL;
    vertice* temp = h->v[0];
    change(0,h->n-1,h);
    (h->n)--;

    build(h);
    return temp;
}

void heap_dealoc(heap *h){
    int i;
    for(i = 0;i < h->n; i++){
        free(h->v[i]);
    }
    free(h);
}

 heap* heap_alloc(int _size){
    heap* h = malloc(sizeof(heap));
    h->n = 0;
    h->v = malloc(sizeof(vertice*)*_size);
    return h;
 }

void heap_impress(heap* h){
    int i;
    for(i = 0;i < h->n;i++){
        printf("%d ",h->v[i]->dist);
    }
    printf("\n");
}
