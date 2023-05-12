/*
 * Tarefa 02 - Testes em Circuitos Integrados
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */

#include<iostream>
#include<locale>
#include"Grafo.h"
#include"Aresta.h"

using namespace std;

int main() {
    int O,V,E,e1,e2;
    char c;
        
        do{
            cin >> V >> E;
        }while(V<1 && E<0);
        Grafo g(V);
        
        for(auto i=0;i<E;i++){
            cin >> e1 >> e2; 
            g.insere_aresta(Aresta(e1,e2));
        }
        cin >> O;

        for(auto i=0;i<O;i++){
            cin >> c;

            switch(c){
                case 'S':{
                    int n;
                    cin >> n;
                    vector<int> N;
                    N.resize(n);

                    for(auto i=0;i<N.size();i++)
                        cin >> N[i];

                    if(g.eh_caminho(N))
                        cout << "SIM" << endl;
                    else
                        cout << "NAO" << endl;
                    
                }
                break;

                case 'C':{
                    int v1,v2;
                    vector<bool> visitado;
                    visitado.resize(V,false);

                    do{
                        cin >> v1 >> v2;
                    }while(v1 < 0 || v2 < 0);
                    
                    if(g.existe_caminho(v1,v2,visitado))
                        cout << "SIM" << endl;
                    else
                        cout << "NAO" << endl;
                }
                break;
                
                case 'X':{
                    
                    if(g.eh_conexo())
                        cout << "SIM" << endl;
                    else
                        cout << "NAO" << endl;
                        
                }
                break;
                
                case 'A':{
                    if(g.eh_aciclico())
                        cout << "SIM" << endl;
                    else
                        cout << "NAO" << endl;
                }
                break;
                
                default:
                    cout << endl;
            }
        }
        


    return 0;
}
