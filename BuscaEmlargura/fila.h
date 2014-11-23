#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED
#include "grafo.h"

typedef struct element{
    struct element* prox;
    vertice* v;
}no;

typedef struct{
    no* comeco;
    no* fim;
}fila;

void inserir_fila(fila*,vertice*);
vertice* remover_fila(fila*);
fila* alocar_fila();
void imprimir_fila(fila*);
void destruir_fila(fila*);


#endif // FILA_H_INCLUDED
