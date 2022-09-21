#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n,numer,i=1,j=1;
	scanf("%d",&numer);
	printf("\n");
	while(i <= numer){
			
		while(j <= i){
			printf("*");
			j++;
		}
		j=1;
		printf("\n");
		i++;
	}
	
	i=1;
	j=1;
	n = numer - 1;
	while(i <= (numer-1)){
	
		while(n >= j){
			printf("*");
			j++;
		}
		j=1;
		n--;
		printf("\n");
		i++;
	}
	return 0;
}
