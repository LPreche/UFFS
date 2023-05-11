/*
 * Tarefa 02 - Testes em Circuitos Integrados
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */

#include"Grafo.h"
#include"Aresta.h"
#include<list>
#include<vector>


using namespace std;

Grafo::Grafo(int n_vertices){
    num_vertices_ = n_vertices;
    num_arestas_ = 0;
    lista_adj_.resize(n_vertices);
}

void Grafo::insere_aresta(Aresta e){
    
    if(!verificaAresta(e) && (e.v1 != e.v2)){
        lista_adj_[e.v1].push_back(e.v2);
        lista_adj_[e.v2].push_back(e.v1);
        num_arestas_++;
    }

}

bool Grafo::verificaAresta(Aresta e){
    for(auto L : lista_adj_[e.v1]){
        if(L == e.v2){
            return true;
        }
    }
    return false;
}

void Grafo::imprime(){
    for(auto i=0;i<num_vertices_;i++){
        cout<<i<<": ";
        for(auto L: lista_adj_[i]){
            cout<< L << " ";
        }
        cout <<"\n";
    }
}

bool Grafo::eh_caminho(vector<int> N){
    for(auto i=0;i < N.size()-1;i++)
        if(!verificaAresta(Aresta(N[i],N[i+1])))
            return false;
    return true;
}

bool Grafo::eh_conexo(){
    for(auto i=0;i<num_vertices_;i++){
        if(lista_adj_[i].size() < num_vertices_);
    }
}