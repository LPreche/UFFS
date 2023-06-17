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
        bool verificaAresta(Aresta e);
        Digrafo(int num_vertices);
        void insere_aresta(Aresta e);
        void imprimeDigrafo();
        void dijkstra(int cidade_origem,int extensao_min);
    private:
        int num_vertices_;
        int num_arestas_;
        vector<list<pair<int,int>>> lista_adj_;
};

#endif /* DIGRAFO_H */
