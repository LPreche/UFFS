#include<iostream>

using namespace std;

int main(){

    int cont=0,i=0;
    float valores[6];
    for(i=0;i<6;i++){
       cin >> valores[i];
    }

    for(i=0;i<6;i++){
        if(valores[i] >= 0 )
            cont++;
    }
    cout << cont << " valores positivos" << endl;
    return 0;
}