#include<iostream>
#include<stack>
#include<vector>
#include<utility>

using namespace std;

pair<int,int> Entrar(vector<pair<int,int>> P, int k){
    for(auto i=0;i<P.size();i++)
        if(P[i].first == k)
            return P[i];
    pair<int,int> r(0,0);
    return r;
}
/*----------------CODIGO INCOMPLETO / PROBLEMA NÃO SOLUCIONADO-----------*/ 
int main(){

    int N=0,K=0,S=0,C=0,vagasDisponiveis;
    stack<pair<int,int>> estacionamento;
    vector<pair<int,int>> clientes;
    pair<int,int> r(0,0);

    do{
        cin >> N >> K;

        if(N == 0 && K == 0)
            break;

        for(auto i=0;i<N;i++){
            cin >> C >> S;
            pair<int,int> CS;
            CS.first=C;
            CS.second=S;  
            clientes.push_back(CS);
        }

        vagasDisponiveis = K;

        int maiorS = clientes[0].second;

        for(auto j=1;j<clientes.size();j++)
            if(clientes[j].second > maiorS)
                maiorS = clientes[j].second;
        
        for(auto k=1;k<=maiorS;k++){
            pair<int,int > cliente = Entrar(clientes,k);

            if(cliente != r){
                if(estacionamento.empty()){
                    estacionamento.push(cliente);
                    vagasDisponiveis--;
                }else if(vagasDisponiveis > 0){
                    estacionamento.push(cliente);
                    vagasDisponiveis--;
                }else{
                    if(cliente.second )
                }
            }

        }

        
            


    }while(N > 0 && K > 0);
    return 0;
}