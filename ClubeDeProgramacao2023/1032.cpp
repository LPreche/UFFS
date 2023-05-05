#include<iostream>
#include<list>

using namespace std;

int main(){

    int n,j,cp;

    do{
        cin >> n;
        if(n>0){
            int primoAtual=1;
            list<int> p;
            for(int a=n;a>0;a--)
                p.push_front(a);

            for(int P : p)
                cout << P << endl;
            
            cout << endl;
            int Eliminado=0,posAnterior=0;
            for(int b=0;b<n;b++){
                int c=1,i=primoAtual+1,aux;
                do{
                    cp = 0;
                    for(int j=i;j>0;j--)
                        if((i % j) == 0)
                            cp++;

                    if(cp == 2){
                        primoAtual = i;
                        //cout << "Primo Atual: "<< primoAtual << endl;
                    }
                    i++;
                }while(cp != 2);

                list<int>::iterator it = p.begin();
                cout << "Primo Atual: " << primoAtual << endl;
                Eliminado = posAnterior + (primoAtual-1);
                cout << "Eliminado: " << Eliminado << endl;
                
                advance(it,Eliminado);
                p.remove(*it);

                posAnterior = Eliminado;

                for(int P : p)
                    cout << P << endl;
                cout << endl;               
            }

        }
    }while(n!=0);
    return 0;
}