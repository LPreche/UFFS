#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char conc[75];
	int i,i1;
	double matric[75];
	float med_final[75];
		for(i=1;i<=75;i++){
			printf("\nDigite a matricula\n");
			scanf("%lf",&matric[i]);
			printf("\nDigite sua nota final\n");
			scanf("%f",&med_final[i]);
			
			if((med_final[i] > 10.0)||(med_final[i] < 0.0)){
				printf("\nNumero negativo ou maior que 10,0\n Digite novamente:\n");
				scanf("%f",&med_final[i]);
			}
			
			if((med_final[i] >= 0.0)&&(med_final[i] < 5.0)){
				conc[i]='D';
			}else if((med_final[i] >=5.0)&&(med_final[i] < 7.0)){
				conc[i]='C';
			}else if((med_final[i] >=7.0)&&(med_final[i] <9.0)){
				conc[i]='B';
			}else if((med_final[i]>=9.0)&&(med_final[i] <=10.0)){
				conc[i]='A';
			}
			
		}
		printf("Matricula\t\tConceito\n");
		for(i1=1;i1<=75;i1++){
			printf("%0.0lf\t\t\t%c\n",matric[i1],conc[i1]);
		}
		return 0;
	}
