#include "headers.h"

int main(void) {
  db *banco = malloc(sizeof(db));

  int op=0;


  printf("\
\n========================\n\
\t MENU FUNCIONAL \
\n========================\n\n\
Selecione uma operaçao:\n\
[1] - Criar uma nova tabela\n\
[2] - Imprimir tabela existente\n\
[3] - Sair do Programa\n\
\n");
 
  printf("\
\n========================\n\
\t MENU DESEJAVEL\
\n========================\n\n\
Selecione uma operaçao:\n\
[1] - Criar uma nova tabela\n\
[2] - Entrar em uma tabela existente\n\
[3] - Deletar uma tabela existente\n\
[4] - Mostrar todas as tabelas\n\
[5] - Sair do Programa\n\
\n");


/*  printf("\
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
\n");*/



  scanf("%d", &op);

  switch (op){
    case 1:
      criar_tabela(banco); 
      break;
    case 2:
      imprime_tabela(banco);
      break;
    case 3:
        //inserir_elementos(banco);
        break;
    default:
      printf("opçao invalida.");
    
  }
 
  fclose(fp);
  return 0;
}