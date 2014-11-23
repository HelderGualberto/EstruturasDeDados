#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED
#include "grafo.h"

typedef struct element{
    struct element* prox;
    vertice* v;
}no;

typedef struct{
    no* topo;
}pilha;

pilha* alocar_pilha();
void destruir_pilha(pilha*);
void inserir_pilha(pilha*,vertice*);
vertice* remover_pilha(pilha*);
void imprimir_pilha(pilha*);
vertice* checa_topo(pilha*);
#endif // PILHA_H_INCLUDED
