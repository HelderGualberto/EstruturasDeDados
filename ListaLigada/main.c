#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main()
{
    lista* listinha = alocar_lista();

    inserir_lista_ordenada(listinha,12);
    inserir_lista_ordenada(listinha,31);
    inserir_lista_ordenada(listinha,34);
    inserir_lista_ordenada(listinha,2);
    inserir_lista_ordenada(listinha,65);
    inserir_lista_ordenada(listinha,87);
    inserir_lista_ordenada(listinha,34);
    inserir_lista_ordenada(listinha,98);

    imprimir_lista(listinha);
   // printf("%d removido\n",remover_lista(listinha,372));
    //imprimir_lista(listinha);


    return 0;
}
