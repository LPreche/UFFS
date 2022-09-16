#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i;
	do{
		scanf("%d",&n);
	}while(n>100);
	
	int vet[n];	
	
	for(i=0;i<n;i++){
		scanf("%d",&vet[i]);
	}
	for(i=(n-1);i>=0;i--){
		printf("%d ",vet[i]);
	}	
	return 0;
}
