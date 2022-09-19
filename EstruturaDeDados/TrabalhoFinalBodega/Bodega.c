#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
	int cod;
	char desc[50];
	int conteudo;
	float preco;
	int qtd;
	char alcoolico[1];
	struct bebida *next;
	struct bebida *prev;
}bebida;

typedef struct{
	bebida *head;
	bebida *tail;
}estrutura;

typedef struct{
	int dia;
	int mes;
	int ano;
}data;

bebida *busca_bebida(estrutura *E,int cod){
	bebida *aux=NULL;

	if(E->head!=NULL)
		for(aux=E->head;aux!=NULL;aux=aux->next)
			if(aux->cod==cod)
				break;
		
	return aux;
}

bebida *cadastra_bebida(estrutura *E, bebida *B){
	bebida *aux=NULL;

	if(E->head==E->tail){
		E->head->next=B;
		B->prev=E->head;
		E->tail=B;
	}else{
		E->tail->next=B;
		B->prev=E->tail;
		E->tail=B;
	}

	return E;
}

void listar_bebidas(estrutura *E){
	bebida *aux=NULL; 

	for(aux=E->head;aux!=NULL;aux=aux->next){

		printf("Codigo: %d\t\tDesc.: %s\t\tConteudo: %dML\t\tPreco:R$%.2f\t\tEstoque: %dUN\t\tAlcoólica?: %s\n",aux->cod,aux->desc,aux->conteudo,aux->preco,aux->qtd,aux->alcoolico);
	}
}
bebida *deletar_bebida(estrutura *E,int cod){
	bebida *aux,*pnext,*prev;
	aux=busca_bebida(E,cod);
	if(aux!=NULL){

		printf("\nBebida excluida com sucesso:   ");
		printf("Cod: %d\tDesc: %s\n",aux->cod,aux->desc);
		
		if((aux==E->head)&&(aux==E->tail)){
			E->head=NULL;
			E->tail=NULL;
		}else if(aux==E->head){
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
	}else
		printf("\nCodigo não encontrado!\n");
	return E;
}

bebida *comprar_bebida(estrutura *E){
	bebida *aux;
	int cod=0,qtdC=0;
	printf("\nDigite o codigo da bebida a dar entrada:    ");
	scanf("%d",&cod);
	aux=busca_bebida(E,cod);
	if(aux!=NULL){
		printf("\nBebida localizada!\n");
		printf("\nCod: %d\tDescrição: %s\tEstoque atual: %d\t",aux->cod,aux->desc,aux->qtd);
		printf("\nDigite a quantidade a dar entrada:    ");
		scanf("%d",&qtdC);
		aux->qtd=aux->qtd+qtdC;
	}else
		printf("\nBebida não cadastrada!\n");

	return E;
}

int form_idade(data *D){
	int idade,year;
	struct tm *data_atual;     
	time_t segundos;
	time(&segundos);   
	data_atual = localtime(&segundos);
	year=data_atual->tm_year+1900;
	idade = (((D->ano*365)+(D->mes*30)+ D->dia)-((year*365)+((data_atual->tm_mon+1)*30)+(data_atual->tm_mday)));  
	idade=abs(idade/365);
	return idade;
}
bebida *debita_estoque(bebida *B){
	int qtdV=0;
	float vlr;
	if(B->qtd!=0){
		system("clear");
		printf("\nEstoque disponivel da bebida %s: %d\n",B->desc,B->qtd);
		printf("\nDigite a quantidade a ser vendida:    ");

		do{
			scanf("%d",&qtdV);

			if(B->qtd < qtdV){
				system("clear");
				printf("\nQuantidade superior ao estoque disponivel!\n");
				printf("Digite a quantidade ser vendida novamente:    ");

			}else{
				B->qtd=B->qtd - qtdV;
				vlr=B->preco*qtdV;
				system("clear");
				printf("\nBebida Vendida!\nValor total:%0.2f\n",vlr);
				printf("\nEstoque atual da bebida %s: %d\n",B->desc,B->qtd);
			}

		}while(B->qtd < qtdV);

	}else
		printf("\nBebida com estoque zerado!\n");

	return B;
}
bebida *vender_bebida(estrutura *E){
	bebida *aux;
	data *D;
	D=(data *)malloc(sizeof(data));
	int cod=0,qtdV=0,idade=0;
	printf("\nDigite o codigo da bebida:    ");
	scanf("%d",&cod);
	aux=busca_bebida(E,cod);
	if(aux!=NULL){

		if(strcmp(aux->alcoolico,"S")==0){
			system("clear");
			printf("Bebida Destinada a maiores de 18 anos!\n\n");
			printf("\nDigite a data de nascimento do cliente(dd/mm/aaaa):    ");
			scanf("%d/%d/%d",&D->dia,&D->mes,&D->ano);
			idade=form_idade(D);

			if(idade>=18)
				aux=debita_estoque(aux);
			else
				printf("\nVenda não autorizada!\n\nCliente menor de idade\n");

		}else
			aux=debita_estoque(aux);
	}else
		printf("\nBebida não encontrada!\n");

	return E;
}
void fim_sistema(estrutura *est){
	bebida *aux,*prev;
	for(aux=est->head;aux!=NULL;aux=aux->next){
		prev=aux;
		free(prev);
	}
	free(aux);
}

int main() {
	printf("Bem Vindo a bodega do joãoozin!\n");
	int op=0,cod=0,idade;
	char alc[1];
	bebida *B,*aux;
	estrutura *E;
	E=(estrutura *) malloc(sizeof(estrutura)); 
	E->head=NULL;
	E->tail=NULL;

	do{	
		printf("\n");	
		printf("+--------------MENU-------------+\n");
		printf("|     1 - Cadastrar Bebidas     |\n");
		printf("|     2 - Listar Bebidas        |\n");
		printf("|     3 - Buscar Bebida         |\n");
		printf("|     4 - Excluir Bebida        |\n");
		printf("|     5 - Comprar Bebida        |\n");
		printf("|     6 - Vender Bebida         |\n");
		printf("|     7 -    SAIR               |\n");
		printf("+-------------------------------+\n");
		printf("o que deseja fazer ?    ");
		scanf("%d",&op);
		printf("\n\n\n");

		switch(op){

			case 1:
				system("clear");
				int cmp_alc=0;
				printf("\nCadastro de Bebida \n\n");
				B=(bebida *) malloc(sizeof(bebida));
				printf("Digite as informações da bebida\n");
				printf("Codigo:    ");
				do{

					scanf("%d",&cod);
					aux=busca_bebida(E,cod);
					if(aux==NULL)
						B->cod=cod;
					else
						printf("\nCodigo ja cadastrado, digite outro numero:    ");
				}while(aux!=NULL);
				
				printf("Descricao:    ");
				scanf("%s",B->desc);
				printf("Conteudo(ML):    ");
				scanf("%d",&B->conteudo);
				printf("Preco(R$):    ");
				scanf("%f",&B->preco);
				printf("Estoque atual(UN):    ");
				scanf("%d",&B->qtd);
				printf("Bebida alcoolica?(S-Sim N-Nao):    ");

				do{
					
					scanf("%s",alc);
					if(strcmp(alc,"S")==0){
						strcpy(B->alcoolico,alc);
						cmp_alc=1;
					}else if(strcmp(alc,"s")==0){
						strcpy(alc,"S");
						strcpy(B->alcoolico,alc);
						cmp_alc=1;
					}else if(strcmp(alc,"N")==0){
						strcpy(B->alcoolico,alc);
						cmp_alc=1;
					}else if(strcmp(alc,"n")==0){
						strcpy(alc,"N");
						strcpy(B->alcoolico,alc);
						cmp_alc=1;
					}else
						printf("\nInformação incorreta,Por favor repita:     ");

				}while(cmp_alc!=1);	
				B->next=NULL;
				B->prev=NULL;

				if(E->head==NULL){
					E->head=B;
					E->tail=B;
				}else
					E=cadastra_bebida(E,B);

				system("clear");
			break;

			case 2:
				system("clear");
				printf("\nLista de bebidas cadastradas\n\n");
				if(E->head!=NULL)
					listar_bebidas(E);
				else
					printf("\nLista de bebidas vazia!\n");
			break;

			case 3:
				system("clear");
				printf("\nLocalizar Bebida\n\n");
				if(E->head!=NULL){
					printf("Digite o codigo da bebida:    ");
					scanf("%d",&cod);
					aux=busca_bebida(E,cod);
				
					if(aux!=NULL)
						printf("\nCodigo: %d\t\tDesc: %s\t\tConteudo: %d\t\tPreço: %.2f\t\tEstoque: %d\t\t Alcoolica: %s\n",aux->cod,aux->desc,aux->conteudo,aux->preco,aux->qtd,aux->alcoolico);
					else
						printf("\nCodigo não encontrado!\n");
				}else
					printf("\nLista de bebidas vazia!\n");
			break;

			case 4:
				system("clear");
				printf("\nExcluir uma bebida\n\n");

				if(E->head!=NULL){
					printf("Digite o codigo da bebida à excluir:     ");
					scanf("%d",&cod);
					E=deletar_bebida(E,cod);
				}else
					printf("\nLista de bebidas Vazia\n");
			break;

			case 5:
				system("clear");
				printf("\nComprar Bebida\n\n");

				if(E->head!=NULL)
					E=comprar_bebida(E);
				else
					printf("\nLista de bebidas Vazia!\n");
			
			break;

			case 6:
				system("clear");
				printf("\nVender Bebida\n\n");
				if(E->head!=NULL){
					E=vender_bebida(E);
				}else{
					printf("\nLista de Bebidas Vazia!\n");
				}
			break;

			case 7:
				system("clear");
				printf("Saindo do sistema\nObrigado pela Preferência!\n");
				if(E->head!=NULL)
					fim_sistema(E);
			break;

			default:
				printf("\n Opção invalida! Digite novamente:    ");
			break;
		}
	}while(op!=7);

}