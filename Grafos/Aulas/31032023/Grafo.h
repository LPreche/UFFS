#include "Aresta.h"
#include<vector>


   
    class Grafo{
        public:
            Grafo(int num_vertices);
            int num_vertices();
            int num_arestas();
            void insere_arestas(Aresta e);
            void remover_arestas(Aresta e);
            void imprime();
        private:
            int n_vertices;
            int n_arestas;
            std::vector<std::vector<int>> matriz_adj;
    };