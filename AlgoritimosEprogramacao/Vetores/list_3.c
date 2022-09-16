#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i,j,k,aux=0;
	scanf("%d",&n);
	int v1[n],v2[n],v3[n+1];
	for(i=0;i<n;i++){
		scanf("%d",&v1[i]);
	}	
	for(j=0;j<n;j++){
		scanf("%d",&v2[j]);
	}
	
	for(k=n;k>=0;k--){
		v3[k]=v1[k]+v2[k];
		v3[k-1]+=aux;
		aux = 0;	
		if(v3[k]>9){
			aux = v3[k]-10;
			v3[k]= v3[k] % 10;
		}
	
	}
	for(i=0;i<n;i++){
		printf("%d ",v3[i]);
	}
	
	return 0;
}
