#include <stdio.h>
#include <stdlib.h>
#include "ARVORE.h"
#include "HEAP.h"

arvore* codificacao(no** heap, int tam)
{
    no* folha1;
    no* folha2;
    arvore *a = alloc_arvore();

    while(tam > 1){
        folha1 = heap_remove(tam,heap);tam--;
        folha2 = heap_remove(tam,heap);tam--;

        heap_insert_node(tam,heap,folha1,folha2);tam++;
    }
    a->raiz = heap_remove(tam,heap);tam--;
    return a;
}

void arvore_impress(no* raiz){
    if(raiz == NULL)
        return;


    arvore_impress(raiz->fesq);

    printf("%c - %d\n",raiz->letra,raiz->valor);

    arvore_impress(raiz->fdir);
}

void huffman(no** folhas,int tam){
    int i;
    no* temp;
    for(i=0;i<tam;i++){
        temp = folhas[i];
        printf("%c - ",folhas[i]->letra);
        while(temp->pai != NULL){
            if(temp == temp->pai->fesq)
                printf("1");
            else
                printf("0");
            temp = temp->pai;
        }
        printf("\n");
    }
}

arvore* alloc_arvore(){
    arvore* a = malloc(sizeof(arvore));
    a->raiz = NULL;
    return a;
}
