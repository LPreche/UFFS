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
	char nome[10];
	data nascimento;
	float media;
	struct aluno *next;
}aluno;

void insert_student(aluno *A,aluno *first){
	aluno *aux;
	
	for(aux=first;aux->next!=NULL;aux=aux->next);
		 
	aux->next=A;

}

void show_students(aluno *first){
	aluno *aux;

		for(aux=first;aux!=NULL;aux=aux->next)
			printf("%s, %s, %d/%d/%d, %.2f\n",aux->matricula,aux->nome,aux->nascimento.dia,aux->nascimento.mes,aux->nascimento.ano,aux->media);
		
}

aluno *del_student(aluno *first, char matricula[10]){
	aluno *aux2,*aux,*prev=NULL;
	aux2=first;
	if(first==NULL)
		printf("Lista Vazia!\n");
	else{
		while(aux2!=NULL){
			for(aux=first;aux!=NULL;aux=aux->next){
				if((strcmp(aux->matricula,matricula))==0){

					if(aux==first){
						first=first->next;
						break;
					}
						prev->next=aux->next;
						break;
				}
				prev=aux;
			}
		aux2=aux2->next;
		}
	}
	return first;
}

void show_students_inverted(aluno *first){
	aluno *aux;
	aux=first;

		if(!aux)
			return;
		show_students_inverted(aux->next);
		printf("%s, %s, %d/%d/%d, %.2f\n",aux->matricula,aux->nome,aux->nascimento.dia,aux->nascimento.mes,aux->nascimento.ano,aux->media);

}

int number_students(aluno *first){
	int count=0;
	aluno *aux;

	for(aux=first;aux!=NULL;aux=aux->next)
		count++;

	return count;
}
void GetOut(aluno *first){
	aluno *aux,*prev;
	for(aux=first;aux!=NULL;aux=aux->next){
		prev=aux;
		free(prev);
		printf("-");
	}
	free(aux);
	printf("\n");
}

int main(){
	int op,N_students=0;
	char mat[10];
	aluno *first=NULL,*aux,*A;

	do{
		/*
		printf("+------------------------------+\n");
		printf("|     1 - Incluir Aluno        |\n");
		printf("|     2 - Apagar Aluno         |\n");
		printf("|     3 - Listar Alunos(inc.)  |\n");
		printf("|     4 - Listar Alunos(Inv.)  |\n");
		printf("|     5 - Numero de Alunos     |\n");
		printf("|     0 - Sair                 |\n");
		printf("+------------------------------+\n");
		*/
		scanf("%d",&op);
	
			if(op==1){
				A=(aluno *) malloc(sizeof(aluno));
				scanf("%s",&A->matricula);
				scanf("%s",&A->nome);
				scanf("%d/%d/%d",&A->nascimento.dia,&A->nascimento.mes,&A->nascimento.ano);
				A->next=NULL;
				scanf("%f",&A->media);
				if(first==NULL){
					first=A;
					aux=A;
				}else
					insert_student(A,first);
				
			}
			else if(op==2){
			scanf("%s",&mat);
			first=del_student(first, mat);
			}

			else if(op==3){
				if(first!=NULL)
					show_students(first);
				else
					printf("Lista Vazia!\n");
			}

			else if(op==4){
				if(first!=NULL)
					show_students_inverted(first);
				else
					printf("Lista Vazia!\n");
			}

			else if(op==5){
				N_students=number_students(first);
				printf("%d\n",N_students);
			}
			else if(op==0){
				if(first!=NULL)
					GetOut(first);
			}


	}while(op!=0);
	printf("\n");
	return 0;
}