#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main(){

    int p;
    cin >> p;

    for(auto i=0;i<p;i++){
        vector<int> entrada;
        vector<int> edificio;
        int np,andar,aux,nAndares;
        cin >> np;
        for(auto j=0;j<np;j++){
            cin >> andar;
            entrada.push_back(andar); 
        }

        for(auto i=1;i<entrada.size();i++){
            for(auto j=i;j>0;j--){
                if(abs(entrada[j]) > abs(entrada[j-1])){
                    aux=entrada[j-1];
                    entrada[j-1]=entrada[j];
                    entrada[j]=aux;
                }
            }
        }

        edificio.push_back(entrada[0]);
        if(entrada.size() > 1){    
            for(auto j=1;j<entrada.size();j++){
                if(entrada[j] > 0){    
                    if(entrada[j-1] < 0)
                        edificio.push_back(entrada[j]);
                }else{
                        if(entrada[j-1] > 0)
                            edificio.push_back(entrada[j]);
                }
            }
        }
        
        cout << edificio.size() << endl;
    }

    return 0;
}