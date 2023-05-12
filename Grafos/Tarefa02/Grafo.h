/*
 * Tarefa 02 - Testes em Circuitos Integrados
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */

#ifndef GRAFO_H

#define GRAFO_H
#include<iostream>
#include<list>
#include<vector>
#include "Aresta.h"

using namespace std;

class Grafo {
    public:
        Grafo(int num_vertices);
        void insere_aresta(Aresta e);
        bool verificaAresta(Aresta e);
        bool eh_caminho(vector<int> N);
        bool existe_caminho(int v1, int v2,vector<bool>& visitado);
        bool eh_conexo();
        bool eh_aciclico();
    private:
        int num_vertices_;
        int num_arestas_;
        vector<vector<int>> lista_adj_;
};

#endif /* GRAFO_H */
