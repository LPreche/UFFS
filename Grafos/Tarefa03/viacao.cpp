/*
 * Tarefa 03 - Ciacao Grafeira
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */

#include<iostream>
#include<locale>
#include"Digrafo.h"
#include"Aresta.h"

using namespace std;

int main() {
    int M,R,C,T,X,Y,Z,x;
    char c;
        
        do{
            cin >> C >> T; 
        }while(C<1 && T<0);

        Digrafo g(C);
        
        for(auto i=0;i<T;i++){
            cin >> X >> Y >> Z; 
            g.insere_aresta(Aresta(X,Y,Z));
        }
        g.imprimeDigrafo();
        cin >> R;
        for(auto i=0;i<R;i++){
            cin >> x >> M;
            g.dijkstra(x,M);
            cout<<endl;
        } 

        

  

    return 0;
}
