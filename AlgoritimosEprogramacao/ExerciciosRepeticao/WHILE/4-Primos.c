#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int i=97,n2=1478,cont=0,j=1,soma=0;
	
	while(i <= n2){
	cont=0;
		while(j <= i){
			if((i % j)==0){
				cont++;
			}	
		j++;
		}
		
		if(cont == 2){
			soma += i;
		}
	i++;
	j=1;
	}
	printf("\nSoma dos primos e: %d \n",soma);
	
	



	return 0;
}


