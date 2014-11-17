#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#include "ARVORE.h"
no** heap_alloc(int);

void heap_insert(int valor,no**,int index,unsigned char letter);
void heap_insert_node(int i,no** heap,no* folha1,no* folha2);
no* heap_remove(int tam,no**);
void heap_impress(no**,int tam);
void heap_dealoc(no**,int tam);
no** heap_clone(no** heap,int tam);

#endif // HEAP_H_INCLUDED
