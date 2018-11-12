#include "headers.h"
FILE *fp;
void procurar_dado(db* banco){
	printf("Under Construction");
}

void adicionar_linha(db* banco){
	printf("Under Construction");
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