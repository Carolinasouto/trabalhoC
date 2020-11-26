#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
 
typedef struct{ 
		
        int cpf;
		char nome[30];
		int sex;
		char email[30];
		int dtnasc;
		int tel;
		int cpfdep;
		char nomedep[30];
		int dtnascdep;
		float valorplano;
		int dtvencimento;
                
} TCliente;

FILE *pcliente;

TCliente cliente_aux, cliente_nulo;

int plano;

void cabec() {
system("cls");
printf("$$   NUCLEO DE SAUDE   $$\n\n");
}

void abre_arquivo()
{ 
	pcliente = fopen("cliente.txt", "a+b");
}

/*void valorPlano (int sex, int valorPlano, int qtdDependente, int i)

{
	if (qtdDependente >= 2)
    {
        cliente_aux.valorplano[i]-=(cliente_aux.valorplano[i] *20)/100;
    }
    else if (cliente_aux.idade >= 13)
    {
    	cliente_aux.valorplano[i]+=(cliente_aux.valorplano[i] *30)/100;
	}
    
    else if (cliente_aux.idade <= 35)
    {
    	cliente_aux.ValorPlano[i]+=(cliente_aux.valorplano[i] *30)/100;
	}
    
    else if (cliente_aux.idade < 13)
    {
        cliente_aux.valorplano[i]-=(cliente_aux.valorplano[i] *30)/100;
    }
    
	else if (cliente_aux.idade >= 60)
    {
    	cliente_aux.ValorPlano[i]+=(cliente_aux.valorplano[i] *40)/100;
	}
}  */ 
void inserir()
	{ 
	int resp;
	do { 
		cabec();
		printf("\n\nCADASTRAR CLIENTE\n\n");//CADASTRO
		printf("\nCPF: ");
		scanf("%d", &cliente_aux.cpf);
		
		printf("\nNOME: ");
		fflush(stdin);
		gets(cliente_aux.nome);
		
		printf("\nSEXO(1-F/2-M): ");
		scanf("%d", &cliente_aux.sex);
		
		printf("\nEMAIL: ");
		fflush(stdin);
    	gets(cliente_aux.email);
    		 	   
    	printf("\nDATA DE NASCIMENTO: ");
    	fflush(stdin);
    	scanf("%d", &cliente_aux.dtnasc);
     	   
    	printf("\nTELEFONE: ");
    	fflush(stdin);
    	scanf("%d", &cliente_aux.tel);
     	   
    	printf("\nCPF DEPENDENTE: ");
    	fflush(stdin);
    	scanf("%d", &cliente_aux.cpfdep);
    	    
    	printf("\nDIGITE NOME DEPENTENTE: ");
    	fflush(stdin);
    	gets(cliente_aux.nomedep);
     	   
    	printf("\nDATA DE NASCIMENTO DEPENDENTE: ");
    	fflush(stdin);
    	scanf("%d", &cliente_aux.dtnascdep);
	
		printf("\nEM QUAL PLANO O PACIENTE SERA CADASTRADO?\n");
		fflush(stdin);
		printf("\n1, 2, 3 ou 4\n");
		scanf("%d", &plano);
    
    	/*for (i = 0; i < plano)
		{
    		printf("\n\nQUAL O PLANO O CLIENTE SERA CADASTRADO?\n\n");
    		printf("\n\n1-OURO\n\n");
    		printf("\n\n2-DIAMANTE\n\n");
    		printf("\n\n3-PRATA\n\n");
    		printf("\n\n4-ESMERALDA\n\n");
    		
    		valorPlano (cliente_aux.plano[i],i);
		}*/
    		
	fseek(pcliente, 0, SEEK_END);
	fwrite(&cliente_aux, sizeof(TCliente), 1, pcliente);
	
	printf("\n\nCLIENTE CADASTRADO COM SUCESSO!\n\n");
	printf("\nDESEJA CADASTRAR OUTRO?: (1-S/0-N)? ");
	scanf("%d", &resp);
	}while (resp ==1);
}


/*int procura(int cpfp)
{ 
	int p;
	p = 0;
	rewind(pcliente);
	fread(&cliente_aux, sizeof(TCliente), 1, pcliente);
	while (feof(pcliente)==0)
	{
		if (cliente_aux.cpf == cpfp)
		return p;
	
			else
			{ 
				fread(&cliente_aux, sizeof(TCliente), 1, pcliente);
				p++;
			}
	}	
		return -1;
	}
	void mostre(int pos)
	{ 
		fseek(pcliente, pos*sizeof(TCliente), SEEK_SET);
		fread(&cliente_aux, sizeof(TCliente), 1, pcliente);
		printf("\n\n\n");
		printf("CPF      NOME            SEXO   \n\n");
		printf("%14d %-20s %8d \n\n", cliente_aux.cpf, cliente_aux.nome, cliente_aux.sex);
	}

	void consultar()//LISTAR POR PLANO
	{
		int resp, cpfcon, posicao;
		do
		{ 
		cabec();
		printf("\n\nCONSULTAR CLIENTE\n\n\n");
		printf("CPF: ");
		scanf("%d", &cpfcon);
		posicao = procura(cpfcon);
	
		if (posicao == -1)
		printf("\n\nCPF NAO ENCONTRADO!\n\n");
		else
		mostre(posicao);
		printf("\n\nDESEJA CONSULTAR OUTRO? (1-S/0-N)? ");
		scanf("%d", &resp);
		} 
		while (resp == 1);
		}
	void remover()//REMOVER CLIENTE
	{ 
		int cpfrem, conf, resp, posicao;
		cliente_nulo.cpf = 0;
		do
		{ 
			cabec();
			printf("\n\nREMOVER CLIENTE\n\n\n");
			printf("CPF: ");
			scanf("%d", &cpfrem);
			posicao = procura(cpfrem);
			if (posicao == -1)
				printf("\nCLIENTE NAO ENCONTRADO!!\a");
			else 
			{	 
				mostre(posicao);
				printf("\n\nDESEJA REMOVER O CLIENTE (1-S/0-N)? ");
				scanf("%d", &conf);
			if (conf == 1)
			{	 
				fseek(pcliente,posicao*sizeof(TCliente),SEEK_SET);
				fwrite ( &cliente_nulo, sizeof(TCliente), 1, pcliente);
				printf("\n\nCLIENTE REMOVIDO COM SUCESSO!");
			}
			else
				printf("\nREMOCAO CANCELADA!");
			}
	printf("\n\n\nDESEJA REMOVER OUTRO? (1-S/0-N)? ");
	scanf("%d", &resp);
	} while (resp ==1);
}
*/

void alterar()//EDITAR CLIENTE
{
	int cpfalt, conf, resp, posicao;
do 
	{
	cabec();
	printf("\n\nEDITAR CLIENTE\n\n\n");
	printf("CPF: ");
	scanf("%d", &cpfalt);
	posicao = procura(cpfalt);
	if (posicao == -1)
		printf("\nCLIENTE NAO ENCONTRADO!!\a");
			
	else
	{
		char novoNome[30],novoEmail[30];
		int novoCpf, novoSexo, novoDtnasc, novoTel;
		
		mostre(posicao);
		printf("\n\nEDITAR CLIENTE(1-S/0-N)? ");
		scanf("%d", &conf);
		if (conf == 1)
		{
			printf("\nO QUE DESEJA ALTERAR: \n");
			printf("\nCPF[1]\n");
			printf("\nNOME[2]\n");
			printf("\nSEXO[3]\n");
			printf("\nEMAIL[4]\n");
			printf("\nDATA DE NASCIMENTO[5]/n");
			printf ("\nTELEFONE[6]\n");
			scanf("%i", &resp);
			if (resp == 1)
			
			printf("\nNOVO CPF: ");
			scanf("%d", &cliente_aux.cpf);
			printf("\nNOVO NOME: ");
			scanf("%c", &cliente_aux.nome);
			printf("\nNOVO SEXO: ");
			scanf("%d", &cliente_aux.sex);
			printf("\nNOVO EMAIL: ");
			scanf("%d", &cliente_aux.email);
			printf("\nNOVA DATA DE NASCIMENTO: ");
			scanf("%d", &cliente_aux.dtnasc);
			printf("\nNOVO TELEFONE: ");
			scanf("%d", &cliente_aux.tel);
			
			printf("\nDADOS ALTERADOS COM SUCESSO! \n\n");
			fseek(pcliente,posicao*sizeof(TCliente),SEEK_SET);
			fwrite(&cliente_aux,sizeof(TCliente), 1,pcliente);
			mostre(posicao);
			printf("\nDADOS ALTERADOS COM SUCESSO!\n");
		}
	else
		printf("\n\nALTERACAO CANCELADA!\n\n");
	}
	printf("\n\nDESEJA ALTERAR OUTRO(1-S/0-N)? ");
	scanf("%d", &resp);
}
	while (resp ==1);
}
	void listagem()
{ 
	cabec();
	printf("\n\nLISTAGEM GERAL\n\n\n\n");
	printf("\n\nCPF         NOME                   SEXO  FONE         EMAIL                   IDADE  PLANO  DEPENDENTE                 VALOR PLANO    VENCIMENTO DO PLANO   \n\n");
	rewind(pcliente);
	fread(&cliente_aux, sizeof(TCliente), 1, pcliente);

while(feof(pcliente)==0)
	{ 
	if (cliente_aux.cpf != 0)
	printf("%9i %-20s \n", cliente_aux.cpf, cliente_aux.nome);
	fread(&cliente_aux, sizeof(TCliente), 1, pcliente);
	}

	printf("\nTECLE ENTER PARA VOLTAR AO MENU!");
	getche();
}

main()
{ 
	int menu;
	abre_arquivo();
do	{ 
	cabec();
	printf("\n\nMENU: \n\n\n");
	printf("1- CADASTRAR CLIENTE\n\n");
	printf("2- REMOVER CLIENTE\n\n");
	printf("3- CONSULTAR CLIENTE POR CPF\n\n");
	printf("4- EDITAR CLIENTE\n\n");
	printf("5- LISTAGEM GERAL\n\n");
	printf("0- SAIR\n\n\n");
	printf("INFORME A OPCAO DESEJADA: ");
	scanf("%d", &menu);
	
switch(menu)
		{ 
		case 1: inserir(); break;
		case 2: remover(); break;
		case 3: consultar(); break;
		case 4: alterar(); break;
		case 5: listagem(); break;
		case 0: fclose(pcliente); break;
		default: printf("\n\n\aOPCAO INVALIDA!");
		break;
		}
	} 
	while (menu != 0);
}
