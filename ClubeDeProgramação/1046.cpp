#include<iostream>

using namespace std;
int main(){
    int inicio=0,fim=0,tempo=0;
    cin >> inicio >> fim;
    if(inicio<=24 && fim <=24){
        if(inicio > fim ){
            tempo = 24 - inicio;
            tempo += fim;
        }else if(inicio == fim){
            tempo = 24;
        }else
            tempo = fim - inicio;

        cout << "O JOGO DUROU " << tempo << " HORA(S)" << endl;
    }
    return 0;
}