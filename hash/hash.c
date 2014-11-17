#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "hash.h"

Hash* alocar_hash(int tam){
    int i;
    Hash* h = malloc(sizeof(Hash));
    h->tam = tam;

    h->l = malloc(sizeof(lista*)*tam);

    for(i=0;i<tam;i++){
        h->l[i] = alocar_lista();
    }
    return h;
}

void inserir_hash(Hash* h,int i){
    inserir_lista(h->l[i%h->tam],i);
}
void remover_hash(Hash *h,int i){
    remover_lista(h->l[i%h->tam],i);
}
void imprimir_hash(Hash* h){
    int i;
    for(i=0;i<h->tam;i++){
        printf("%d: ",i);
        imprimir_lista(h->l[i]);
        printf("\n");
    }
}

