#include "headers.h"
FILE *fp;
void procurar_dado(db* banco){
    printf("Under Construction");
}

void adicionar_id(char* endereco){


    printf("o caminho é %s",endereco);

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

    char* nome_tabela = (char*)malloc(50);
    strcat(nome_tabela, "./data/banco/");
    strcat(dir,".csv");
    strcat(nome_tabela, dir);
    fp = fopen(nome_tabela,"a");
    fprintf(fp, "\n");

    //imprime_tabela(db* banco);
    //criando a pasta id
    char* ids = (char*)malloc(50);
    strcat(ids, "./data/ids/");
    strcat(dir2,".csv");
    strcat(ids, dir2);

    printf("\n\n->Determine o numero de colunas:\n");
    scanf("\t%d", &qntd_col);
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
    voltar_menu_secundario();
}


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

void adicionar_coluna(db* banco){
    printf("Under Construction");
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
[3] - Editar a linha\n\
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
            testando_a_chave();
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
[4] - Sair do Programa\n\
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



