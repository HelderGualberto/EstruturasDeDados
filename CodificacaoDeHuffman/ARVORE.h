#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED

typedef struct elemento{
    struct elemento* fesq;
    struct elemento* fdir;
    struct elemento* pai;
    int valor;
    unsigned char letra;
}no;

typedef struct{
    no* raiz;
}arvore;


void arvore_impress(no* a);
arvore* alloc_arvore();
arvore* codificacao(no** heap, int tam);
void huffman(no** folhas,int tam);

#endif // ARVORE_H_INCLUDED
