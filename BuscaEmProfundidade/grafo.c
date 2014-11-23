#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"
#include "pilha.h"

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
    g->t = 0;

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

void pf(grafo* g,vertice* s){
    arco* a;
    (g->t)++;
    s->inicio = g->t;

    for(a = s->comeco;a != NULL;a = a->prox){
        if(a->w->visitado == 0){
            s->visitado = 1;
            pf(g,a->w);
        }
    }
    (g->t)++;
    s->fim = g->t;
    printf("%c: %d-%d\n",s->id,s->inicio,s->fim);
}

void bpf(grafo* g,vertice* s){

    vertice*v;
    for(v = g->vertices;v < g->vertices+g->n;v++)
        v->visitado = 0;
    s->visitado = 1;
    g->t = 0;

    pf(g,s);
}

void bpf_iterativa(grafo*g,vertice*s){
    vertice *v;
    pilha* p;
    p = alocar_pilha();
    g->t = 0;

    for(v = g->vertices;v < g->vertices+g->n;v++)
        v->visitado = 0;

    s->a = s->comeco;
    inserir_pilha(p,s);

    while(p->topo != NULL){
        vertice* topo = checa_topo(p);

        if(topo->a == topo->comeco){
            (g->t)++;
            topo->inicio = g->t;
        }

        if(topo->a == NULL){
            (g->t)++;
            topo->fim = g->t;
            remover_pilha(p);
            printf("%c: %d/%d\n", topo->id, topo->inicio, topo->fim);
        }
        else{
            vertice* w;
            w = topo->a->w;

            if(w->visitado == 0){
                w->a = w->comeco;
                w->visitado = 1;
                inserir_pilha(p,w);
            }
            topo->a = topo->a->prox;

        }
    }
}
