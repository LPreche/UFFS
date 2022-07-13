#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	int i;
	float media=0,soma=0,num;
	
	do{
		scanf("%f",&num);
		soma +=num;
		i++;
	}while(num>=0);
	
	
	media= soma / i;
	printf("Média dos valores é: %0.2f",media);	
		return 0;
}
