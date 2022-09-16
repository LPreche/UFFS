#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int numer,i=1,j=1,n;
	scanf("%d",&numer);
	n=numer;
	while(i <= numer){
		
		while(n >= j){
			printf("*");
			j++;
		}
		printf("\n");
		n--;
		j=1;
		i++;
	}
	return 0;
}
