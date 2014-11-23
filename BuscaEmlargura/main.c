#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    FILE* input = fopen("d://input.txt","r");

    grafo* g;
    g = graph_alloc(input);
    fclose(input);

    bl(g,&g->vertices[1]);
    vertice* v;

    return 0;
}
