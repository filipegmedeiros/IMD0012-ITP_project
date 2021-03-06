#include "headers.h"
FILE *fp;

void criar_tabela(db* banco){
    banco -> qntd_linhas = 0;

    // Determina o Nome da Tabela
    printf("\n\n->Determine o nome da tabela: ");
    char* dir = malloc(50);
    char* dir2 = malloc(50);
    char* dir3 = malloc(50);
    scanf(" %s", dir);

    strcpy(dir2,dir);
    strcpy(dir3,dir);

    char* nome_tabela = malloc(50);
    char* ids = malloc(50);
    char* qntid_colunas = malloc(50);

    strcpy(ids,nome_tabela);
    strcpy(qntid_colunas,nome_tabela);

    // Determina o caminho onde será salvo a Tabela
    strcat(nome_tabela, "./data/banco/");
    strcat(dir,".csv");
    strcat(nome_tabela, dir);

    strcat(ids, "./data/ids/");
    strcat(dir2,".csv");
    strcat(ids, dir2);

    strcat(qntid_colunas, "./data/qnt_cols/");
    strcat(dir3,".csv");
    strcat(qntid_colunas, dir3);

  
    // Determina a primeira chave Primaria
    printf("\n\n->Determine o nome da chave primaria: ");
    char* chave_primaria = malloc(24);
    scanf(" %s", chave_primaria);
    banco -> a_chave_primaria = chave_primaria;



    // Abre o arquivo ID e coloca na primeira linha a chave
    fp = fopen(ids,"wb");
    fprintf(fp,"%s,", banco -> a_chave_primaria);
    fprintf(fp, "\n");
    fclose(fp);


    // Cria as colunas no arquivo escolhido.
    printf("\n\n->Quantas colunas deseja criar? ");
    int qntd_col;
    scanf("\t%d", &qntd_col);

    // Adicona a um banco o numero de colunas que possui.
    banco -> qntd_colunas = qntd_col;
    fp = fopen(qntid_colunas,"wb");
    fprintf(fp,"%d,", banco -> qntd_colunas);
    fclose(fp);


    db_elementos *elem=(db_elementos*)malloc(sizeof(db_elementos)*qntd_col);
    banco -> elementos = elem;


    // Cria o arquivo com o nome escolhido para a tabela
    fp=fopen(nome_tabela,"wb");
    banco -> nome_da_tabela = nome_tabela;

    /*   char* tipo = (char*)malloc(24);
         for(int i=0; i< banco -> qntd_colunas; i++){
         printf("\n\n->Determine o tipo da coluna %d:\n[i]-Int\n[c]-Char\n[f]-Float\n[d]-Double\n[s]-String\n", i+1);
         scanf(" %s", tipo);
         banco -> o_tipo = tipo;
         fprintf(fp,"%s,", banco -> o_tipo);
         }*/

    for(int i = 0 ; i < banco -> qntd_colunas ; i++){
        printf("\n\n ->Qual o nome da Coluna %d ? ",i+1);
        char* nome_coluna = malloc(24);
        scanf("%s",nome_coluna);
        elem[i].nome_da_coluna = nome_coluna;
        fprintf(fp,"%s,", elem[i].nome_da_coluna);

    }



    for(int i = 0 ; i < banco -> qntd_colunas ; i++){
        free(elem[i].nome_da_coluna);

    }
    free(nome_tabela);
    //free(tamanho_campo);
    //free(nome_coluna);
    free(dir);
    free(elem);
    fclose(fp);

}

// Imprime a tabela escolhida
void imprime_tabela(db* banco){
    printf("\n\n->Qual o nome da tabela? ");
    char* dir = malloc(50);
    scanf(" %s", dir);

    char* nome_tabela = malloc(50);

    strcat(nome_tabela, "./data/banco/");
    strcat(dir,".csv");
    strcat(nome_tabela, dir);
    char c;
    banco -> nome_da_tabela = nome_tabela;
    printf("\n");
    fp = fopen(banco -> nome_da_tabela, "r");

    if (fp == NULL) {
        printf("Tabela não existe, por favor reinicie o processo!");
        //voltar_menu_primario();
    }


    c = fgetc(fp);


    while (c != EOF){ 
        printf ("%c", c); 
        c = fgetc(fp); 
    }
    printf("\n");

    free(dir);
    free(nome_tabela);
    //voltar_menu_primario();

}

void remove_tabela(db* banco){
    printf("\n\n->Qual o nome da tabela? ");
    char* dir = malloc(24);
    scanf(" %s", dir);

    char* nome_tabela = malloc(24);

    strcat(nome_tabela, "./data/banco/");
    strcat(dir,".csv");
    strcat(nome_tabela, dir);

    banco -> nome_da_tabela = nome_tabela;
    printf("\n");
    fp = fopen(banco -> nome_da_tabela, "r");
    int ret;
    ret = remove(banco -> nome_da_tabela);

    if(ret == 0) {
        printf("Deletado com Sucesso!\n");
    }else{
        printf("Error: Nâo existe o arquivo.");
    }

    //voltar_menu_primario();
}
