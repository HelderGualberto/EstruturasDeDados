#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

pilha* alocar_pilha(){
    pilha* p = malloc(sizeof(pilha));
    p->topo = NULL;
    return p;
}

void imprimir_pilha(pilha* p){
    no* temp = p->topo;

    while(temp!=NULL){
        printf("%c ",temp->v->id);
        temp = temp->prox;
    }
    printf("\n");
}

void inserir_pilha(pilha* p,vertice* v){
    no* novo = malloc(sizeof(no));
    novo->v = v;

    if(p->topo == NULL){
        p->topo = novo;
        p->topo->prox = NULL;
        return;
    }

    novo->prox = p->topo;
    p->topo = novo;
    return;
}

vertice* remover_pilha(pilha* p){
    if(p->topo == NULL){
        printf("Pilha vazia");
        return NULL;
    }
    no* temp = p->topo;
    p->topo = p->topo->prox;
    vertice* v = temp->v;
    free(temp);
    return v;
}

void destruir_pilha(pilha* p){
    while(remover_pilha(p) != NULL);
    free(p);
}

vertice* checa_topo(pilha* p){
    return p->topo->v;
}


