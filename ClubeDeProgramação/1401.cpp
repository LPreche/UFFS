#include<iostream>
#include<list>
#include<string>
#include<algorithm>

using namespace std;


int main(){

    int n;
    cin >> n;
    cin.ignore();
    for(auto i=0;i<n;i++){
        string entrada;
        getline(cin,entrada);
        sort(entrada.begin(),entrada.end());

        do{
            cout << entrada << endl;
        } while (next_permutation(entrada.begin(),entrada.end()));

        if(i<n)
            cout << endl;
        
        
    }

    return 0;
}