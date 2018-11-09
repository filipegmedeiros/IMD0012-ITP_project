#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

typedef struct elementos_do_banco{
    int ID;
    int field_Size;
    char* nome_da_coluna;
    char* tamanho_do_campo;
}db_elementos;

typedef struct banco_de_dados{
    char* chave_primaria;
    char* nome_da_tabela;
    char* nome_da_coluna;
    int qntd_linhas;
    int qntd_colunas;
    int tamanho_da_linha;
    int ID;
    db_elementos* elementos;

}db;

void criar_tabela(db* banco);

