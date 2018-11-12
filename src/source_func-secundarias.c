#include "headers.h"
FILE *fp;
void procurar_dado(db* banco){
	printf("Under Construction");
}

void adicionar_id(char* endereco){
    
    
    printf("o caminho é %s",endereco);

  char* numero_id = (char*)malloc(24);
  fp = fopen(endereco,"a");

 printf("\n\n->Determine o ID da linha atual:\n");
 scanf("%s", numero_id);
 fprintf(fp, "%s,", numero_id);
 fprintf(fp,"\n");
 fclose(fp);

}

void adicionar_linha(db* banco){
	int qntd_lin=0, qntd_col=0;
  char elemento[50];

  printf("\n\n->Determine o nome da tabela: ");
  char* dir = (char*)malloc(24);
  scanf(" %s", dir);
  char* dir2 = (char*)malloc(24);
  strcpy(dir2,dir);

  char* nome_tabela = (char*)malloc(24);
  strcat(nome_tabela, "./data/banco/");
  strcat(dir,".csv");
  strcat(nome_tabela, dir);
  fp = fopen(nome_tabela,"a");
  fprintf(fp, "\n");

  //imprime_tabela(db* banco);
  //criando a pasta id
  char* ids = (char*)malloc(50);
  strcat(ids, "./data/ids/");
  strcat(dir2,".csv");
  strcat(ids, dir2);

  printf("\n\n->Determine o numero de colunas:\n");
  scanf("\t%d", &qntd_col);
  printf("\n\n->Quantos elementos deseja inserir?\n");
  scanf("%d", &qntd_lin);

  for(int j=0; j<qntd_lin; j++){
    for (int i = 0; i<qntd_col; i++){
     
      printf("Insira um elemento na coluna %d: ", i+1);
      scanf("%s", elemento);
      fprintf(fp, "%s,", elemento);
    }
    fprintf(fp, "\n");
    adicionar_id(ids);
  }
   fclose(fp);
}






void adicionar_coluna(db* banco){
	printf("Under Construction");
}
void deletar_dado(db* banco){
	printf("Under Construction");
}
void voltar_menu(){
	printf("Under Construction");
}



void opera_tabela(db* banco){
  printf("\
\n========================\n\
\t MENU\
\n========================\n\n\
Selecione uma operaçao:\n\
[1] - Procurar algum dado nessa tabela\n\
[2] - Adicionar uma nova linha\n\
[3] - Adicionar uma nova coluna\n\
[4] - Deletar algum dado nessa tabela\n\
[5] - Mostrar a tabela\n\
[6] - Voltar ao menu principal\n\
\n");

  int op2=0;
  scanf(" %d", &op2);
  printf("teste");


  switch (op2){
    case 1:
      procurar_dado(banco);
      printf("teste");
      break;
    case 2:
      adicionar_linha(banco);
      break;
    case 3:
      adicionar_coluna(banco);
        break;
    case 4:
      deletar_dado(banco);
        break;
    case 5:
      imprime_tabela(banco);
        break;
    case 6:
      voltar_menu();
        break;
    default:
      printf("opçao invalida.");
    
  }
}