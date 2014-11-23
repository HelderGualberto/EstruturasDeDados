#include <stdio.h>
#include <stdlib.h>
#include "HEAP.h"

int main()
{


   FILE * input = fopen("D:\\input.txt","r");

    grafo* g = graph_alloc(input);

    dijkstra(g,&g->vertices[0]);
    vertice* v;
    for(v = g->vertices;v < g->vertices+g->n;v++)
        printf("%c: %d\n",v->id,v->dist);

     return 0;
}
