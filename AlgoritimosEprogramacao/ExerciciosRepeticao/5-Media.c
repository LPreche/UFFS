#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	setlocale(LC_ALL,"portuguese");
	int i;
	float media=0,soma=0,num;
	
	for(i=0;;i++){
		scanf("%f",&num);
		if(num < 0){
			break;
		}else{
			soma +=num;
		}
	}
	
	media= soma / i;
	printf("Média dos valores é: %0.2f",media);	
		return 0;
}
