/**
 * @file main.c
 * @brief Aplicativo de linha de comando para gerenciamento de contatos.
 *
 * Oferece funcionalidades como:
 * - Listar todos os contatos
 * - Adicionar novo contato
 * - Editar um contato existente
 * - Excluir um contato existente
 *
 * Os dados são armazenados em um arquivo binário.
 *
 * @author Danilo Côrtes Gonçalves
 * @date 22/06/2025
 */

#include "contact_manager.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>
/**
 * @brief Lê do teclado os campos de um contato e atribui na struct.
 * Remove o '\n' inserido pelo fgets para evitar problemas.
 */
 
static void input_contact(Contact *c) {
    printf("Nome: ");
    fgets(c->name, MAX_NAME_LENGTH, stdin);
    c->name[strcspn(c->name, "\n")] = '\0';

    printf("Telefone: ");
    fgets(c->phone, MAX_PHONE_LENGTH, stdin);
    c->phone[strcspn(c->phone, "\n")] = '\0';

    printf("Email: ");
    fgets(c->email, MAX_EMAIL_LENGTH, stdin);
    c->email[strcspn(c->email, "\n")] = '\0';
}

/**
 * @brief Exibe o menu principal e lê a opção escolhida pelo usuário.
 * Utiliza scanf + getchar para limpar o '\n' do buffer.
 *
 * @return int Opção selecionada.
 */
static int menu(void) {
    printf("===== Gerenciador de Contatos =====\n");
    printf("1. Listar todos os contatos\n");
    printf("2. Adicionar contato\n");
    printf("3. Editar contato\n");
    printf("4. Excluir contato\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");

    int opt;
    scanf("%d", &opt);
    getchar();  // Remove o '\n' deixado no buffer
    return opt;
}

/**
 * @brief Função principal que controla o fluxo do aplicativo.
 * - Inicializa o banco
 * - Executa loop de menu até o usuário escolher sair
 * - Chama funções para cada opção (listar, adicionar, editar, excluir)
 * - Encerra o banco antes de sair
 */
int main(void) {
    cm_init();  // Abre/cria o arquivo de contatos


    // locale do ambiente (geralmente UTF-8)
    setlocale(LC_ALL, "");
    
    while (1) {
        int opt = menu();

        if (opt == 0) {
            // Se a opção for 0, interrompe o loop e encerra o programa
            break;
        }

        size_t n;
        Contact *list;

        switch (opt) {
            case 1:
                // 1) Listar todos os contatos
                n = cm_count_contacts();            // Conta quantos existem
                printf("\nTotal de contatos: %zu\n\n", n);
                list = cm_load_all_contacts(&n);     // Carrega todos
                for (size_t i = 0; i < n; i++) {
                    cm_print_contact(&list[i]);      // Imprime cada um
                }
                cm_free_contacts(list);              // Libera memória alocada
                break;

            case 2: {
                // 2) Adicionar novo contato
                printf("\nAdicionar novo contato:\n");
                Contact c;
                input_contact(&c);                   // Lê dados do usuário
                c = cm_add_contact(&c);             // Adiciona e recebe ID
                printf("Contato adicionado com ID %d\n\n", c.id);
                break;
            }

            case 3: {
                // 3) Editar um contato existente
                printf("Informe o ID do contato a editar: ");
                int id;
                scanf("%d", &id);
                getchar();  // Remove '\n'
                printf("Informe os novos dados:\n");
                Contact c;
                input_contact(&c);                // Lê novos dados
                if (cm_edit_contact(id, &c))      // Tenta editar
                    printf("Contato %d atualizado com sucesso.\n\n", id);
                else
                    printf("Contato %d nao encontrado.\n\n", id);
                break;
            }

            case 4: {
                // 4) Excluir um contato existente
                printf("Informe o ID do contato a excluir: ");
                int id;
                scanf("%d", &id);
                getchar();  // Remove '\n'
                if (cm_delete_contact(id))        // Tenta excluir
                    printf("Contato %d excluido com sucesso.\n\n", id);
                else
                    printf("Contato %d nao encontrado.\n\n", id);
                break;
            }

            default:
                // Qualquer outra opção é inválida
                printf("Opçao invalida.\n\n");
        }
    }

    cm_close();  // Fecha o arquivo de contatos
    return 0;
}
