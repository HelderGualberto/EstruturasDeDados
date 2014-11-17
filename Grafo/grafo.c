#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void* graph_dealoc(grafo* g){

    if(g == NULL)
        return;

    int i;
    arco* p;
    arco* q;

    for(i=0;i<g->n;i++){
        p = g->vertices[i].comeco;

        if(p == NULL);

        else{
            q = p->prox;
            while(q != NULL){
                free(p);
                p = q;
                q = q->prox;
            }
            free(p);
        }
    }
    free(g->vertices);
    free(g);
    return NULL;
}

grafo* graph_alloc(FILE* input){

    grafo* g = malloc(sizeof(grafo));

    arco* arc;
    int i,m,n,j,k;
    char c;
    fscanf(input,"%d",&n);
    fgetc(input);
    g->vertices = malloc(sizeof(vertice)*n);
    g->n = n;

    for(i=0;i<g->n;i++){
        fscanf(input,"%c",&c);
        g->vertices[i].id = c;
        g->vertices[i].comeco = NULL;
        fgetc(input);
    }
    fscanf(input,"%d",&m);
    fgetc(input);

    for(i=0;i<m;i++){
        fscanf(input,"%d",&j);
        fscanf(input,"%d",&k);
        arc = malloc(sizeof(arco));

        if(g->vertices[j].comeco == NULL)
            arc->prox = NULL;
        else
            arc->prox = g->vertices[j].comeco;

        arc->w = &(g->vertices[k]);
        g->vertices[j].comeco = arc;
    }
    return g;
}

void graph_impress(grafo* g){
    if(g == NULL)
        return;

    int i;
    arco* temp;
    FILE * output;
    output = fopen("d:\\output.txt","w");
    for(i=0;i<g->n;i++){
        temp = g->vertices[i].comeco;
        fprintf(output,"%c: ",g->vertices[i].id);
        printf("%c: ",g->vertices[i].id);

        while(temp != NULL){
            fprintf(output,"%c ",temp->w->id);
            printf("%c ",temp->w->id);
            temp = temp->prox;
        }
        fprintf(output,"\n");
        printf("\n");
    }
}
