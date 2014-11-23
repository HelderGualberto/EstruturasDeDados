#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    FILE* input = fopen("d://input.txt","r");
    vertice* v;
    grafo* g;
    g = graph_alloc(input);

    if(bellman_ford(g,&g->vertices[0]))
        printf("GRAFO TEM CIRCUITO NEGATIVO!\n");
    else
        for(v=g->vertices;v < g->vertices+g->n;v++)
            printf("%c: %d\n",v->id,v->dist);

    return 0;
}
