/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */

#ifndef GRAFO_H

#define GRAFO_H
#include<iostream>
#include<vector>
#include<list>
#include "Aresta.h"

using namespace std;

class Grafo {
public:
    Grafo(int num_vertices);
    // ~Grafo(); // Se necessario
    int num_arestas();
    void insere_aresta(Aresta e);
    void remove_aresta(Aresta e);
    int grau_maximo();
    int grau_minimo();
    void imprime();
    bool verificaAresta(Aresta e);
private:
    int num_vertices_;
    int num_arestas_;
    vector<list<int>> lista_adj_;
};

#endif /* GRAFO_H */
