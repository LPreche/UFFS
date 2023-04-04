/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche  
 * Matricula: 2021101059
 */
#include "Grafo.h"
#include<algorithm>
using namespace std;

Grafo::Grafo(int n_vertices){
    num_vertices_ = n_vertices;
    num_arestas_ = 0;
    
    for(auto L : lista_adj_){
        list<int> inicialList;
        for(auto i=0; i<num_vertices_;i++){
            inicialList.push_front(0);
        }
        L.push_front(inicialList);
    }
};

int Grafo::num_arestas(){
    return num_arestas_;
}

int Grafo::grau_maximo(){
    return (num_vertices_*(num_vertices_-1))/2;
}

void Grafo::insere_aresta(Aresta e){
 

}
