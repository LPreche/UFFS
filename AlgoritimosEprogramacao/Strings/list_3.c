#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*----------------*/


struct pessoa{
   char nome[100];
   int telefone;
};

    int N_pessoas;
    int i;
int main(){

    char pes_nome[100];
    printf("Informe quantas pessoas voce deseja integrar a lista telefonica: \n");
    scanf("%d",&N_pessoas);
    struct pessoa lista_tel[N_pessoas];

    for(i=0;i<N_pessoas;i++){
        printf("Digite o nome da %dª pessoa: \n",(i+1));
        scanf("%s",lista_tel[i].nome);
        printf("Digite o telefone da %d pessoa: \n",(i+1));
        scanf("%d",&lista_tel[i].telefone);
    }

    printf("Digite o nome da pessoa para consulta: \t");
    scanf("%s",pes_nome);

    for(i=0;i<N_pessoas;i++){

        if(strcmp(lista_tel[i].nome,pes_nome)== 0){
                printf("\n Pessoa encontrada...\n");
                printf("Nome: %s\n",lista_tel[i].nome);
                printf("Telefone: %d",lista_tel[i].telefone);
                break;
           }else{
                printf("\n Pessoa Não encontrada...\n");
                printf("Nome: %s\n",pes_nome);
           }
    }

    return 0;
}
