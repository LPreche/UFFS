#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

using namespace std;
int main(){

    double A,B,C,aux=0.0;
    
    cin >> A >> B >> C;

    if(C > B){
        aux = C;
        C = B;
        B = aux;
    }
    if(C > A){
        aux = C;
        C = A;
        A = aux;
    }
    if(B > A){
        aux = B;
        B = A;
        A = aux;
    }
    

    if(A >= (B+C))
        cout << "NAO FORMA TRIANGULO" << endl;
    else if(pow(A,2) == ((pow(B,2))+(pow(C,2))))
        cout << "TRIANGULO RETANGULO" << endl;
    else if(pow(A,2) > ((pow(B,2))+(pow(C,2))))
        cout << "TRIANGULO OBTUSANGULO" << endl;
    else if(pow(A,2) < ((pow(B,2))+(pow(C,2))))
        cout << "TRIANGULO ACUTANGULO" << endl;
    
    if((A == B) && (A == C) && (B == C))
        cout << "TRIANGULO EQUILATERO" << endl;
    if(((A == B)&&(A != C))||((B == C) && (B != A))||((C == A) && (C != B)))
        cout << "TRIANGULO ISOSCELES" << endl;
    return 0;
}