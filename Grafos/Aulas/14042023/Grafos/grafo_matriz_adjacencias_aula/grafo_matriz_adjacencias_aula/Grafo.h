#include "Aresta.h"
#include <vector>
#include <list>
class Grafo {
public:
    Grafo(int num_vertices);
    int num_vertices();
    int num_arestas();
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    void imprime();
    int grauVertice(int v);
    bool temAresta(int v);
private:
    int num_vertices_;
    int num_arestas_;
    //std::vector<std::vector<int>> matriz_adj_;
    std::vector<std::list<int>> lista_adj_;
};