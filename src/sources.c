#include "headers.h"
FILE *fp;

void criar_tabela(db* banco){
  banco -> qntd_linhas = 0;


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
     printf("\n\n ->Qual o nome da Coluna %d ? ",i+1);
     char* nome_coluna = (char*)malloc(24);
     scanf("%s",nome_coluna);
     elem[i].nome_da_coluna = nome_coluna;


  }
    char* dir = (char*)malloc(24);
    strcat(dir, "./data/");
    strcat(nome_tabela,".csv");
    strcat(dir, nome_tabela);

    fp=fopen(dir,"wb");


    free(nome_tabela);
    for(int i = 0 ; i < banco -> qntd_colunas ; i++){
        free(elem[i].nome_da_coluna);

    }
    free(nome_tabela);
    //free(tamanho_campo);
    //free(nome_coluna);
    free(dir);
    free(elem);

}
