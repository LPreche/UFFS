#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i,anos=0;
	float chico,ze;
	chico=1.50;
	ze=1.10;
	
	while(ze <= chico){
		chico +=0.02;
		ze +=0.03;
		anos++;
		printf("%d Ano(s)\taltura Chico %0.2f\taltura ze %0.2f\n",anos,chico,ze);
	}	
			
	
	printf("para que ze seja maior que chico, ele levara %d anos\n",anos);	

	return 0;

}
