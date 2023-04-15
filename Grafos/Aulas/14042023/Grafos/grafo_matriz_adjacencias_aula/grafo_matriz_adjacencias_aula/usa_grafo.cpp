#include "Grafo.h"
#include<iostream>
#include<strings.h>
using namespace std;

int main() {
    Grafo g(10);
    g.insere_aresta(Aresta(1,3));
    g.insere_aresta(Aresta(2,1));
    g.insere_aresta(Aresta(4,1));
    g.insere_aresta(Aresta(6,1));
    g.imprime();
    
    /* v = 6;
    cout << "Grau do vertice " << v << ": " << g.grauVertice(v) << "\n";
    Aresta a(4,1);
    
   if(g.temAresta(a)){
        cout << "Tem a Aresta: " << a.v1 << " " << a.v2 << "\n";
    }else{
        cout << "Não a Tem Aresta: " << a.v1 << " " << a.v2 <<"\n";
    }*/
    
    return 0;
}