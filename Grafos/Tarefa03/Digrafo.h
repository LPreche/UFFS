/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */

#ifndef DIGRAFO_H

#define DIGRAFO_H
#include<iostream>
#include<list>
#include<vector>
#include "Aresta.h"

using namespace std;

class Digrafo {
    public:
        Digrafo(int num_vertices);
        void insere_aresta(Aresta e);
        bool verificaAresta(Aresta e);
        bool eh_caminho(vector<int> N);
        bool existe_caminho(int v1, int v2,vector<bool>& visitado);
    private:
        int num_vertices_;
        int num_arestas_;
        vector<vector<int>> lista_adj_;
};

#endif /* DIGRAFO_H */
