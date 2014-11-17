#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

typedef struct element{
    struct element *prox;
    int valor;
}no;

typedef struct{
    no* comeco;
}lista;

void inserir_lista(lista*,int valor);
int remover_lista(lista*, int valor);
void destruir_lista(lista*);
lista* alocar_lista();
void imprimir_lista(lista*);
void inserir_lista_ordenada(lista*,int);


#endif // LISTA_H_INCLUDED
