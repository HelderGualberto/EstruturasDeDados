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
    int custo;
};

struct _vertice{
    arco* comeco;
    char id;
    vertice* pred;
    int dist,infinito;
};

struct _grafo{
    int n,arcos;
    vertice* vertices;
};

grafo* graph_alloc(FILE*);
void graph_impress(grafo*);
void* graph_dealoc(grafo*);
int bellman_ford(grafo* g, vertice *s);


#endif // GRAFO_H_INCLUDED
