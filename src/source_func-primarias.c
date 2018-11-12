#include "headers.h"
FILE *fp;

void criar_tabela(db* banco){
    banco -> qntd_linhas = 0;

// Determina o Nome da Tabela
    printf("\n\n->Determine o nome da tabela: ");
    char* dir = (char*)malloc(50);
    char* dir2 = (char*)malloc(50);
    scanf(" %s", dir);
    strcpy(dir2,dir);
    char* nome_tabela = (char*)malloc(50);
    char* ids = (char*)malloc(50);
    strcpy(ids,nome_tabela);
// Determina o caminho onde será salvo a Tabela
    strcat(nome_tabela, "./data/banco/");
    strcat(dir,".csv");
    strcat(nome_tabela, dir);

    strcat(ids, "./data/ids/");
    strcat(dir2,".csv");
    strcat(ids, dir2);

    printf("%s",ids);
// Determina a primeira chave Primaria
    printf("\n\n->Determine o nome da chave primaria: ");
    char* chave_primaria = (char*)malloc(24);
    scanf(" %s", chave_primaria);
    banco -> a_chave_primaria = chave_primaria;

    int aux = 0;

//Ler o arquivo chaves_primarias e verifica se existe uma chave primaria igual
void testando_a_chave(){
    aux = 0;
    fp=fopen("./data/chaves_primarias.csv","r");
    char* verificador = malloc(sizeof(char)*24);
    while(fscanf(fp, "%[^,],", verificador) != EOF){
    if ( strncmp(verificador,chave_primaria,4) == 0){
	printf("Essa chave já existe, por favor, escolha outra.");
	aux = 1;
	break;
	} else {
	   continue;
        }
    }
    fclose(fp);
}
testando_a_chave();

if ( aux == 0 ){
    fp=fopen("./data/chaves_primarias.csv","wb");
    fprintf(fp,"%s,", chave_primaria);
    fclose(fp);
} else{
    printf("\n\n->Determine o novo nome da chave primaria: ");
    scanf(" %s", chave_primaria);
    testando_a_chave();
}

// Abre o arquivo ID e coloca na primeira linha a chave
        fp = fopen(ids,"wb");
        fprintf(fp,"%s,", banco -> a_chave_primaria);
        fprintf(fp, "\n");
        fclose(fp);

// Cria o arquivo com o nome escolhido para a tabela
    fp=fopen(nome_tabela,"wb");
    banco -> nome_da_tabela = nome_tabela;

    //fprintf(fp,"%s,", banco -> a_chave_primaria);



// Cria as colunas no arquivo escolhido.
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
    fclose(fp);


}

// Imprime a tabela escolhida
void imprime_tabela(db* banco){
    printf("\n\n->Qual o nome da tabela? ");
    char* dir = (char*)malloc(24);
    scanf(" %s", dir);

    char* nome_tabela = (char*)malloc(24);

    strcat(nome_tabela, "./data/banco/");
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
