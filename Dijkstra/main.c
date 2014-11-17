#include <stdio.h>
#include <stdlib.h>
#include "HEAP.h"


int main()
{
    FILE * input = fopen("D:\\text.txt","r");

    grafo* g = graph_alloc(input);

    heap * h = heap_alloc(g->n);
    int i;
    for(i = 0; i< g->n;i++){

        heap_insert(&(g->vertices[i]),h);
        reprioriza(&g->vertices[i],h,i);

    }

    heap_impress(h);
    heap_remove(h);
    heap_impress(h);
    heap_remove(h);
    heap_impress(h);


    return 0;
}
