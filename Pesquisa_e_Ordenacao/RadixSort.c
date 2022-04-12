#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int ano;
	char modelo[100];
}veiculo;

void CountingSort(veiculo V[],int n, int pos){
	
	veiculo aux[n];
	int cont[10];
	int dig=0,i=0;
	
	for(i=0;i<10;i++)
		cont[i]=0;


	for(i=0;i<n;i++){
		dig=(V[i].ano/pos)%10;
		cont[dig]++;
	}

	for(i=1;i<10;i++){
		cont[i]=cont[i]+cont[i-1];
	}

	for(i=n-1;i>=0;i--){
		dig=(V[i].ano/pos) % 10;
		cont[dig]--;
		aux[cont[dig]].ano=V[i].ano;
		strcpy(aux[cont[dig]].modelo,V[i].modelo);
	}

	for(i=0;i<n;i++)
		V[i]=aux[i];

}

int BuscaMax(veiculo V[],int n){
	int maior=V[0].ano;
	int i=0;

	for(i=0;i<n;i++)
		if(V[i].ano > maior)
			maior=V[i].ano;

	return maior;
}

void RadixSort(veiculo V[],int n){

	int max = BuscaMax(V,n);
	int pos=0;

	for(pos=1;max/pos>0;pos*=10){
		CountingSort(V,n,pos);

	}


}

int main() {
	int i=0;
	veiculo V[15]={
		{2009,"Corsa"},{2008,"Fusion"},{2010,"Gol"},{2009,"Ecosport"},{2011,"X5"},{2012,"A320"},{2004,"Punto"},{2000,"Fox"},{2001,"Vectra"},{2001,"i320"},{2008,"i30"},{2005,"Lancer"},{2006,"Fiesta"},{2007,"5cc"},{2021,"HB20"}
	};
	printf("\n\nNão Ordenado\n\n");
	for(i=0;i<15;i++)
		printf("Ano:%d Modelo:%s\n",V[i].ano,V[i].modelo);

	RadixSort(V,15);
	printf("\n\nOrdenado\n\n");
	for(i=0;i<15;i++)
		printf("Ano:%d Modelo:%s\n",V[i].ano,V[i].modelo);

  return 0;
}