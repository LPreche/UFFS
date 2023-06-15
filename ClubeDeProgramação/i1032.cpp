#include<iostream>
#include<vector>

using namespace std;
/* PROBLEMA RESOLVIDO POREM RETORNA TIME LIMIT EXCEED NO BEECROWD*/
int main(){

    int n,j,cp;

    do{
        cin >> n;
        if(n>0){
            int primoAtual=1;
            vector<int> p;
            p.resize(n);
            for(int a=0;a<n;a++)
                p[a]=a+1;

            int Eliminado=0,posAnterior=0;
            for(int b=0;b<(n-1);b++){
                int i=primoAtual+1,aux;
                do{
                    cp = 0;
                    for(int j=i;j>0;j--)
                        if((i % j) == 0){
                            cp++;
                            if(cp>2)
                                break;
                    }
                    
                    if(cp == 2){
                        primoAtual = i;
                        break;
                    }
                    i++;
                }while(cp != 2);

                Eliminado = (posAnterior + (primoAtual-1)) % p.size();
             
                if(Eliminado == p.size()){
                   Eliminado = 0;
                }

                p.erase(p.begin()+Eliminado);
                posAnterior = Eliminado;
                
            }
            for(int P : p)
                    cout << P << endl;
        }
    }while(n!=0);
            
    return 0;
}