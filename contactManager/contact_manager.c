/**
 * @file contact_manager.c
 * @brief Implementação do gerenciador de contatos usando arquivos binários.
 *
 * Funções para inicialização, inserção, edição, exclusão, listagem,
 * contagem e liberação de contatos armazenados em disco.
 *
 * @author Danilo Côrtes Gonçalves
 * @date 22/06/2025
 */

#include "contact_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Ponteiro para o arquivo binário do banco de dados
static FILE *db = NULL;

/**
 * @brief Inicializa o banco de dados.
 * Abre o arquivo binário de contatos para leitura e escrita. 
 * Se não existir, ele será criado.
 */
void cm_init(void) {
    db = fopen(DATABASE_FILE, "r+b");
    if (!db) db = fopen(DATABASE_FILE, "w+b");
}

/**
 * @brief Fecha o banco de dados.
 * Deve ser chamado ao final da execução.
 */
void cm_close(void) {
    if (db) fclose(db);
}

/**
 * @brief Retorna a quantidade total de registros no banco.
 * @return Quantidade de contatos armazenados.
 */
static size_t total_records(void) {
    fseek(db, 0, SEEK_END);
    return ftell(db) / sizeof(Contact);
}

/**
 * @brief Adiciona um novo contato ao banco.
 * @param c Ponteiro para o contato a ser adicionado.
 * @return O contato adicionado com ID atribuído.
 */
Contact cm_add_contact(const Contact *c) {
    Contact newc = *c;
    size_t total = total_records();
    newc.id = (int)total + 1;
    fseek(db, 0, SEEK_END);
    fwrite(&newc, sizeof(Contact), 1, db);
    fflush(db);
    return newc;
}

/**
 * @brief Edita um contato existente com base no ID.
 * @param id ID do contato a ser editado.
 * @param c Novo conteúdo do contato.
 * @return 1 se editado com sucesso, 0 caso contrário.
 */
int cm_edit_contact(int id, const Contact *c) {
    rewind(db);
    Contact tmp;
    size_t i = 0;
    while (fread(&tmp, sizeof(tmp), 1, db) == 1) {
        if (tmp.id == id) {
            tmp = *c;
            tmp.id = id;
            fseek(db, (long)i * sizeof(Contact), SEEK_SET);
            fwrite(&tmp, sizeof(Contact), 1, db);
            fflush(db);
            return 1;
        }
        i++;
    }
    return 0;
}

/**
 * @brief Remove um contato do banco com base no ID.
 * O processo cria um arquivo temporário sem o contato removido.
 * @param id ID do contato a ser removido.
 * @return 1 se removido com sucesso, 0 se não encontrado.
 */
int cm_delete_contact(int id) {
    FILE *ft = fopen("temp.db", "w+b");
    if (!ft) return 0;

    rewind(db);
    Contact tmp;
    int found = 0;
    while (fread(&tmp, sizeof(tmp), 1, db) == 1) {
        if (tmp.id == id) {
            found = 1;
            continue;
        }
        fwrite(&tmp, sizeof(tmp), 1, ft);
    }
    fclose(db);
    fclose(ft);
    remove(DATABASE_FILE);
    rename("temp.db", DATABASE_FILE);
    cm_init();  // Reabre o novo arquivo
    return found;
}

/**
 * @brief Retorna a quantidade de contatos armazenados.
 * @return Número total de contatos.
 */
size_t cm_count_contacts(void) {
    return total_records();
}

/**
 * @brief Carrega todos os contatos do banco em um array.
 * O array alocado deve ser liberado com `cm_free_contacts`.
 * @param n Ponteiro para armazenar o número de contatos.
 * @return Ponteiro para array de contatos.
 */
Contact *cm_load_all_contacts(size_t *n) {
    size_t count = total_records();
    *n = count;
    Contact *arr = malloc(count * sizeof(Contact));
    if (!arr) return NULL;
    rewind(db);
    fread(arr, sizeof(Contact), count, db);
    return arr;
}

/**
 * @brief Imprime um contato na tela.
 * @param c Ponteiro para o contato a ser exibido.
 */
void cm_print_contact(const Contact *c) {
    printf("ID: %d\nNome: %s\nTelefone: %s\nEmail: %s\n\n",
           c->id, c->name, c->phone, c->email);
}

/**
 * @brief Libera o array alocado de contatos.
 * @param list Ponteiro para a memória alocada.
 */
void cm_free_contacts(Contact *list) {
    free(list);
}
