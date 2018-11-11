#include "headers.h"
FILE *fp;

void criar_tabela(db* banco){
    banco -> qntd_linhas = 0;

// Determina o Nome da Tabela
    printf("\n\n->Determine o nome da tabela: ");
    char* dir = (char*)malloc(24);
    scanf(" %s", dir);

    char* nome_tabela = (char*)malloc(24);

// Determina o caminho onde será salvo a Tabela
    strcat(nome_tabela, "./data/banco/");
    strcat(dir,".csv");
    strcat(nome_tabela, dir);

// Determina a chave Primaria
    printf("\n\n->Determine o nome da chave primaria: ");
    char* chave_primaria = (char*)malloc(24);
    scanf(" %s", chave_primaria);
    banco -> a_chave_primaria = chave_primaria;

// Abre o arquivo chaves_primarias e adiciona a ela a Chave
    fp=fopen("./data/chaves_primarias.csv","a");
    fprintf(fp,"%s,", banco -> a_chave_primaria);
    fclose(fp);
// Aqui ele tá substituindo a M0x0 pela key... A ideia era adicionar na proxima col

/*
02) Falta Verificar se existe a chave na tabela chaves_primarias
*/

// Abre o arquivo ids e adiciona a ela um ID
    fp=fopen("./data/ids.csv","wb");
    int id = 1;
    fprintf(fp,"%d,", id);
    id++;
    fclose(fp);
// aqui nem ta funcionando ainda 




    fp=fopen(nome_tabela,"wb");
    banco -> nome_da_tabela = nome_tabela;

    fprintf(fp,"%s,", banco -> a_chave_primaria);




    printf("\n\n->Quantas colunas deseja criar? ");
    int qntd_col;
    scanf("\t%d", &qntd_col);
    banco -> qntd_colunas = qntd_col;
    db_elementos *elem=(db_elementos*)malloc(sizeof(db_elementos)*qntd_col);
    banco -> elementos = elem;

 /*   char* tipo = (char*)malloc(24);
    for(int i=0; i< banco -> qntd_colunas; i++){
        printf("\n\n->Determine o tipo da coluna %d:\n[i]-Int\n[c]-Char\n[f]-Float\n[d]-Double\n[s]-String\n", i+1);
        scanf(" %s", tipo);
        banco -> o_tipo = tipo;
        fprintf(fp,"%s,", banco -> o_tipo);
    }*/

    for(int i = 0 ; i < banco -> qntd_colunas ; i++){
        printf("\n\n ->Qual o nome da Coluna %d ? ",i+1);
        char* nome_coluna = (char*)malloc(24);
        scanf("%s",nome_coluna);
        elem[i].nome_da_coluna = nome_coluna;
        fprintf(fp,"%s,", elem[i].nome_da_coluna);

    }


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

void imprime_tabela(db* banco){
    printf("\n\n->Qual o nome da tabela? ");
    char* dir = (char*)malloc(24);
    scanf(" %s", dir);

    char* nome_tabela = (char*)malloc(24);

    strcat(nome_tabela, "./data/");
    strcat(dir,".csv");
    strcat(nome_tabela, dir);
    char c;
    banco -> nome_da_tabela = nome_tabela;
    printf("\n");
    fp = fopen(banco -> nome_da_tabela, "r");
    c = fgetc(fp);

    while (c != EOF){ 
        printf ("%c", c); 
        c = fgetc(fp); 
    }
    printf("\n");
}
