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


int Grafo::grau_maximo(){
    return (num_vertices_*(num_vertices_-1))/2;
}


void Grafo::insere_aresta(Aresta e){
    if(e.v1 >= 0 && e.v2 >= 0){
        if(e.v1 < num_vertices_ && e.v2 < num_vertices_){
            if(!verificaAresta(e)){
                lista_adj_[e.v1].push_front(e.v2);
                lista_adj_[e.v2].push_front(e.v1);
            }else{
                cout << "Aresta já existe!" << "\n" << endl;
            }
        }else{
            cout << "Aresta com Valor Superior ao numero de vertices!" << "\n" << endl;
        }
    }else{
        cout << "Aresta com posição negativa!" << "\n" << endl;
    }
}


bool Grafo::verificaAresta(Aresta e){
    for(auto L : lista_adj_[e.v1]){
        if(e.v2 == L){
            return true;
        }else{
            return false;
        }
    }
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