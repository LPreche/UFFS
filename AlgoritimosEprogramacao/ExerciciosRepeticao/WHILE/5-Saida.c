#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int numer,i=1,j=1;
	scanf("%d",&numer);
	while(i <= numer){
		while(j <= i){
			printf("%d",i);
			j++;
		}
		printf("\n");
		j=1;
		i++;
	}
	
	return 0;
}
