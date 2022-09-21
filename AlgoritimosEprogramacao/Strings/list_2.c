#include <stdio.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define TAM 10
int main(int argc, char *argv[]) {
	int i,j,k,num1[TAM],num2[TAM],result[TAM];
	char oper[TAM+1];
	
	for(i=0;i<TAM;i++){
		scanf("%d",&num1[i]);
	}
	for(i=0;i<TAM;i++){
		scanf("%s",&oper[i]);
	}
	for(i=0;i<TAM;i++){
		scanf("%d",&num2[i]);
	}
	
	for(i=0;i<TAM;i++){
		if(oper[i]=='+'){
			result[i]= num1[i] + num2[i];
		}else if(oper[i]=='-'){
			result[i]= num1[i] - num2[i];
		}else if(oper[i]=='*'){
			result[i]=num1[i] * num2[i];
		}else if(oper[i]=='/'){
			result[i]=num1[i] / num2[i];  
		}
	}
	printf("\n Resultado: ");
	for(i=0;i<TAM;i++){
		printf("%d ",result[i]);  	
	}
	
	return 0;
}
