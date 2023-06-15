#include<iostream>
#include<string>
#include<stack>
#include<vector>
using namespace std;


int main(){
    int n;

    do{
        stack<int> cartas, aux;
        vector<int> descarte;
        int pBase;
        cin >> n;

        if(n != 0){
            for(auto i=n;i>0;i--){
                cartas.push(i);
            }
            while(cartas.size() > 1){
                descarte.push_back(cartas.top());
                cartas.pop();
                if(cartas.size() > 1){
                    pBase = cartas.top();
                    cartas.pop();
                    while(!cartas.empty()){
                        aux.push(cartas.top());
                        cartas.pop();
                    }

                    cartas.push(pBase);

                    while(!aux.empty()){
                        cartas.push(aux.top());
                        aux.pop();
                    }
                }
            }

            cout << "Discarded cards: ";
            for(auto i=0;i<descarte.size();i++){
                cout << descarte[i] ;
                if(i < descarte.size() - 1)
                    cout << ", " ;
            }
            cout << endl;
            cout << "Remaining card: " << cartas.top() << endl;

        }
    }while(n != 0);
        

    return 0;
}