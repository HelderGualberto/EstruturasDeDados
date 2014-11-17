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
        printf("%d ",temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

void inserir_pilha(pilha* p,int valor){
    no* novo = malloc(sizeof(no));
    novo->valor = valor;

    if(p->topo == NULL){
        p->topo = novo;
        p->topo->prox = NULL;
        return;
    }

    novo->prox = p->topo;
    p->topo = novo;
    return;
}

int remover_pilha(pilha* p){
    if(p->topo == NULL){
        printf("Pilha vazia");
        return -1;
    }
    no* temp = p->topo;
    p->topo = p->topo->prox;
    int valor = temp->valor;
    free(temp);
    return valor;
}

void destruir_pilha(pilha* p){
    while(remover_pilha(p) != -1);
    free(p);
}


