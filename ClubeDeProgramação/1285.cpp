#include<iostream>
#include<vector>

using namespace std;

bool temRepetidos(vector<int> D){

    for(auto i=0;i<D.size();i++){
        for(auto j=0;j<D.size();j++){
            if(i!=j){
                if(D[i] == D[j]){
                    return true;
                }
            }
        }
    }
    return false;
}


int main(){
    int N,M,contagem=0;
    
    do{
        cin >> N >> M;
    }while(N > M);

    for(int i=N;i<=M;i++){
        string numero = to_string(i);
        vector<int> digitos;
        for(char d : numero)
            digitos.push_back(d-'0');

        if(!temRepetidos(digitos))
            contagem++;
    }

    cout<< contagem << endl;

}