/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche  
 * Matricula: 2021101059
 */
#include "Grafo.h"

Grafo::Grafo(int n_vertices){
    num_vertices_ = n_vertices;
    num_arestas_ = 0;
};

int Grafo::num_arestas(){
    return num_arestas_;
}

int Grafo::grau_maximo(){
    return (num_vertices_*(num_vertices_-1))/2;
}