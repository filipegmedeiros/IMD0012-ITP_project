#include "headers.h"

int main(void) {
  int op=0;
  
  printf("\t MENU\n========================\nSelecione uma operaçao:\n[1]-Criar Tabela\n[2]-Imprimir Tabela\n");
  scanf("%d", &op);

  switch (op){
    case 1:
      criar_tabela(banco); 
      break;
    default:
      printf("opçao invalida.");
    
  }
 
  fclose(fp);
  return 0;
}