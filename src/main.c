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
            [2] - Operar uma tabela existente\n\
            [3] - Imprimir tabela existente\n\
            [4] - Sair do Programa\n\
            \n");

    /*  printf("\
        \n========================\n\
        \t MENU DESEJAVEL\
        \n========================\n\n\
        Selecione uma operaçao:\n\
        [1] - Criar uma nova tabela\n\
        [2] - Entrar em uma tabela existente\n\
        [3] - Deletar uma tabela existente\n\
        [4] - Mostrar todas as tabelas\n\
        [5] - Sair do Programa\n\
        \n");*/




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
            printf("opçao invalida.");

    }
    return 0;
}
