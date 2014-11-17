#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

fila* alocar_fila(){
    fila* f = malloc(sizeof(fila));
    f->comeco = NULL;
    f->fim=NULL;
    return f;
}

void destruir_fila(fila* f){
    while(remover_fila(f) != -1);
    free(f);
}

void imprimir_fila(fila* f){
    no* temp = f->comeco;
    while(temp!= NULL){
        printf("%d ",temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}

void inserir_fila(fila* f,int valor){
    no* novo = malloc(sizeof(no));
    novo->valor = valor;
    novo->prox = NULL;

    if(f->comeco == NULL){
        f->comeco = novo;
        f->fim = novo;
        return;
    }

    f->fim->prox = novo;
    f->fim = novo;

}

int remover_fila(fila* f){

    if(f->comeco == NULL){
        printf("Fila vazia!");
        return -1;
    }

    no* temp = f->comeco;
    int valor = temp->valor;

    f->comeco = f->comeco->prox;
    free(temp);
    return valor;
}
