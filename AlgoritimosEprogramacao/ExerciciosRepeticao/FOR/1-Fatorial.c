#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n_num,i2,i,j;
	i=0;
	j=0;
	i2=0;
	printf("Digite a quantidade de numeros a serem digitados \n");
	scanf("%d",&n_num);
	int numer[n_num];
	long long int fatorial[n_num];
	
		for(i=0;i<n_num;i++){
			scanf("%d",&numer[i]);
			
			if(numer[i] < 0 ){
				printf("Numero negativo, sera posto 0 em seu lugar!\n");
				numer[i]=0;
			}
			fatorial[i] = numer[i];
			for(j=1;j<numer[i];j++){
				fatorial[i]= fatorial[i] * j;
			}
					
		}
		
		printf("Numero\tFatorial\n\n");
		for(i2=0;i2<n_num;i2++){
			printf("%d\t%lld\n\n",numer[i2],fatorial[i2]);
		}
	
		return 0;
	}
