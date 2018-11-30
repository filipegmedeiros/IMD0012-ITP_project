#include "headers.h"

FILE *fp;
void procurar_dado(db* banco){
    printf("Under Construction");
}

void adicionar_id(char* endereco){


    //    printf("o caminho é %s",endereco);

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
    char* dir = (char*)malloc(50);
    scanf(" %s", dir);
    char* dir2 = (char*)malloc(50);
    strcpy(dir2,dir);
    char* dir3 = (char*)malloc(50);
    strcpy(dir3,dir);

    char* nome_tabela = (char*)malloc(50);
    strcat(nome_tabela, "./data/banco/");
    strcat(dir,".csv");
    strcat(nome_tabela, dir);

    //imprime_tabela(db* banco);
    //criando a pasta id
    char* ids = (char*)malloc(50);
    char* qntid_colunas = (char*)malloc(50);

    strcat(ids, "./data/ids/");
    strcat(dir2,".csv");
    strcat(ids, dir2);

    strcat(qntid_colunas, "./data/qnt_cols/");
    strcat(dir3,".csv");
    strcat(qntid_colunas, dir3);
    char c[0];
    // Abre o arquivo das Colunas para saber a quantidade
    fp = fopen(qntid_colunas,"r");
    c[0] = fgetc(fp);
    printf("C: %s\n", c);
    // Dá um cast para transformar de char para int.
    qntd_col = strtol(c, NULL, 10);
    printf("qnt col: %d\n", qntd_col);
    fclose(fp);

    fp = fopen(nome_tabela,"a");
    fprintf(fp, "\n");


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
    //     voltar_menu_secundario();
    voltar_menu_secundario();
}





void adicionar_coluna(db* banco){
    int qntd_col=0;
    printf("\n\n->Determine o nome da tabela: ");
    char* dir = (char*)malloc(50);
    scanf(" %s", dir);
    char* dir3 = (char*)malloc(50);
    strcpy(dir3,dir);

    char* nome_tabela = (char*)malloc(50);
    strcat(nome_tabela, "./data/banco/");
    strcat(dir,".csv");
    strcat(nome_tabela, dir);

    char* qntid_colunas = (char*)malloc(50);

    strcat(qntid_colunas, "./data/qnt_cols/");
    strcat(dir3,".csv");
    strcat(qntid_colunas, dir3);
    char c[0];
    // Abre o arquivo das Colunas para saber a quantidade
    fp = fopen(qntid_colunas,"r");
    c[0] = fgetc(fp);
    printf("C: %s\n", c);
    // Dá um cast para transformar de char para int.
    qntd_col = strtol(c, NULL, 10);
    printf("qnt col: %d\n", qntd_col);
    fclose(fp);

    printf("\n\n->Quantas colunas deseja criar? ");
    int add_qntd_col, nova_qntd_col;
    scanf("\t%d", &add_qntd_col);
    nova_qntd_col = qntd_col + add_qntd_col;

    fp = fopen(qntid_colunas,"w");
    fprintf(fp,"%d,", qntd_col);
    fclose(fp);

    db_elementos *elem=(db_elementos*)malloc(sizeof(db_elementos)*qntd_col);

    // Abre o arquivo com o nome escolhido para a tabela
    char* nome_coluna = (char*)malloc(70);
    char* verificador = malloc(sizeof(char)*24);
    /* A partir daqui tá errado */
    for(int i = qntd_col ; i < nova_qntd_col ; i++){
        printf("\n\n ->Qual o nome da Coluna %d ? ",i+1);

        scanf("%s",nome_coluna);

        fp=fopen(nome_tabela,"r");

        while(fscanf(fp, "%[^,],", verificador) != EOF){
            if ( strncmp(verificador,nome_coluna,4) == 0){
                printf("Essa coluna já existe, digite outro nome por favor.");
            }
            fclose(fp);
        }
        fp=fopen(nome_tabela,"a");
        elem[i].nome_da_coluna = nome_coluna;
        fprintf(fp,"%s,", elem[i].nome_da_coluna);
        fclose(fp);





    }

    voltar_menu_secundario();
}
/* Até aqui */




//Ler o arquivo chaves_primarias e verifica se existe uma chave primaria igual
void testando_a_chave(){

    printf("\n\n->Determine o nome da tabela: ");
    char* dir = (char*)malloc(50);
    scanf(" %s", dir);
    char* dir2 = (char*)malloc(50);
    strcpy(dir2,dir);

    char* ids = (char*)malloc(50);
    strcat(ids, "./data/ids/");
    strcat(dir2,".csv");
    strcat(ids, dir2);

    int chaveok=0;
    while(!chaveok){
        printf("\n\n->Determine o número da chave: ");
        char* numero_chave = (char*)malloc(50);
        scanf(" %s", numero_chave);


        fp = fopen(ids,"r");
        char* verificador = malloc(sizeof(char)*24);


        while(fscanf(fp, "%[^,],", verificador) != EOF){
            if (strncmp(verificador,numero_chave, 20) == 0){
                printf("Essa chave está correta!\n");
                printf("verificador: %s", verificador);
                chaveok = 1;
                break;
            }
        }



    }

    fclose(fp);

}

void deletar_dado(db* banco){
    printf("Under Construction");
}



void opera_tabela(db* banco){
    printf("\
\n========================\n\
\t MENU DA TABELA\
\n========================\n\n\
Selecione uma operaçao:\n\
[1] - Procurar algum dado nessa tabela\n\
[2] - Adicionar uma nova linha\n\
[3] - Adicionar uma nova Coluna\n\
[4] - Deletar algum dado nessa tabela\n\
[5] - Mostrar a tabela\n\
[6] - Voltar ao menu principal\n\
            \n");

    int op2=0;
    scanf(" %d", &op2);


    switch (op2){
        case 1:
            procurar_dado(banco);
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
            voltar_menu_primario();
            break;
        default:
            printf("opçao invalida.");

    }
}

void exibir_menu(){
    db *banco = malloc(sizeof(db));

    int op=0;


    printf("\
\n========================\n\
\t MENU INICIAL \
\n========================\n\n\
Selecione uma operaçao:\n\
[1] - Criar uma nova tabela\n\
[2] - Operar uma tabela existente\n\
[3] - Imprimir tabela existente\n\
[4] - Apagar tabela existente\n\
[5] - Sair do Programa\n\
            \n");






    scanf("%d", &op);

    switch (op){
        case 1:
            criar_tabela(banco); 
            break;
        case 2:
            opera_tabela(banco);
            break;
        case 3:
            imprime_tabela(banco);
            break;
        case 4:
            remove_tabela(banco);
            break;
        default:
            printf("Adeus! \n");

    }
}

void voltar_menu_primario(){
    printf("\nDeseja Voltar ao menu Inicial? (s/S) ");
    char op5;
    scanf(" %c", &op5);

    if ( op5 == 's' || op5 == 'S' ){
        exibir_menu();
    }else{
        printf("\nObrigado por usar nosso programa!\n");
    }

}


void voltar_menu_secundario(){
    db *banco = malloc(sizeof(db));
    printf("\
\n==============================\n\
Para voltar aos Menus digite: \
\n==============================\n\n\
[1] - Voltar ao Menu da Tabela\n\
[2] - Voltar ao Menu Inicial\n\
[3] - Sair do Programa\n");

    int op5;
    scanf(" %d", &op5);

    switch (op5){
        case 1:
            opera_tabela(banco);
            break;
        case 2:
            exibir_menu(banco);
            break;
        case 3:
            break;
        default:
            printf("opçao invalida.");

    }

}



