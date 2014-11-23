#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

struct _arco;
struct _vertice;
struct _grafo;

typedef struct _arco arco;
typedef struct _vertice vertice;
typedef struct _grafo grafo;

struct _arco{
    arco* prox;
    vertice* w;
};

struct _vertice{
    arco* comeco;
    arco* a;
    int visitado,inicio,fim;
    char id;
};

struct _grafo{
    int n,t;
    vertice* vertices;
};

grafo* graph_alloc(FILE*);
void graph_impress(grafo*);
void* graph_dealoc(grafo*);
void bpf(grafo* g,vertice* s);
void bpf_iterativa(grafo*g,vertice*s);


#endif // GRAFO_H_INCLUDED
