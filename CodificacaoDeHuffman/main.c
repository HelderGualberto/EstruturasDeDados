#include <stdio.h>
#include <stdlib.h>
#include "HEAP.h"
#include "ARVORE.h"


int* frequencia(){

    FILE* input = fopen("D:\\texto.txt","r");
    int *v,erro,i;

    v = malloc(sizeof(int)*256);

    for(i = 0;i < 256; i++){
        v[i] = 0;
    }
    while(1){
        erro = getc(input);
        if(erro == EOF)
            break;
        else
            v[erro]++;
    }
    fclose(input);
    return v;
}


int main()
{
    int i,tam,*v;
    arvore* a = alloc_arvore();
    v = frequencia();
    no** folhas;
    for(i = 0; i < 256; i++){
        if(v[i] != 0)
            tam++;
    }

    no** heap = heap_alloc(tam);
    tam = 0;

    for(i = 0; i < 256; i++){
        if(v[i] != 0){
            heap_insert(v[i],heap,tam,(unsigned char)i);
            tam++;
        }
    }
    folhas = heap_clone(heap,tam);

    a = codificacao(heap,tam);

    huffman(folhas,tam);
    //arvore_impress(a->raiz);

    return 0;
}
