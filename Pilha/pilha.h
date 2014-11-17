#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct element{
    struct element* prox;
    int valor;
}no;

typedef struct{
    no* topo;
}pilha;

pilha* alocar_pilha();
void destruir_pilha(pilha*);
void inserir_pilha(pilha*,int);
int remover_pilha(pilha*);
void imprimir_pilha(pilha*);

#endif // PILHA_H_INCLUDED
