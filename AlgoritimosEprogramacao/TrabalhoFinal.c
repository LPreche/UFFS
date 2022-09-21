#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct veiculo{
    int codigo;
	char placa[8];
	char modelo[51];
	int ano;
	int estado;
	int cliente;
	int km;
	int filia;
};
struct cliente{
    char prim_nome[100];
    char sobrenome[100];
    int cpf[11];
    int codigo_cliente;
    char senha[7];
    char endereco[100];
};
struct filial{
    int codigo;
    char nome[100];
    char cidade[100];
    char endereco[100];
};
struct cliente lista_clientes[100];
struct veiculo lista_veiculos[100];
struct filial lista_filiais[100];

/*Definição de variaveis globais*/
int j=0,i=0;

int resulta_cpf;
/*variaveis para controle*/
int cod_veic=0,cod_clie=1,cod_filial=0;
int verifica_cpf();
void devolucao_veiculo();
/*Difinindo inicio no codigo*/


/**/
int main(int argc, char *argv[]) {

    setlocale(LC_ALL, "portuguese");

	int opcao,sair=0;
	/*inicio do Laço para sempre aparecer o Menu */
	do{
	/*"Design" do Menu principal*/

	printf("\n");
	printf("\t\t\t+-------------------------+\n");
	printf("\t\t\t|  Rent - A - Kr System   |\n");
	printf("\t\t\t+-------------------------+\n");
	printf("\t\t\t|  1- Cadastrar Cliente   |\n");
	printf("\t\t\t|  2- Cadastrar Veículo   |\n");
	printf("\t\t\t|  3- Locar Veículo       |\n");
	printf("\t\t\t|  4- Cadastrar filiais   |\n");
	printf("\t\t\t|  5- Transferir Veículo  |\n");
	printf("\t\t\t|  6- Devolução de Veículo|\n");
	printf("\t\t\t|  7- Sair        	  |\n");
	printf("\t\t\t+-------------------------+\n");


		printf("\n\t\t\t   Sua Escolha : ");
		scanf("%d",&opcao);
		switch(opcao){
			case 1:
                system("clear");
                cadastro_cliente();
                cod_clie++;
			break;

			case 2:
			    system("clear");
				if(cod_filial !=0 ){
				cadastro_veiculo();
				}else{
                    printf("\n\t\t\t primeiramente faça o cadastro de uma filial!!\n\n");
				}
				cod_veic++;
			break;

			case 3:
			    system("clear");
				loca_veiculo();
			break;

			case 4:
			    system("clear");
			    cadastro_filial();
				cod_filial++;
			break;


			case 5:
			     system("clear");
			     movimentar_carro();
		        break;

			case 6:
				system("clear");
				devolucao_veiculo();
			break;

			case 7:
				sair++;
			break;
		}
	}while(sair!=1);

	return 0;
}



void cadastro_veiculo(){

	printf("\n\t\t\t Bem Vindo ao cadastro de Veiculos \n\n");
	printf("\n\t\t\t +---------------------------------+\n\n");
	printf("\n\t\t\t Digite o codigo da filial que este veiculo está: ");
	scanf("%d",&lista_veiculos[cod_veic].filia);
	printf("\n\t\t\t Digite a placa do Veiculo: ");
    scanf("%s",lista_veiculos[cod_veic].placa);
	printf("\n\t\t\t Digite o modelo do veiculo: ");
	getchar();
    gets(lista_veiculos[cod_veic].modelo);
	printf("\n\t\t\t Digite o ano de fabricação do veiculo: ");
    scanf("%i",&lista_veiculos[cod_veic].ano);
	printf("\n\t\t\t Estado do veiculo (1-locado 0-Disponivel): ");
    scanf("%d",&lista_veiculos[cod_veic].estado);
	printf("\n\t\t\t Quilometragem atual do veiculo(KM): ");
    scanf("%i",&lista_veiculos[cod_veic].km);
    system("clear");
    printf("\n\t\t\t Veiculo inserido com sucesso!!!");
    printf("\n\t\t\t Informações Inseridas: \n");
    printf("\n\t\t\t Placa: %s",lista_veiculos[cod_veic].placa);
    printf("\n\t\t\t Modelo: %s",lista_veiculos[cod_veic].modelo);
    printf("\n\t\t\t Ano: %i",lista_veiculos[cod_veic].ano);
    if(lista_veiculos[cod_veic].estado == 0){
       printf("\n\t\t\t Estado: Disponivel");
    }else{
       printf("\n\t\t\t Estado: Locado");
    }
    printf("\n\t\t\t Quilometragem atual: %i KM",lista_veiculos[cod_veic].km);
    printf("\n");

}

void cadastro_cliente(){
int cont_digitos=0,tamanho;
    lista_clientes[cod_clie].codigo_cliente = cod_clie;
    printf("\n\t\t\t Bem Vindo ao cadastro de Cliente \n\n");
    printf("\n\t\t\t +---------------------------------+\n\n");
    printf("\n\t\t\t Digite seu primeiro nome: ");
    getchar();
    gets(lista_clientes[cod_clie].prim_nome);
    printf("\n\t\t\t Digite seu sobrenome: ");
    gets(lista_clientes[cod_clie].sobrenome);
    printf("\n\t\t\t Digite seu CPF: \n");
    printf("\t\t\t\ OBS:Insira um espaço após cada numero:  ");
    printf("\n\t\t\t ");
    /*Inserção e verificação do CPF*/
    do{
        for(i=0;i<11;i++){

            scanf("%d",&lista_clientes[cod_clie].cpf[i]);

            if(lista_clientes[cod_clie].cpf[i] > 9){
                printf("\n\t\t\t Digito Invalido! Insira um digito valido de 0 a 9: ");
                scanf("%d",&lista_clientes[cod_clie].cpf[i]);
            }
        }
        resulta_cpf = verifica_cpf();
        if(resulta_cpf == 1){
            printf("\n\t\t\t CPF valido! Continuando cadastro...\n");
            break;
        }else{
            printf("\n\t\t\t CPF Invalido! Tente Novamente...\n");
        }

    }while(1==1);
    /**/
    /*senha para terminal remoto*/

    printf("\n\t\t\t Digite uma senha com até 6 caracteres: ");
    scanf("%s",lista_clientes[cod_clie].senha);
    /**/
    printf("\n\t\t\t Digite seu endereco: ");
    getchar();
    gets(lista_clientes[cod_clie].endereco);

    system("clear");
    printf("\n\t\t\t Cliente cadastrado com sucesso!! \n\n");
    printf("\n\t\t\t Informacoes inseridas: \n");
    printf("\n\t\t\t Seu codigo de cliente e: %d",lista_clientes[cod_clie].codigo_cliente);
    printf("\n\t\t\t Nome Completo: %s%s",lista_clientes[cod_clie].prim_nome, lista_clientes[cod_clie].sobrenome);
    printf("\n\t\t\t cpf: ");
    for(i=0;i< 11;i++){
        printf("%d",lista_clientes[cod_clie].cpf[i]);
    }
    printf("\n\t\t\t endereco: %s", lista_clientes[cod_clie].endereco);


}

int verifica_cpf(){
    int total,total2,d1,d2,d3,d4,d5,d6,d7,d8,d9,dv1,dv2,v1,v2;

    d1=lista_clientes[cod_clie].cpf[0];
    d2=lista_clientes[cod_clie].cpf[1];
    d3=lista_clientes[cod_clie].cpf[2];
    d4=lista_clientes[cod_clie].cpf[3];
    d5=lista_clientes[cod_clie].cpf[4];
    d6=lista_clientes[cod_clie].cpf[5];
    d7=lista_clientes[cod_clie].cpf[6];
    d8=lista_clientes[cod_clie].cpf[7];
    d9=lista_clientes[cod_clie].cpf[8];
    dv1=lista_clientes[cod_clie].cpf[9];
    dv2=lista_clientes[cod_clie].cpf[10];

    /*Conta Primeiro Verificador*/
    total = ((d1*10)+(d2*9)+(d3*8)+(d4*7)+(d5*6)+(d6*5)+(d7*4)+(d8*3)+(d9*2));
    total = total % 11;
    if(total <2){
        v1 = total;
    }else{
        v1 = 11 - total;
    }

    /*Conta Segundo Verificador*/
    total2 = ((d1*11)+(d2*10)+(d3*9)+(d4*8)+(d5*7)+(d6*6)+(d7*5)+(d8*4)+(d9*3)+(v1*2));
    total2 = total2 % 11;
    if(total2 < 2){
        v2 = total2;
    }else{
        v2 = 11 - total2;
    }
    /*COMPARADOR*/
    if((v1 == dv1)&&(v2 == dv2)){
        resulta_cpf = 1;
    }else{
        resulta_cpf = 0;
    }
    return resulta_cpf;

}


void loca_veiculo(){
    char placa_veiculo[8];
    int exist,aux_cod,opcao,pesq,pesq2;

    printf("\n\t\t\t Bem Vindo a locação de veiculos \n\n");
    printf("\n\t\t\t +------------------------------+\n\n");

    printf("\n\t\t\t Primeiramente digite a placa do veiculo(sem traço): ");
    scanf("%s",placa_veiculo);

    for(pesq=0;pesq<100;pesq++){
        if(strcmp(lista_veiculos[pesq].placa,placa_veiculo) == 0){
            exist = 0;
            if(lista_veiculos[pesq].estado == 0){
                exist++;
            }
            break;
        }else{
            exist = 0;
        }
    }
    if(exist == 1){
        printf("\n\t\t\t Veiculo disponivel para locacao!\n");
            printf("\n\t\t\t +------------------------------+\n");
            printf("\n\t\t\t |  Deseja locar este veiculo?  |\n");
            printf("\n\t\t\t +------------------------------+\n");
            printf("\n\t\t\t |  1-sim             2-nao     |\n");
            printf("\n\t\t\t +------------------------------+\n");
            printf("\n\t\t\t Sua Opção: ");
            scanf("%d",&opcao);
                if(opcao == 1){
                   printf("\n\t\t\t Digite o codigo do cliente: ");
                   scanf("%d",&aux_cod);
                   lista_veiculos[pesq].cliente = aux_cod;
                   lista_veiculos[pesq].estado = 1;
                   printf("\n\t\t\t Veiculo locado com sucesso!!\n");
                   }


        }else{
            printf("\n\t\t\t Veiculo já locado ou inexistente!!");
        }

}

int cadastro_filial(){

    printf("\n\t\t\t Bem vindo ao cadastro de filial");
    printf("\n\t\t\t +-----------------------------+\n");
    lista_filiais[cod_filial].codigo = cod_filial;
    printf("\n\t\t\t Digite o nome da filial: ");
    getchar();
    gets(lista_filiais[cod_filial].nome);
    printf("\n\t\t\t Digite a cidade da filial: ");

    gets(lista_filiais[cod_filial].cidade);
    printf("\n\t\t\t Digite o endereço da filial: ");

    gets(lista_filiais[cod_filial].endereco);
    system("clear");
    printf("\n\t\t\t Cadastro da filial efetuado com sucesso!!\n\n");
    printf("\n\t\t\t Informacoes inseridas: \n");
    printf("\n\t\t\t Codigo da filial: %d", lista_filiais[cod_filial].codigo);
    printf("\n\t\t\t Nome da filial: %s", lista_filiais[cod_filial].nome);
    printf("\n\t\t\t Cidade da filial: %s", lista_filiais[cod_filial].cidade);
    printf("\n\t\t\t Endereco da filial: %s\n", lista_filiais[cod_filial].endereco);
}

void movimentar_carro(){
    int exist=0,pesq,opcao_mov, opcao_mov2,cod_orig,cod_dest,cod_veiculo;

    char placa_vei[8];
    printf("\n\t\t\t Bem vindo à transferência de veiculo");
    printf("\n\t\t\t +----------------------------------+\n\n");
    printf("\n\t\t\t Digite a placa do veículo: ");
    scanf("%s",placa_vei);

    for(pesq=0;pesq<100;pesq++){
        if(strcmp(lista_veiculos[pesq].placa,placa_vei) == 0){
            exist = 0;
            if(lista_veiculos[pesq].estado == 0){
                exist++;
            }
            break;
        }else{
            exist = 0;
        }
    }
    if(exist == 1){
        printf("\n\t\t\t Deseja transferir este veículo? (1 - SIM | 2 - NÃO)");
        scanf("%d",&opcao_mov);

        if(opcao_mov == 1){
            printf("\n\t\t\t Digite o código da filial destino: ");
            scanf("%d",&cod_dest);
            printf("\n\t\t\t Você deseja transferir o veículo? (1 - SIM | 2 - NÃO)  ");
            scanf("%d",&opcao_mov2);
            if(opcao_mov2 == 1){
                lista_veiculos[pesq].filia = cod_dest;
                printf("\n\t\t\t Veiculo transferido para %s com sucesso!!!\n",lista_filiais[cod_dest].nome);
            }
        }
    }else{
	printf("\n\t\t\t Veiculo inexistente ou locado");
    }
}

void devolucao_veiculo(){
    int exist=0, pesq, opcao_mov, opcao_dev, cod_veiculo, cod_filial;
    char  placa_veicu[8];

    printf("\n\t\t\t Bem Vindo ao Devolução de Veículos \n\n");
    printf("\n\t\t\t +---------------------------------+\n\n");
    printf("\n\t\t\t Digite a placa do seu veículo que está locado: ");
    getchar();
    gets(placa_veicu);

     for(pesq = 0; pesq < 100; pesq++){
        if(strcmp(lista_veiculos[pesq].placa,placa_veicu) == 0){
            exist = 0;
            if(lista_veiculos[pesq].estado == 1){
                exist++;
            }
            break;
        }else{
            exist = 0;
        }
    }

    if(exist == 1){
        printf("\n\t\t\t Deseja devolver este veículo? (1 - SIM | 2 - NÃO): ");
        scanf("%i", &opcao_dev);
        if(opcao_dev == 1){
            printf("\n\t\t\t Informe em qual filial foi devolvido o veículo: ");
            scanf("%i", &cod_filial);
            lista_veiculos[pesq].filia = cod_filial;
            lista_veiculos[pesq].cliente = 0;
            lista_veiculos[pesq].estado = 0;
            printf("\n\t\t\t Veiculo devolvido na filial %s com sucesso!!!",lista_filiais[cod_filial].nome);
        }
    }
    else{
        printf("\n\t\t\t Veiculo locado ou inexistente!!!\n");
	}
}
