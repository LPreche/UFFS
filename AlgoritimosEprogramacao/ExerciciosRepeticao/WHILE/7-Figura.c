#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i=0,j=1;
	printf("+");
	while(i < 5){
		printf("/\\");
		i++;
		
	}	
	printf("+\n");
	printf("|\t   |\n");
	i=1;
	while(j<=2){
	if(j<2) printf("+");
		while(i <= 5){
			printf("/\\");
			i++;
		}
	if(j <2) printf("+");
	if(j <2) printf("\n");
	j++;
	}
	
	j=1;
	while(j <= 5){
		printf("|\t   |");
		if(j < 5) printf("\n");
		j++;
	}
	
	j=1;
	printf("\n+");
	while(j <= 5){
		printf("/\\");
		j++;			
	}
	printf("+");
		return 0;
	}
