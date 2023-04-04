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
        cout<<"Digite o numero de vertices: ";
        cin>>V;
        cout << endl;
    }while(V<=0);

    do{
        cout<<"Digite o numero de Operacoes: ";
        cin>>O;
        cout << endl;
    }while(O<=0);

    Grafo g(V);
    for(auto i=0;i<O;i++){
       
        cout<<"Informe a operacao: ";
        cin>>op;
        cout<< endl;
        switch(op){
            case 'I':{ 
                
                cout << "Inserir Aresta" << endl;
                cout << "Digite as cordenadas para inserir uma aresta X e Y: ";
                cin >> X >> Y;
                cout << endl;
                Aresta e(X,Y);
                g.insere_aresta(e);
            }
            break;

            case 'R':
                cout << "Remover Aresta" << endl;
                cout << "Digite as cordenadas para remover uma aresta X e Y: ";
                cin >> X >> Y;
                cout << endl;
            break;

            case 'E':
                cout << "Obter numero de arestas" << endl;
            break;

            case 'X':
                cout << "Calcular Grau maximo" << endl;
            break;

            case 'N':
                cout << "Calcular Grau Minimo "<< endl;
            break;

            case 'P':
                cout << "Imprimir Grafo" << endl;
            break;
            
            default:
                cout << "opcao invalida" << endl;
        }
    }
    return 0;
}
