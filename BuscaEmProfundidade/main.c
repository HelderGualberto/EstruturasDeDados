#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{

    grafo* g;
    FILE* input = fopen("D:\\input.txt","r");

    g = graph_alloc(input);

    fclose(input);
    //graph_impress(g);
    bpf_iterativa(g,&g->vertices[0]);

    return 0;
}
