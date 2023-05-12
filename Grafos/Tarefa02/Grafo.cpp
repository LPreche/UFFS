/*
 * Tarefa 02 - Testes em Circuitos Integrados
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */
#include<list>
#include<vector>
#include"Grafo.h"




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

bool Grafo::eh_caminho(vector<int> N){
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

bool Grafo::existe_caminho(int V1, int V2,vector<bool>& visitado) {
    
    if (V1 == V2) {
        return true;
    }

    visitado[V1] = true;
    
    for(auto  L : lista_adj_[V1]) {
        int vizinho = L;

        if (!visitado[vizinho])
            if (existe_caminho(vizinho, V2, visitado))
                return true;
    }

    return false;
}

bool Grafo::eh_conexo(){
    for(auto i=1;i < num_vertices_; i++){
        vector<bool> visitado;
        visitado.resize(num_vertices_,false);
        if(!existe_caminho(0,i,visitado))
            return false;
    }      
    return true;
}


bool Grafo::eh_aciclico() {
    
    vector<int> lista_adj_Aux_(num_vertices_, 0);

    for (int i = 0; i < num_vertices_; i++) {
        for (int L : lista_adj_[i]) {
            lista_adj_Aux_[L]++;
        }
    }

    for (int i = 0; i < num_vertices_; i++) {
        int j;
        for (j = 0; j < num_vertices_; j++) 
            if (lista_adj_Aux_[j] == 0) 
                break;
            
        if(j == num_vertices_)  
            return false;
        
        lista_adj_Aux_[j] = -1; 

        for (int vizinho : lista_adj_[j]) 
            lista_adj_Aux_[vizinho]--;
        
    }

    return true;
}