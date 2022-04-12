#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BubbleSortFlagged(int *vetor, int n, int *cont){
	int flag=0,aux=0,i=0,fim=0;
	cont[0]=0;
	while(!flag){
		flag=1;
		fim=n-1;
		cont[0]++;
		for(i=0;i<fim;i++){
			cont[0]++;
			if(vetor[i]>vetor[i+1]){
				aux=vetor[i];
				vetor[i]=vetor[i+1];
				vetor[i+1]=aux;
				flag=0;
			}	
		}
		fim--;
	}
	return *vetor;
}

int InsertionSort(int *vetor, int n,int *cont){
	int aux,i=0,j=0;
	cont[1]=0;
	for(i=1;i<n;i++){
		cont[1]++;
		for(j=i;j>0;j--){
			cont[1]++;
			if(vetor[j]<vetor[j-1]){
				aux=vetor[j-1];
				vetor[j-1]=vetor[j];
				vetor[j]=aux;
			}
		}
	}

		return *vetor;
}

int SelectionSort(int *vetor,int n,int *cont){
	int menor,i=0,j=0,k=0;
	cont[2]=0;
	for(i=0;i<n;i++){
		cont[2]++;
		menor=vetor[i];
		for(j=i;j<n;j++){
			cont[2]++;
			if(vetor[j]< menor){
				menor=vetor[j];
				vetor[j]=vetor[i];
				vetor[i]=menor;
			}
		}
	}
	return *vetor;
}

int Start_Ordening(int *ar,int n,int ord){
	int aux=0,i=0,j=0,flag=0,fim;
	
	if(ord==1){
		while(!flag){
			flag=1;
			fim=n-1;
			for(i=0;i<fim;i++){

				if(ar[i]>ar[i+1]){
					aux=ar[i];
					ar[i]=ar[i+1];
					ar[i+1]=aux;
					flag=0;
				}	
			}
			fim--;
		}
	}
	else if(ord==2){
		for(i=0;i<n;i++){
			for(j=0;j<i;j++){
				if(ar[i]>ar[j]){
					aux=ar[i];
					ar[i]=ar[j];
					ar[j]=aux;
				}
			}
		}
	}
return *ar;
}

void Copy_Array(int *ar1,int *ar2,int *ar3,int n){
	int i=0;
	for(i=0;i<n;i++){
		ar2[i]=ar1[i];
		ar3[i]=ar1[i];
	}
	

}
int main(){
	int i=0,op=0,cont[3],ord;
	clock_t B,I,S;
	

	do{
		printf("Digite o tamanho do vetor: ");
		scanf("%d",&op);
		printf("Digite a ordenação a iniciar vetor:\n1-Crescente\n2-Decrescente\nOpções diferentes das anteriores, os elementos serão escolhidos aleatoriamente!\n");
		printf("opção: ");
		scanf("%d",&ord);
	}while(op<0);

	int a1[op],a2[op],a3[op];
	
	for(i=0;i<op;i++)
		a1[i]=rand()%1000;
	*a1=Start_Ordening(a1,op,ord);
	Copy_Array(a1,a2,a3,op);
	/*for(i=0;i<op;i++)
		printf("%d ",a1[i]);
	printf("\n\n");
	for(i=0;i<op;i++)
		printf("%d ",a2[i]);
	printf("\n\n");
	for(i=0;i<op;i++)
		printf("%d ",a3[i]);
	printf("\n\n");*/

	//BUBBLE SORT
	B = clock();
	*a1=BubbleSortFlagged(a1,op,cont);
	B = clock()-B;


	//INSERTION SORT
	I = clock();
	*a2=InsertionSort(a2,op,cont);
	I = clock()-I;


	//SELECTION SORT
	S = clock();
	*a2=SelectionSort(a3,op,cont);
	S = clock()-S;

	printf("\nNumero de Elementos: %d\n",op);
	if(ord==1)
		printf("Ordenação escolhida: Crescente\n");
	else if(ord==2)
		printf("Ordenação escolhida: Decrescente\n");
	else
		printf("Ordenação escolhida: Aleatoria\n");
	printf("\nINFORMAÇÕES DE EXECUÇÃO:\n\n");
	printf("NUMERO DE COMPARAÇÕES:\n");
	printf("Bubble Sort C/ flag: %d Comp.\n",cont[0]);
	printf("Insertion Sort: %d Comp.\n",cont[1]);
	printf("Selection Sort: %d Comp.\n\n",cont[2]);
	printf("TEMPOS DE EXECUÇÕES:\n");
	printf("Bubble Sort C/ flag: %lf ms\n",((double)B)/((CLOCKS_PER_SEC/1000)));
	printf("Insertion Sort: %lf ms\n",((double)I)/((CLOCKS_PER_SEC/1000)));
	printf("Selection Sort: %lf ms\n\n",((double)S)/((CLOCKS_PER_SEC/1000)));
return 0;
}