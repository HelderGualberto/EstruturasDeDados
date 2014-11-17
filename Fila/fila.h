#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct element{
    struct element* prox;
    int valor;
}no;

typedef struct{
    no* comeco;
    no* fim;
}fila;

void inserir_fila(fila*,int);
int remover_fila(fila*);
fila* alocar_fila();
void imprimir_fila(fila*);
void destruir_fila(fila*);


#endif // FILA_H_INCLUDED
