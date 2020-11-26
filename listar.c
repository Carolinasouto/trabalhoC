
void mostrar(){
  FILE *arq;
  arq = fopen("cliente.txt", "ab");
  fseek(arq, sizeof(arq), SEEK_SET);
  fread(arq, sizeof(arq), 1, arq);
  printf("\n\n\n");
  printf("CPF      NOME            SEXO   \n\n");
  printf("%14d %-20s %8d \n\n", cliente.cpf, cliente.nome, cliente.sex);

}
