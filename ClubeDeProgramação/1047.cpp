#include<iostream>

using namespace std;
int main(){
    int inicio_hr=0,fim_hr=0,tempo_inicio=0;
    int inicio_min=0,fim_min=0,tempo_fim=0;
    int tempo_final=0;
    cin >> inicio_hr >> inicio_min >> fim_hr >> fim_min;
    
    tempo_inicio = (inicio_hr * 60) + inicio_min;
    tempo_fim = (fim_hr * 60) + fim_min;

    if(tempo_inicio > tempo_fim)
        tempo_final = (24*60) - (tempo_inicio - tempo_fim);
    else if(tempo_inicio == tempo_fim)
        tempo_final = 24*60;
    else
        tempo_final = tempo_fim - tempo_inicio;
    inicio_hr = tempo_final / 60;
    inicio_min = tempo_final % 60;
    cout << "O JOGO DUROU " <<inicio_hr << " HORA(S) E " << inicio_min << " MINUTO(S)" << endl;
   
    return 0;
}