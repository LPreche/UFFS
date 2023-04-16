/*
 * Tarefa 01 - Grafo - Listas de Adjacencia
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche  
 * Matricula: 2021101059
 */
#include <iostream>
#include "Grafo.h"
#include "Aresta.h"

using namespace std;
int main() {

    int V,O,X=0,Y=0;
    char op;

    do{
        cin>>V;
    }while(V<=0);

    do{
        cin>>O;
    }while(O<=0);

    Grafo g(V);
    for(auto i=0;i<O;i++){
        cin>>op;
        switch(op){
            case 'I':{ 
                do{    
                    cin >> X >> Y;
                }while((X<0 || Y<0) || (X>V || Y>V));

                Aresta e(X,Y);
                g.insere_aresta(e);
            }
            break;

            case 'R':{
                do{
                    cin >> X >> Y;
                }while((X<0 || Y<0) || (X>V || Y>V));
                
                Aresta e(X,Y);
                g.remove_aresta(e);
            }
            break;

            case 'E':
                cout << g.num_arestas() << endl;
            break;

            case 'X':
                cout << g.grau_maximo() << endl;
            break;

            case 'N':
                cout << g.grau_minimo() << endl;
            break;

            case 'P':
                g.imprime();
            break;
            
            default:
                cout << "" << endl;
        }
        
    }
    
    return 0;
}
