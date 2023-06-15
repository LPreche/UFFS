/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */
#include<list>
#include<utility>
#include"Digrafo.h"




using namespace std;

Digrafo::Digrafo(int n_vertices){
    num_vertices_ = n_vertices;
    num_arestas_ = 0;
    lista_adj_.resize(n_vertices);
}

void Digrafo::insere_aresta(Aresta e){
    
    if(!verificaAresta(e) && (e.v1 != e.v2)){
        pair<int,int> par;
        par.first = e.v2;
        par.second = e.peso;
        lista_adj_[e.v1].push_back(par);
        num_arestas_++;
    }

}

bool Digrafo::verificaAresta(Aresta e){
    for(auto L : lista_adj_[e.v1]){
        if(L.first == e.v2){
            return true;
        }
    }
    return false;
}

void Digrafo::imprimeDigrafo(){
    for(auto i=0;i<num_vertices_;i++){
        cout<<i<<": ";
        for(auto L: lista_adj_[i]){
            cout<< L.first << " ";
        }
        cout <<"\n";
    }
}

