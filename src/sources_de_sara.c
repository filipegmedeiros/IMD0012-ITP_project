#include "funcs.h"

FILE *fp;

void inserir_elementos(int qntd_col, int qntd_lin){
  char elemento[50];

  fprintf(fp, "\n");
  for(int j=0; j<qntd_lin; j++){
    for (int i = 0; i < qntd_col; i++){
      printf("Insira um elemento na coluna %d: ", i+1);
      scanf("%s", elemento);
      if(i==0){
        fprintf(fp, "%d,",j); //preenche chave primaria
      }
      fprintf(fp, "%s,", elemento);
    }
    fprintf(fp, "\n");
  }
}

void criar_coluna(int qntd_col){
  char titulo[20], tipo;

  printf("\n\n->Determine o nome da chave primaria:");
  scanf("%s", titulo);
  fprintf(fp,"%s,", titulo);

  for(int i=0; i<qntd_col; i++){
    printf("\n\n->Determine o titulo da coluna:");
    scanf("%s", titulo);
    fprintf(fp,"%s,", titulo);
  } 
  
  fprintf(fp, "\n");
  fprintf(fp, "i,"); //tipo da coluna ID
  
  for(int i=0; i<qntd_col; i++){
    printf("\n\n->Determine o tipo da coluna %d:\n[i]-Int\n[c]-Char\n[f]-Float\n[d]-Double\n[s]-String\n", i+1);
    scanf("\n%c", &tipo);
    fprintf(fp,"%c,", tipo);
  }
}

void criar_tabela(){
  fp = fopen("database.csv", "a");
  char nome_tabela[50];
  int qntd_lin, qntd_col;
  printf("\n\n->Determine o nome da tabela: ");
  scanf("%s", nome_tabela);
  fprintf(fp, "\n%s,\n", nome_tabela);

  
  printf("\n\n->Quantas colunas deseja criar?");
  scanf("\t%d", &qntd_col);

  criar_coluna(qntd_col);
  
  printf("\n\n->Quantos elementos deseja inserir?\n");
  scanf("%d", &qntd_lin);

  inserir_elementos(qntd_col, qntd_lin);
}

void imprime_tabela(){
  char c;
  fp = fopen("database.csv", "r");
  c = fgetc(fp);
  
  while (c != EOF){ 
    printf ("%c", c); 
    c = fgetc(fp); 
  }

}