/**
 * @file main.c
 * @brief Interactive shopping cart application.
 *
 * This program provides a command-line interface for managing a shopping cart.
 * Users can add products, remove products, update quantities, and view cart totals.
 *
 * @author Danilo Côrtes Gonçalves
 * @date 2026-01-29
 * @version 2.0
 */

#include "shopping_cart.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ==================== Constants ==================== */

/** Maximum length for user input buffer */
#define MAX_INPUT_LEN 256

/* ==================== Function Prototypes ==================== */

/**
 * @brief Displays the main menu and returns user choice.
 *
 * @return Menu option selected by user.
 */
static int display_menu(void);

/**
 * @brief Clears input buffer after scanf operations.
 *
 * Removes leftover newline character from stdin.
 */
static void clear_input_buffer(void);

/**
 * @brief Reads a string safely from standard input.
 *
 * @param buffer Destination buffer.
 * @param size Buffer size.
 *
 * @return Number of characters read.
 */
static int read_string(char *buffer, size_t size);

/**
 * @brief Handles adding a product to the cart.
 *
 * @param cart Shopping cart to modify.
 */
static void handle_add_product(ShoppingCart *cart);

/**
 * @brief Handles removing a product from the cart.
 *
 * @param cart Shopping cart to modify.
 */
static void handle_remove_product(ShoppingCart *cart);

/**
 * @brief Handles updating product quantity.
 *
 * @param cart Shopping cart to modify.
 */
static void handle_update_quantity(ShoppingCart *cart);

/**
 * @brief Handles searching for a product in the cart.
 *
 * @param cart Shopping cart to search.
 */
static void handle_search_product(const ShoppingCart *cart);

/**
 * @brief Displays help information.
 */
static void display_help(void);

/* ==================== Implementation ==================== */

static int display_menu(void) {
    printf("\n");
    printf("╔════════════════════════════════════╗\n");
    printf("║  SISTEMA DE CARRINHO DE COMPRAS   ║\n");
    printf("╠════════════════════════════════════╣\n");
    printf("║ 1 - Adicionar produto              ║\n");
    printf("║ 2 - Remover produto                ║\n");
    printf("║ 3 - Atualizar quantidade           ║\n");
    printf("║ 4 - Buscar produto                 ║\n");
    printf("║ 5 - Visualizar carrinho            ║\n");
    printf("║ 6 - Limpar carrinho                ║\n");
    printf("║ 7 - Ver ajuda                      ║\n");
    printf("║ 0 - Sair                           ║\n");
    printf("╚════════════════════════════════════╝\n");
    printf("Escolha uma opcao: ");

    int choice;
    if (scanf("%d", &choice) != 1) {
        clear_input_buffer();
        return -1;
    }
    clear_input_buffer();
    return choice;
}

static void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

static int read_string(char *buffer, size_t size) {
    if (!buffer || size == 0) {
        return -1;
    }

    if (fgets(buffer, (int)size, stdin) == NULL) {
        return -1;
    }

    // Remove trailing newline
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    return (int)strlen(buffer);
}

static void handle_add_product(ShoppingCart *cart) {
    if (!cart) {
        printf("Erro: Carrinho inválido.\n");
        return;
    }

    printf("\n--- Adicionar Produto ---\n");

    int code;
    printf("Código do produto: ");
    if (scanf("%d", &code) != 1) {
        clear_input_buffer();
        printf("Erro: Código inválido.\n");
        return;
    }
    clear_input_buffer();

    char name[MAX_PRODUCT_NAME_LEN];
    printf("Nome do produto: ");
    if (read_string(name, sizeof(name)) <= 0) {
        printf("Erro: Nome inválido.\n");
        return;
    }

    float price;
    printf("Preço unitário: R$ ");
    if (scanf("%f", &price) != 1) {
        clear_input_buffer();
        printf("Erro: Preço inválido.\n");
        return;
    }
    clear_input_buffer();

    int quantity;
    printf("Quantidade: ");
    if (scanf("%d", &quantity) != 1) {
        clear_input_buffer();
        printf("Erro: Quantidade inválida.\n");
        return;
    }
    clear_input_buffer();

    CartStatus status = cart_add_product(cart, code, name, price, quantity);

    switch (status) {
        case CART_SUCCESS:
            printf("\n✓ Produto adicionado com sucesso!\n");
            break;
        case CART_ERROR_INVALID_INPUT:
            printf("\n✗ Erro: Entrada inválida (preço e quantidade devem ser positivos).\n");
            break;
        case CART_ERROR_MALLOC:
            printf("\n✗ Erro: Falha na alocação de memória.\n");
            break;
        default:
            printf("\n✗ Erro desconhecido.\n");
    }
}

static void handle_remove_product(ShoppingCart *cart) {
    if (!cart) {
        printf("Erro: Carrinho inválido.\n");
        return;
    }

    printf("\n--- Remover Produto ---\n");

    int code;
    printf("Código do produto a remover: ");
    if (scanf("%d", &code) != 1) {
        clear_input_buffer();
        printf("Erro: Código inválido.\n");
        return;
    }
    clear_input_buffer();

    CartStatus status = cart_remove_product(cart, code);

    if (status == CART_SUCCESS) {
        printf("✓ Produto removido com sucesso!\n");
    } else if (status == CART_ERROR_NOT_FOUND) {
        printf("✗ Erro: Produto não encontrado no carrinho.\n");
    } else {
        printf("✗ Erro: Operação falhou.\n");
    }
}

static void handle_update_quantity(ShoppingCart *cart) {
    if (!cart) {
        printf("Erro: Carrinho inválido.\n");
        return;
    }

    printf("\n--- Atualizar Quantidade ---\n");

    int code;
    printf("Código do produto: ");
    if (scanf("%d", &code) != 1) {
        clear_input_buffer();
        printf("Erro: Código inválido.\n");
        return;
    }
    clear_input_buffer();

    int new_quantity;
    printf("Nova quantidade: ");
    if (scanf("%d", &new_quantity) != 1) {
        clear_input_buffer();
        printf("Erro: Quantidade inválida.\n");
        return;
    }
    clear_input_buffer();

    CartStatus status = cart_update_quantity(cart, code, new_quantity);

    switch (status) {
        case CART_SUCCESS:
            printf("✓ Quantidade atualizada com sucesso!\n");
            break;
        case CART_ERROR_NOT_FOUND:
            printf("✗ Erro: Produto não encontrado no carrinho.\n");
            break;
        case CART_ERROR_INVALID_INPUT:
            printf("✗ Erro: Entrada inválida.\n");
            break;
        default:
            printf("✗ Erro desconhecido.\n");
    }
}

static void handle_search_product(const ShoppingCart *cart) {
    if (!cart) {
        printf("Erro: Carrinho inválido.\n");
        return;
    }

    printf("\n--- Buscar Produto ---\n");

    int code;
    printf("Código do produto: ");
    if (scanf("%d", &code) != 1) {
        clear_input_buffer();
        printf("Erro: Código inválido.\n");
        return;
    }
    clear_input_buffer();

    Product *product = cart_find_product(cart, code);

    if (product) {
        printf("\n✓ Produto encontrado:\n");
        printf("  Código:     %d\n", product->code);
        printf("  Nome:       %s\n", product->name);
        printf("  Preço:      R$ %.2f\n", product->unit_price);
        printf("  Quantidade: %d\n", product->quantity);
        printf("  Subtotal:   R$ %.2f\n\n", product->unit_price * product->quantity);
    } else {
        printf("✗ Erro: Produto não encontrado no carrinho.\n");
    }
}

static void display_help(void) {
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          AJUDA DO SISTEMA                         ║\n");
    printf("╠════════════════════════════════════════════════════════════════════╣\n");
    printf("║ Este é um sistema de gerenciamento de carrinho de compras.        ║\n");
    printf("║                                                                    ║\n");
    printf("║ FUNCIONALIDADES:                                                   ║\n");
    printf("║  • Adicionar produtos ao carrinho                                 ║\n");
    printf("║  • Remover produtos do carrinho                                   ║\n");
    printf("║  • Atualizar quantidades de produtos                              ║\n");
    printf("║  • Buscar produtos específicos                                    ║\n");
    printf("║  • Visualizar carrinho completo com totais                        ║\n");
    printf("║  • Limpar carrinho (remover todos os produtos)                    ║\n");
    printf("║                                                                    ║\n");
    printf("║ DADOS ARMAZENADOS:                                                 ║\n");
    printf("║  • Código do produto (identificador único)                        ║\n");
    printf("║  • Nome do produto                                                ║\n");
    printf("║  • Preço unitário                                                 ║\n");
    printf("║  • Quantidade                                                      ║\n");
    printf("║                                                                    ║\n");
    printf("║ NOTA: Os dados são armazenados em memória durante a execução.    ║\n");
    printf("║ Ao sair do programa, o carrinho é perdido (não é persistido).    ║\n");
    printf("╚════════════════════════════════════════════════════════════════════╝\n\n");
}

/**
 * @brief Main entry point of the application.
 *
 * Initializes the shopping cart and runs the interactive menu loop.
 *
 * @return EXIT_SUCCESS on successful completion, EXIT_FAILURE on error.
 */
int main(void) {
    printf("\n╔════════════════════════════════════════════════╗\n");
    printf("║      BEM-VINDO AO CARRINHO DE COMPRAS       ║\n");
    printf("║           Versão 2.0 - Profissional          ║\n");
    printf("╚════════════════════════════════════════════════╝\n");

    // Create shopping cart
    ShoppingCart *cart = cart_create();
    if (!cart) {
        printf("\nErro fatal: Falha ao criar o carrinho.\n");
        return EXIT_FAILURE;
    }

    // Add some sample products for demonstration
    cart_add_product(cart, 1001, "Notebook Dell 15\"", 3499.99f, 1);
    cart_add_product(cart, 1002, "Mouse Logitech", 89.90f, 2);
    cart_add_product(cart, 1003, "Teclado Mecânico RGB", 450.00f, 1);

    printf("\n(Carrinho pré-preenchido com produtos de exemplo)\n");

    // Main application loop
    int running = 1;
    while (running) {
        int choice = display_menu();

        switch (choice) {
            case 1:
                handle_add_product(cart);
                break;

            case 2:
                handle_remove_product(cart);
                break;

            case 3:
                handle_update_quantity(cart);
                break;

            case 4:
                handle_search_product(cart);
                break;

            case 5:
                cart_print(cart);
                break;

            case 6: {
                printf("\nTem certeza que deseja limpar o carrinho? (S/N): ");
                char confirm;
                if (scanf("%c", &confirm) == 1) {
                    if (confirm == 'S' || confirm == 's') {
                        cart_clear(cart);
                        printf("✓ Carrinho limpo com sucesso!\n");
                    } else {
                        printf("Operação cancelada.\n");
                    }
                }
                clear_input_buffer();
                break;
            }

            case 7:
                display_help();
                break;

            case 0:
                printf("\nEncerrando o programa...\n");
                printf("Obrigado por usar o Carrinho de Compras!\n\n");
                running = 0;
                break;

            default:
                printf("\n✗ Opção inválida. Tente novamente.\n");
        }
    }

    // Clean up
    cart_destroy(cart);
    return EXIT_SUCCESS;
}

