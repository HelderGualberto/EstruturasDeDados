#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main()
{
    FILE* input;

    input = fopen("d:\\input.txt","r");

    grafo* g = graph_alloc(input);

    graph_impress(g);

    g = graph_dealoc(g);
    graph_impress(g);

    fclose(input);
    return 0;
}
