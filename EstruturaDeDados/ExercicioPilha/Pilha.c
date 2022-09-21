#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char ent[60];
	struct element *next;
}element;

typedef struct{
	element *top;
}stack;


element *stack_manipulate(stack *P){
	element *aux;
	aux=P->top;
	P->top=P->top->next;
	free(aux);
	return P;
}

element *stack_insert(char ent[60],element *E,stack *P){
	E=(element *)malloc(sizeof(element));
	strcpy(E->ent,ent);
	E->next=NULL;
	if(P->top==NULL)
		P->top=E;
	else{
		E->next=P->top;
		P->top=E;
	}
	return P;
}

void get_out(stack *P){
	element *aux;
	aux=P->top;
	P->top=aux->next;
	printf("@");
	free(aux);
}
int main() {
	char opt[60];
	element *E,*aux=NULL;
	stack *P;
	P = (stack *)malloc(sizeof(stack));
	P->top=NULL;
	do{
		scanf("%s",opt);
		if((strcmp(opt,"B"))==0){
			if(P->top!=NULL){
				printf("%s\n",P->top);
				P=stack_manipulate(P);
			}else
				printf("Vazio\n");
		}else if((strcmp(opt,"E"))==0){
			if(P->top!=NULL)
				while(P->top!=NULL)
					get_out(P);
			else
				printf("!");
			printf("\n");
			break;
		}else
			P=stack_insert(opt,E,P);

		
	}while((strcmp(opt,"E"))!=0);



return 0;
}