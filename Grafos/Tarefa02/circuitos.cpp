/*
 * Tarefa 02 - Testes em Circuitos Integrados
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */
#include<iostream>
#include"Grafo.cpp"
#include"Aresta.cpp"

using namespace std;

int main() {

    int O,V,E,e1,e2;
    char c;
        do{
            cin >> V;
        }while(V<1);
        Grafo g(V);

        do{
            cin >> E;
        }while(E<0);

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
                    vector<int> N;
                    N.resize(n);
                    for(int V : N)
                        cin >> V;
                    
                    for(int V : N)
                        cout << V << " ";
                    
                    cout << endl;

                }
                break;
                
                case 'C':
                
                break;
                
                case 'X':
                
                break;
                
                case 'A':
                
                break;
                
                default:
                    cout << endl;
            }
        }
        g.imprime();


    return 0;
}
