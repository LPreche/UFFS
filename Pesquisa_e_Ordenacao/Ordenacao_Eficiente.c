#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//MergeSort
int intercala(int *vetor,int inicio,int meio, int fim){
	int n=(fim-inicio+1),i,j,k;
	int *aux=(int *)malloc(sizeof(n));
	i=inicio;
	j=meio+1;
	k=0;

	while(i<=meio && j<=fim){

		if(vetor[i]<=vetor[j]){
			aux[k]=vetor[i];
			i++;
		}else{
			aux[k]=vetor[j];
			j++;
		}
		k++;
	}

	while(i<=meio){
		aux[k]=vetor[i];
		k++;
		i++;
	}

	while(j<=fim){
		aux[k]=vetor[j];
		k++;
		j++;
	}

	for(k=inicio;k<=fim;k++)
		vetor[k]=aux[k-inicio];

	free(aux);
	return *vetor;
}


int MergeSort(int *vetor, int inicio, int fim){
	int meio=0;
	
	if(inicio<fim){

		meio=(inicio+(fim-1))/2;
		*vetor=MergeSort(vetor,inicio,meio);
		*vetor=MergeSort(vetor,meio+1,fim);
		*vetor=intercala(vetor,inicio,meio,fim);
	}


return *vetor;
}
//fim MergeSort


void troca_elementos(int *pos1,int *pos2){
	int aux;
	
	aux=*pos1;
	*pos1=*pos2;
	*pos2=aux;
}


//QuickSort
int particiona(int *vetor,int inicio,int fim){
	int i=0,j=0,k=0,Ppivo=fim;
	k=inicio;

	for(i=inicio;i<fim;i++){
		if(vetor[i]<=vetor[Ppivo]){
			troca_elementos(&vetor[i],&vetor[k]);
			k++;
		}
	}
	if(vetor[k]>vetor[Ppivo])
		troca_elementos(&vetor[k], &vetor[Ppivo]);

	return Ppivo;
}

int QuickSort(int *vetor,int inicio, int fim){
	int Ppivo;
	if(inicio<fim){
		Ppivo=particiona(vetor,inicio,fim);
		QuickSort(vetor,inicio,Ppivo-1);
		QuickSort(vetor,Ppivo+1,fim);
	}
	return *vetor;
}
//Fim_QuickSort

//HeapSort

int CreateHeap(int *vetor,int i,int n){
	int bigger,left,right;
	bigger=i;
	left=2*i+1;
	right=2*i+2;

	if((left<n)&&(vetor[left]>vetor[i]))
		bigger=left;
	
	if((right<n)&&(vetor[right]>vetor[bigger]))
		bigger=right;

	if(bigger!=i){
		troca_elementos(&vetor[i],&vetor[bigger]);
		CreateHeap(vetor,bigger,n);
	}
return *vetor;
}

int HeapSort(int *vetor,int n){
	int k;

	for(k=(n/2-1);k>=0;k--)
		CreateHeap(vetor,k,n);
	
	for(k=n-1;k>=1;k--){
		troca_elementos(&vetor[0],&vetor[k]);
		CreateHeap(vetor,0,k);
	}
	return *vetor;
}
//fim HeapSort



int Start_Ordening(int *ar,int n,int ord){
	int aux=0,i=0,j=0,fim;
	
	if(ord==1){
	int aux,i=0,j=0;
	for(i=1;i<n;i++){

		for(j=i;j>0;j--){
			if(ar[j]<ar[j-1]){
				aux=ar[j-1];
				ar[j-1]=ar[j];
				ar[j]=aux;
			}
		}
	}

		return *ar;
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
	int i=0,op=0,ord,tvet=0;
	clock_t M,Q,H;
	

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

	//printf("MergeSort\n\n");

	//for(i=0;i<op;i++)
	//	printf("%d ",a1[i]);
	//printf("\n");
	M=clock();
	*a1=MergeSort(a1,0,op-1);
	M=clock()-M;
	//for(i=0;i<op;i++)
	//	printf("%d ",a1[i]);
	
	//printf("\n\nQuickSort\n\n");
	
	//for(i=0;i<op;i++)
	//	printf("%d ",a2[i]);
	//printf("\n");
	Q=clock();
	*a2=QuickSort(a2,0,op-1);
	Q=clock()-Q;
	//for(i=0;i<op;i++)
	//	printf("%d ",a2[i]);

	//printf("\n\nHeapSort\n\n");

	//for(i=0;i<op;i++)
	//	printf("%d ",a3[i]);
	//printf("\n");
	H=clock();
	*a3=HeapSort(a3,op);
	H=clock()-H;
	//for(i=0;i<op;i++)
	//	printf("%d ",a3[i]);




	printf("\nNumero de Elementos: %d\n",op);
	if(ord==1)
		printf("Ordenação escolhida: Crescente\n");
	else if(ord==2)
		printf("Ordenação escolhida: Decrescente\n");
	else
		printf("Ordenação escolhida: Aleatoria\n");
	printf("\nINFORMAÇÕES DE EXECUÇÃO:\n\n");
	printf("TEMPOS DE EXECUÇÕES:\n");
	printf("Marge Sort: %lf ms\n",((double)M)/((CLOCKS_PER_SEC/1000)));
	printf("Quick Sort: %lf ms\n",((double)Q)/((CLOCKS_PER_SEC/1000)));
	printf("Heap Sort: %lf ms\n\n",((double)H)/((CLOCKS_PER_SEC/1000)));
return 0;
}