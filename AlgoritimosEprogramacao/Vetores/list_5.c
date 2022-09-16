#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define vet 10
int main(int argc, char *argv[]) {
	int v[vet],i,j,maior=-999999999,menor=999999999,rep;
	for(i=0;i<vet;i++){
		scanf("%d",&v[i]);
	}
	for(j=0;j<vet;j++){
		if(v[j] > maior){
			maior = v[j];
		}
	}
	
	for(j=0;j<vet;j++){
		if(v[j] < menor){
			menor = v[j];
		}
	}

	printf("Valor que mais aparece e: %d\n",n);
	printf("Menor e: %d \n",menor);
	printf("Maior e: %d \n",maior);	
	return 0;
}
