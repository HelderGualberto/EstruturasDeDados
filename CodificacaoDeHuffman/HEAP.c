 #include <stdio.h>
 #include <stdlib.h>
 #include "ARVORE.h"

int pai(int i){
    return (i-1)/2;
}
int fesq(int i){
    return (i*2)+1;
}
int fdir(int i){
    return (i*2)+2;
}

void change(int i,int j,no** heap){
    no* temp;
    temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}
void build(int i,no** heap,int tam){
    int maior,filho;
    while(1){
        maior = heap[i]->valor;

        if(fesq(i) < tam && heap[fesq(i)]->valor < maior){
            maior = heap[fesq(i)]->valor;
            filho = fesq(i);
        }
        if(fdir(i) < tam && heap[fdir(i)]->valor < maior){
            maior = heap[fdir(i)]->valor;
            filho = fdir(i);
        }
        if(maior == heap[i]->valor)
            break;
        else{
            change(i,filho,heap);
            i = filho;
        }
    }
}

void inverse_build(no** heap,int i){
    while(pai(i) >= 0){
        if(heap[pai(i)]->valor > heap[i]->valor){
            change(i,pai(i),heap);
            i = pai(i);
        }
        else
            break;
    }
}

void heap_insert(int valor,no** heap,int i,unsigned char letra){
    heap[i] = malloc(sizeof(no));
    heap[i]->fesq = NULL;
    heap[i]->fdir = NULL;
    heap[i]->pai = NULL;
    heap[i]->valor = valor;
    heap[i]->letra = letra;

    inverse_build(heap,i);
}

void heap_insert_node(int i,no** heap,no* folha1,no* folha2){
    heap[i] = malloc(sizeof(no));
    heap[i]->fesq = folha2;
    heap[i]->fdir = folha1;
    heap[i]->pai = NULL;
    heap[i]->valor = folha1->valor+folha2->valor;
    folha1->pai = heap[i];
    folha2->pai = heap[i];

    inverse_build(heap,i);
}

no* heap_remove(int tam,no** heap){
    if(tam == 0)
        return NULL;
    no* temp = heap[0];
    change(0,tam-1,heap);
    tam--;

    build(0,heap,tam);
    return temp;
}

void heap_dealoc(no** heap,int tam){
    int i;
    for(i = 0;i < tam; i++){
        free(heap[i]);
    }
}

 no** heap_alloc(int _size){
    no** v = malloc(sizeof(no*)*_size);
    return v;
 }

no** heap_clone(no** heap,int tam){
    no** folhas = malloc(sizeof(no*)*tam);
    int i;
    for(i=0;i<tam;i++){
        folhas[i] = heap[i];
    }
    return folhas;
}

void heap_impress(no** heap,int tam){
    int i;
    for(i = 0;i < tam;i++){
        printf("%d ",heap[i]->valor);
    }
    printf("\n");
}
