#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

struct Alunos {
    string nome;
    char tamanho;
    string cor;
};

int main() {
    int N;
    bool controle = true;
    while (cin >> N && N != 0) {
        vector<Alunos> alunos;
        cin.ignore();
        for (int i = 0; i < N; i++) {
            Alunos aluno;
            getline(cin, aluno.nome);
            cin >> aluno.cor >> aluno.tamanho;
            cin.ignore(); // Descartar o caractere de nova linha após a leitura do tamanho
            alunos.push_back(aluno);   
        }
        list<string> brancoP,brancoM,brancoG,vermelhoP,vermelhoM,vermelhoG;
        for(Alunos A : alunos){
            if(A.cor =="branco" && A.tamanho =='P')
                brancoP.push_back(A.nome);
            else if(A.cor == "branco" && A.tamanho =='M')
                brancoM.push_back(A.nome);
            else if(A.cor == "branco" && A.tamanho =='G')
                brancoG.push_back(A.nome);
            else if(A.cor == "vermelho" && A.tamanho =='P')
                vermelhoP.push_back(A.nome);
            else if(A.cor == "vermelho" && A.tamanho =='M')
                vermelhoM.push_back(A.nome);
            else if(A.cor == "vermelho" && A.tamanho =='G')
                vermelhoG.push_back(A.nome);
        }
        
        brancoP.sort();
        brancoM.sort();
        brancoG.sort();
        vermelhoP.sort();
        vermelhoM.sort();
        vermelhoG.sort();
        
        if(!controle)
            cout << endl;
        else
            controle = false;

        for(string NC : brancoP)
            cout << "branco P "<< NC << endl;
        for(string NC : brancoM)
            cout << "branco M "<< NC << endl;
        for(string NC : brancoG)
            cout << "branco G "<< NC << endl;
        for(string NC : vermelhoP)
            cout << "vermelho P "<< NC << endl;
        for(string NC : vermelhoM)
            cout << "vermelho M "<< NC << endl;
        for(string NC : vermelhoG)
            cout << "vermelho G "<< NC << endl;
        
    }

    return 0;
}
