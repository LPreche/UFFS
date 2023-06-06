/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */
#include<list>
#include<vector>
#include"Digrafo.h"




using namespace std;

Digrafo::Digrafo(int n_vertices){
    num_vertices_ = n_vertices;
    num_arestas_ = 0;
    lista_adj_.resize(n_vertices);
}

void Digrafo::insere_aresta(Aresta e){
    
    if(!verificaAresta(e) && (e.v1 != e.v2)){
        lista_adj_[e.v1].push_back(e.v2);
        num_arestas_++;
    }

}

bool Digrafo::verificaAresta(Aresta e){
    for(auto L : lista_adj_[e.v1]){
        if(L == e.v2){
            return true;
        }
    }
    return false;
}

bool Digrafo::eh_caminho(vector<int> N){
    for (auto i = 1; i < N.size(); i++) {
        for (auto j = 0; j < i; j++) {
            if (N[i] == N[j]) {
                return false;
            }
        }
        
        if (!verificaAresta(Aresta(N[i-1], N[i]))) 
            return false;
        
    }
    
    return true;
}

