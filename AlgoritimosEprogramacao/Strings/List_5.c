#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char palavra[60],inversa[60];
	int i,j=0,tam;
	scanf("%s",palavra);
	tam = strlen(palavra);
	inversa[tam+1]='/0';
	for(i=tam-1;i>=0;i--){
		inversa[i]=palavra[j];
		j++;
	}
	if((strcmp(palavra,inversa))==0){
		printf("\n %s e um palidromo",palavra);
	}else{
		printf("\n %s nao e um palidromo",palavra);
	}
	return 0;
}
