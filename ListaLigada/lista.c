#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

lista* alocar_lista(){
    lista* l = malloc(sizeof(lista));
    l->comeco = NULL;
    return l;
}

void destruir_lista(lista* l){
    no* temp = l->comeco->prox;

    while(temp != NULL){
        free(l->comeco);
        l->comeco = temp;
        temp = temp->prox;
    }
    free(l->comeco);
    l = NULL;
    free(l);
}

void imprimir_lista(lista* l){
    no* temp = l->comeco;
    while(temp!=NULL){
        printf("%d ",temp->valor);
        temp = temp->prox;
    }
    printf("\n");
}
// Busca o local certo para incercao

void inserir_lista_ordenada(lista*l,int valor){
    if(l->comeco == NULL){
        l->comeco = malloc(sizeof(no));
        l->comeco->prox = NULL;
        l->comeco->valor = valor;
        return;
    }

    no* p;
    no* q;
    p = l->comeco;
    q = l->comeco->prox;

    no* novo = malloc(sizeof(no));
    novo->valor = valor;

    while(q != NULL){
        if(p->valor >= valor){
            novo->prox = p;
            l->comeco = novo;
            return;
        }

        if(q->valor >= valor){
            novo->prox = q;
            p->prox = novo;
            return;
        }
        p = q;
        q = q->prox;
    }
    novo->prox = NULL;
    p->prox = novo;
    return;
}

void inserir_lista(lista* l,int valor){
    if(l->comeco == NULL){
        l->comeco = malloc(sizeof(no));
        l->comeco->prox = NULL;
        l->comeco->valor = valor;
        return;
    }

    no* novo = malloc(sizeof(no));
    novo->valor = valor;
    novo->prox = l->comeco;
    l->comeco = novo;
}

int remover_lista(lista* l,int valor){
    no* temp = l->comeco->prox;
    no* ant = l->comeco;
    int v;
    while(temp != NULL){
        if(temp->valor == valor){
            v = temp->valor;
            break;
        }
        ant = temp;
        temp = temp->prox;
    }
    if(temp == NULL){
        printf("Lista vazia!\n");
        return -1;
    }
    ant->prox = temp->prox;
    free(temp);

    return v;
}
