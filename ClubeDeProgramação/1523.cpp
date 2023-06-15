#include<iostream>
#include<stack>
#include<utility>

using namespace std;

int main(){

    int N=0,K=0,S=0,C=0,todosPodemEstacionar=true;
    stack<pair<int,int>> estacionamento;
    do{
        cin >> N >> K;
        if(N == 0 && K == 0)
            break;

        for(auto i = 0;i < N;i++){
            cin >> C >> S;
            pair<int,int> CS;
            CS.first=C;
            CS.second=S;
            if(estacionamento.empty()){
                estacionamento.push(CS);
            }else if(estacionamento.size() == K){
                if(CS.first <= estacionamento.top().second)
            }
        }

    }while(N > 0 && K > 0);
    return 0;
}