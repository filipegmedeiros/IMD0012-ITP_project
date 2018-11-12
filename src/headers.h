#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

typedef struct elementos_do_banco{
    int ID;
    char* o_tipo;
    int field_Size;
    char* nome_da_coluna;
    char* tamanho_do_campo;
}db_elementos;

typedef struct banco_de_dados{
    char* a_chave_primaria;
    char* nome_da_tabela;
    char* nome_da_coluna;
    char* o_tipo;
    int qntd_linhas;
    int qntd_colunas;
    int tamanho_da_linha;
    int ID;

    db_elementos* elementos;

}db;

//header_global
void criar_tabela(db* banco);
void imprime_tabelas(db* banco);
void deletar_tabela(db* banco);

//header_op2
void opera_tabela(db* banco);
void procurar_dado(db* banco);
void adicionar_linha(db* banco);
void adicionar_coluna(db* banco);
void imprime_tabela(db* banco);
void deletar_dado(db* banco);
void imprime_tabela(db* banco);
void voltar_menu();