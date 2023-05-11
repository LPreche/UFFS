/*
 * Tarefa 02 - Testes em Circuitos Integrados
 *
 * GEN254 - Grafos - 2023/1
 *
 * Nome:      Luiz Paulo Reche
 * Matricula: 2021101059
 */

#include"Grafo.cpp"
#include"Aresta.cpp"
#include<iostream>
#include<locale>

using namespace std;

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int O,V,E,e1,e2;
    char c;
        cout << "Digite o numero de vertices: ";
        do{
            cin >> V;
        }while(V<1);
        Grafo g(V);
        cout << endl;
        cout << "Digite o numero de Arestas: ";
        do{
            cin >> E;
        }while(E<0);
        cout << endl;
        for(auto i=0;i<E;i++){
            cout << "Digite dois vertices para inserir uma aresta: ";
            cin >> e1 >> e2; 
            g.insere_aresta(Aresta(e1,e2));
        }
        cout << "Digite o numero de operacoes: ";
        cin >> O;
        cout << endl;

        for(auto i=0;i<O;i++){
            cout << "Digite sua opcao: ";
            cin >> c;
            cout << endl;

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
