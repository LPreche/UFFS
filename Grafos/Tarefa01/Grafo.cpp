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
#include<list>
#include<vector>

using namespace std;


Grafo::Grafo(int n_vertices){
    num_vertices_ = n_vertices;
    num_arestas_ = 0;
    lista_adj_.resize(n_vertices);
};


int Grafo::num_arestas(){
    return num_arestas_;
}


int Grafo::grau_minimo(){
    int min = num_arestas_;
    for(auto i = 0;i < num_vertices_;i++){
        if(lista_adj_[i].size() < min){
            min = lista_adj_[i].size();
        }
    }   
    return min;
}

int Grafo::grau_maximo(){
    int max = 0;
    for(auto i=0;i<num_vertices_;i++){
        if(lista_adj_[i].size() > max){
            max = lista_adj_[i].size();
        }
    }
    return max;
}


void Grafo::insere_aresta(Aresta e){
    
    if(!verificaAresta(e) && (e.v1 != e.v2)){
        lista_adj_[e.v1].push_front(e.v2);
        lista_adj_[e.v2].push_front(e.v1);
        num_arestas_++;
    }
}


void Grafo::remove_aresta(Aresta e){
    if(verificaAresta(e)){
        lista_adj_[e.v1].remove(e.v2);
        lista_adj_[e.v2].remove(e.v1);
        num_arestas_--;
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