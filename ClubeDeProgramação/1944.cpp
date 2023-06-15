#include<iostream>
#include<string>
#include<vector>
#include<list>

using namespace std;

int main(){

    int N,inverso=0,gBrindes=0;
    vector<string> painel;
    
    cin >> N;
    int a=0;
    for(auto i = 1; i < N+1; i++){
        if(painel.empty()){
            a++;
            painel.push_back("FACE");
        }
        vector<char> F(4);
        string palavra, antInvertida;
        
        for(auto j = 0; j < 4; j++){
            cin >> F[j];
             palavra += toupper(F[j]);
        }

        painel.push_back(palavra);

        vector<char> C(painel[a-1].begin(), painel[a-1].end());

        for(auto k=3;k>=0;k--)
           antInvertida += C[k];
        
        if(antInvertida == painel[a]){
            gBrindes++;
            painel.pop_back();
            painel.pop_back();
            a-=2;
        }    
        a++;
    }

    cout << gBrindes << endl;
        
    return 0;
}