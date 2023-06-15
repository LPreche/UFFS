#include<iostream>
#include<string>
#include<math.h>
#include<list>

using namespace std;


int CalculaFatorial(int n){
    int nFatorial=n;
    if(n==0){
        nFatorial=1;
    }else{
        for(int i=n;i>1;i--)
            nFatorial = nFatorial * (i-1);
        return nFatorial;
    }
}

int main(){
    int N,menor=0,aux,i=1,fatorialLimite;
    cin >> N;
    aux=N;
    
    do{
        fatorialLimite = CalculaFatorial(i);
        i++;
    }while(fatorialLimite < N);

    for(auto j=i;j>0;j--){
        int fatorial = CalculaFatorial(j);
        while(aux >= fatorial){
            aux -= fatorial;
            menor++;
        }
    }
    cout << menor << endl;
    return 0;
}

