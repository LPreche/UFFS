#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define vet 10
int main(int argc, char *argv[]) {
 int v[vet],i,j,aux;
 
 for(i=0;i<vet;i++){
 	scanf("%d",&v[i]);
 }
 
  for(i=0;i<vet;i++){
  	for(j=i+1;j<vet;j++){
  		if(v[i]>v[j]){
  			aux = v[i];
  			v[i] = v[j];
  			v[j]=aux;
		  }
	  }
  }
  
  for(i=0;i<vet;i++){
  	printf("%d  ",v[i]);
  }
	return 0;
}
