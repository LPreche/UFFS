#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	int i,j,cont,n1=97,n2=120;
	long long int mult=1;
	
	for(i=n1 ;i<=n2;i++){
		cont=0;	
	
		for(j=1;j <= i;j++){
		
			if((i % j)==0){
				cont++;		
			}	
		}
		
		if(cont == 2){
		mult *= i;
		}
	
	}
	
	printf("\n%lli",mult);
		
		return 0;
}
