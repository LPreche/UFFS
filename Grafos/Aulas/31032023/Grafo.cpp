#include "Grafo.h"
#include<iostream>

using namespace std;

    Grafo::Grafo(int num_vertices){
        int n_vertices = num_vertices;
        int n_arestas = 0;

        matriz_adj.resize(num_vertices);
        for(auto i = 0; i<num_vertices;i++){
            matriz_adj[i].resize(num_vertices,0);
        }

    }

    int Grafo::num_vertices(){
        return n_vertices;
    }

    void Grafo::insere_arestas(Aresta e){
        if((matriz_adj[e.v1][e.v2] == 0) && (e.v1 != e.v2)){
            matriz_adj[e.v1][e.v2]=1;
            matriz_adj[e.v2][e.v2]=1;
            n_arestas++;
        }
    }

    void Grafo::remover_arestas(Aresta e){
        if(matriz_adj[e.v1][e.v2] == 0){
            matriz_adj[e.v1][e.v2]=0;
            matriz_adj[e.v2][e.v2]=0;
            n_arestas--;
        }
    }

    void Grafo::imprime(){
        for(auto i = 0; i< n_vertices;i++){
            cout << i << ":";
            for(auto j = 0; j<n_vertices;j++){
                if(matriz_adj[i][j] == 1){
                    cout << " " << j;
                }
            }
            cout << "\n";
        }
    }
    