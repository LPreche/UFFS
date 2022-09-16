#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
# define vet 10 
int main(int argc, char *argv[]) {
   	int a[vet],b[vet],c[vet*2],i,j;	
	for(i=0;i<vet;i++){
		scanf("%d",&a[i]);
	}
	
	for(i=0;i<vet;i++){
		scanf("%d",&b[i]);
	}
	j=0;
	for(i=0;i<(vet*2);i+=2){
		c[i]=a[j];
		j++;
	}
	j=0;
	for(i=1;i<(vet*2);i+=2){
		c[i]= b[j];
		j++;
	}
	
	for(i=0;i<(vet*2);i++){
		printf("%d ",c[i]);
	}
	return 0;
}
