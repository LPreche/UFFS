#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
float S=0,divs=0,i=1,j=1;

	while(j<=50){
		
		S += (i / j) ;
		i+=2;
		j++;	
	}
	
	printf("S = %0.2f\n",S);
	return 0;
}
