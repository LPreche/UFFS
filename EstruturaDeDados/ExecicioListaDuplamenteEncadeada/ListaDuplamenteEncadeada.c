#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int dia;
	int mes;
	int ano;
}data;


typedef struct{
	char matricula[10];
	char nome[40];
	data nascimento;
	float media;
	struct aluno *next;
	struct aluno *prev;
}aluno;

typedef struct {
	aluno *head;
	aluno *tail;
}estrutura;

aluno *search_student(aluno *head,char matricula[10]){
	aluno *aux;

	for(aux=head;aux!=NULL;aux=aux->next){
		if((strcmp(aux->matricula,matricula)==0)){
			return aux;
			break;
		}
	}
	return aux;
}

aluno *insert_student(aluno *A, char matricula[10],estrutura *E){
	aluno *aux, *anex;
	aux=search_student(E->head,matricula);

			if(aux!=NULL){
				
				if(aux==E->head){

					if(E->head==E->tail){

						E->head->next=A;
						A->prev=E->head;
						A->next=NULL;
						E->tail=A;
					}else{

						A->prev=E->head;
						A->next=E->head->next;
						E->head->next=A;
					}
				}else if(aux==E->tail){

						E->tail->next=A;
						A->prev=E->tail;
						A->next=NULL;
						E->tail=A;
				}else{

					anex=aux->next;
					A->prev=aux;
					anex->prev=A;
					A->next=aux->next;
					aux->next=A;
				}
			}else{

				if(aux==NULL)

				A->next=E->head;
				E->head->prev=A;
				E->head=A;
			}
	return E;
}

void show_students(estrutura *E, int op){
	aluno *aux;

		if(op==3)
			for(aux=E->head;aux!=NULL;aux=aux->next)
				printf("%s, %s, %d/%d/%d, %.2f\n",aux->matricula,aux->nome,aux->nascimento.dia,aux->nascimento.mes,aux->nascimento.ano,aux->media);
		else if(op==4)
			for(aux=E->tail;aux!=NULL;aux=aux->prev)
				printf("%s, %s, %d/%d/%d, %.2f\n",aux->matricula,aux->nome,aux->nascimento.dia,aux->nascimento.mes,aux->nascimento.ano,aux->media);

		
}

aluno *del_student(estrutura *E, char matricula[10]){
	aluno *repeat,*aux,*prev=NULL,*pnext;

	if(E->head==NULL)
		printf("Lista Vazia!\n");
	else{

		for(repeat=E->head;repeat!=NULL;repeat=repeat->next){
			aux=search_student(E->head,matricula);
			if(aux!=NULL){
				if(aux==E->head){
					E->head=E->head->next;
					E->head->prev=NULL;
				}else if(aux==E->tail){
					E->tail=E->tail->prev;
					E->tail->next=NULL;
				}else{
					prev=aux->prev;
					prev->next=aux->next;
					pnext=prev->next;
					pnext->prev=prev;
				}
				free(aux);
			}
		}
	}
	return E;
}



void GetOut(aluno *head){
	aluno *aux,*prev;
	for(aux=head;aux!=NULL;aux=aux->next){
		prev=aux;
		free(prev);
		printf("*");
	}
	free(aux);
	printf("\n");
}

int main(){

	int op;
	char mat[10];
	aluno *aux,*A;
	estrutura *E;
	E=(estrutura *) malloc(sizeof(estrutura));
	E->head=NULL;
	E->tail=NULL;
	do{
		/*
		printf("+------------------------------+\n");
		printf("|     1 - Incluir Aluno        |\n");
		printf("|     2 - Apagar Aluno         |\n");
		printf("|     3 - Listar Alunos(inic.) |\n");
		printf("|     4 - Listar Alunos(ult.)  |\n");
		printf("|     0 - Sair                 |\n");
		printf("+------------------------------+\n");
		*/
		scanf("%d",&op);
	
			if(op==1){

					scanf("%s",&mat);
					A=(aluno *) malloc(sizeof(aluno));
					scanf("%s",&A->matricula);
					scanf("%s",&A->nome);
					scanf("%d/%d/%d",&A->nascimento.dia,&A->nascimento.mes,&A->nascimento.ano);
					A->next=NULL;
					A->prev=NULL;
					scanf("%f",&A->media);
					
					if(E->head==NULL){
						E->head=A;
						E->tail=A;
					}else
						E=insert_student(A, mat, E);
				
					
			}
			else if(op==2){
				if(E->head!=NULL){
					scanf("%s",&mat);
					E=del_student(E, mat);
				}else
					printf("Lista Vazia!\n");

			}

			else if(op==3){

				if(E->head!=NULL)
					show_students(E,3);
				else
					printf("Lista Vazia!\n");
			}

			else if(op==4){

				if(E->head!=NULL)
					show_students(E,4);
				else
					printf("Lista Vazia!\n");
			}

			else if(op==0){
				if(E->head!=NULL)
					GetOut(E->head);
			}


	}while(op!=0);
	printf("\n");
	return 0;
}