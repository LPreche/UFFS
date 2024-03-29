/*
 * Tarefa 03 - Viacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */
#include <list>
#include <utility>
#include <limits>
#include "Digrafo.h"
#include "Filapri_min.h"

using namespace std;

bool Digrafo::verificaAresta(Aresta e) {
    for (auto L : lista_adj_[e.v1]) {
        if (L.first == e.v2) {
            return true;
        }
    }
    return false;
}

Digrafo::Digrafo(int n_vertices) {
    num_vertices_ = n_vertices;
    num_arestas_ = 0;
    lista_adj_.resize(n_vertices);
}

void Digrafo::insere_aresta(Aresta e) {
    if (!verificaAresta(e) && (e.v1 != e.v2)) {
        pair<int, int> par;
        par.first = e.v2;
        par.second = e.peso;
        lista_adj_[e.v1].push_back(par);
        num_arestas_++;
    }
}

void Digrafo::imprimeDigrafo() {
    for (auto i = 0; i < num_vertices_; i++) {
        cout << i << ": ";
        for (auto L : lista_adj_[i]) {
            cout << L.first << " ";
        }
        cout << "\n";
    }
}

void Digrafo::dijkstra(int cidade_origem, int extensao_min) {
    
    int infinito = numeric_limits<int>::max();
    vector<int> dp(num_vertices_, infinito);
    vector<int> pai(num_vertices_,-1);

    if(!lista_adj_[cidade_origem].empty()){
        Filapri_min<int> fp(num_vertices_);
        dp[cidade_origem] = 0;
        fp.insere(cidade_origem, 0);
        for (auto i = 0; i < num_vertices_; i++) 
            if (i != cidade_origem)
                fp.insere(i, infinito);
        

        while (!fp.vazia()) {
            pair<int, int> removido = fp.remove();
            if (dp[removido.first] != infinito) {
                vector<int> vizinhos;
                for (auto i = 0; i < num_vertices_; i++) {
                    if (verificaAresta(Aresta(removido.first, i, 0))) {
                        vizinhos.push_back(i);
                    }
                }

                for (auto V : vizinhos) {
                    pair<int, int> U;
                    for (auto L : lista_adj_[removido.first]) {
                        if (L.first == V) {
                            U = L;
                            break; 
                        }
                    }

                    if (dp[V] > (dp[removido.first] + U.second)) {
                        dp[V] = dp[removido.first] + U.second;
                        fp.diminui_prio(V, dp[V]);
                        pai[V] = removido.first;
                    }
                }
            }
        }
    }

    for(auto i=0;i<dp.size();i++){
        if(i != cidade_origem){
            cout << i <<": ";
            if(dp[i] < extensao_min || dp[i] == infinito){
                cout << "economicamente inviavel partindo de "<< cidade_origem;
            }else{
                cout << dp[i] << ", ";
                int j=i;
                while(j != -1){
                    cout << j << " ";
                    j=pai[j];
                }
            }
            cout << endl;
        }
    }
    
}
