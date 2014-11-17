#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

struct _arco;
struct _vertice;
struct _grafo;

typedef struct _arco arco;
typedef struct _vertice vertice;
typedef struct _grafo grafo;

struct _arco{
    int custo;
    arco* prox;
    vertice* w;
};

struct _vertice{
    arco* comeco;
    char id;
    vertice* pred;
    int dist,indice;
};

struct _grafo{
    int n;
    vertice* vertices;
};

grafo* graph_alloc(FILE*);
void graph_impress(grafo*);
void* graph_dealoc(grafo*);
int bellman_ford(grafo*,vertice*);


#endif // GRAFO_H_INCLUDED
