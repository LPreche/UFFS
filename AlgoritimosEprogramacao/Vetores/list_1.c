#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
int tam_vet,i,j;
printf("Determine o tamanho do vetor:\n");
scanf("%d",&tam_vet);
int vetor[tam_vet];

for(i=0;i<tam_vet;i++){
	scanf("%d",&vetor[i]);
}

for(j=tam_vet-1;j>=0;j--){
	printf("%d  ",vetor[j]);
}
	return 0;
}
