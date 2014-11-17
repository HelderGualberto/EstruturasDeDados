#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "lista.h"

typedef struct{
    int tam;
    lista** l;
}Hash;

Hash* alocar_hash(int tam);
void inserir_hash(Hash*,int);
void remover_hash(Hash*,int);
void imprimir_hash(Hash*);


#endif // HASH_H_INCLUDED
