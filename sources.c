#include "headers.h"
FILE *fp;

void criar_tabela(db* banco){
  banco -> qntd_linhas = 0;


  char* nome_da_coluna;

  printf("\n\n->Determine o nome da tabela: ");
  char* nome_tabela = (char*)malloc(24);

  scanf("%s", nome_tabela);
  banco -> nome_da_tabela = nome_tabela;


  
  printf("\n\n->Quantas colunas deseja criar? ");
  int qntd_col;
  scanf("\t%d", &qntd_col);
  banco -> qntd_colunas = qntd_col;
  db_elementos *elem=(db_elementos*)malloc(sizeof(db_elementos)*qntd_col);
  banco -> elementos = elem;

  for(int i = 0 ; i < banco -> qntd_colunas ; i++){
     printf("%d \n\n ->Qual o nome da Coluna",i,"? ");
     char* nome_coluna = (char*)malloc(24);
     scanf("%s",nome_da_coluna);
     elem[i].nome_da_coluna = nome_coluna;

     printf("%d \n\n ->Qual o tamanho do campo da Coluna ",i,"? ");
     char* tamanho_campo = (char*)malloc(24);
     elem[i].tamanho_do_campo=tamanho_campo;
     elem[i].ID=1;

  }
  int x = strlen(nome_tabela);
    nome_tabela[x]='.';
    nome_tabela[x+1]='c';
    nome_tabela[x+2]='s';
    nome_tabela[x+3]='v';
    nome_tabela[x+4]='\0';
    fp=fopen(nome_tabela,"wb");


    free(nome_tabela);
    for(int i = 0 ; i < banco -> qntd_colunas ; i++){
        free(elem[i].nome_da_coluna);

    }
    free(elem);

}
