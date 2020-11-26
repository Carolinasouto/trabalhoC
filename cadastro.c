#include "anoAtual.c"

typedef struct{
	int dia, mes, ano;
}nascimento;

typedef struct{ 
		char nome[30];
        char cpf[11];
		int sex;
		char email[30];
		nascimento dtnasc;
		char tel[15];
		int cpfdep;
		int plan;
		char nomedep[30];
		int dtnascdep;
		float valorplano;
		int dtvencimento;
                
} Clientes;

Clientes cliente;

int contador = 0;

void inserir()
	{ 
	
	FILE *arq;
	arq = fopen("cliente.txt", "ab");
	
	while (1) {
		//VARIÁVEIS
		
		char resp;
	 
		printf("$$   NUCLEO DE SAUDE   $$\n\n");
		printf("\n\nCADASTRAR CLIENTE\n\n");//CADASTRO
		printf("\nCPF: ");
		gets(cliente.cpf);
		
		fflush(stdin);
		
		printf("\nNOME: ");
		gets(cliente.nome);
		
		SEXO:
		printf("\nSEXO(F/M): ");
		scanf("%c", &cliente.sex);
		fflush(stdin);
		if(cliente.sex != 'F' && cliente.sex != 'M'){
			printf("Opcao invalida!");
			goto SEXO;
		}
		
		printf("\nEMAIL: ");
		fflush(stdin);
    	gets(cliente.email);
    		 	   
    	printf("\nDATA DE NASCIMENTO: ");
    	fflush(stdin);
    	
		DIA:
		printf("\nDia: ");
    	scanf("%d", &cliente.dtnasc.dia);
    	
    	if(cliente.dtnasc.dia < 1 || cliente.dtnasc.dia > 31){
    		printf("Escolha um dia valido");
    		goto DIA;
		}
    	
    	MES:
		printf("Mes: ");
    	scanf("%d", &cliente.dtnasc.mes);
    	
    	if(cliente.dtnasc.mes < 1 || cliente.dtnasc.mes > 12){
    		printf("Escolha um mes valido\n");
    		goto MES;
		}
    	
		ANO:
		printf("Ano: ");
    	scanf("%d", &cliente.dtnasc.ano);
    	
    	int ano = anoAtual();
    	
		if(cliente.dtnasc.ano > ano || cliente.dtnasc.ano < (ano - 120)){
    		printf("\nEscolha um ano valido\n");
    		goto ANO;
		}
		   
    	printf("\nTELEFONE: ");
    	fflush(stdin);
    	gets(cliente.tel);
     	   
    		
		printf("\nEM QUAL PLANO O PACIENTE SERA CADASTRADO?\n");
		fflush(stdin);
		printf("\n1-OURO R$300,00");
    	printf("\n2-DIAMANTE R$400,00");
    	printf("\n3-PRATA R$200,00");
    	printf("\n4-ESMERALDA R$500,00\n");
		scanf("%d", &cliente.plan);
		fflush(stdin);
		
			
	fwrite(&cliente, sizeof(cliente), 1, arq);
	fclose(arq);
		
	contador++;
	
	printf("\nCliente Cadastrado com sucesso");
	
	ERRO:
	printf("\nDESEJA CADASTRAR OUTRO?: (S/N)? ");
	scanf("%c", &resp);
	if(resp == 'N'){
		break;
	}else if(resp != 'S'){
		printf("\nVocê nao escolheu uma opcao valida!");
		goto ERRO;
	}
	};
}
