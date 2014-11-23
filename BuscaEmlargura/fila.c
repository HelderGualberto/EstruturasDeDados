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
    while(remover_fila(f) != NULL);
    free(f);
}

void imprimir_fila(fila* f){
    no* temp = f->comeco;
    while(temp!= NULL){
        printf("%c ",temp->v->id);
        temp = temp->prox;
    }
    printf("\n");
}

void inserir_fila(fila* f,vertice* v){
    no* novo = malloc(sizeof(no));
    novo->v = v;
    novo->prox = NULL;

    if(f->comeco == NULL){
        f->comeco = novo;
        f->fim = novo;
        return;
    }

    f->fim->prox = novo;
    f->fim = novo;

}

vertice* remover_fila(fila* f){

    if(f->comeco == NULL){
        printf("Fila vazia!");
        return NULL;
    }

    no* temp = f->comeco;
    vertice* v = temp->v;

    f->comeco = f->comeco->prox;
    free(temp);
    return v;
}
