#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Para tolower()

// Estrutura para representar um Produto
typedef struct Produto {
    char nome[50];
    float preco;
    int quantidade_estoque;
    struct Produto* proximo;
} Produto;

// Estrutura para categorias de produtos
typedef struct Categoria {
    char nome[50];
    Produto* produtos;
    struct Categoria* proxima;
} Categoria;

// Estrutura para itens no carrinho
typedef struct ItemCarrinho {
    Produto* produto;
    int quantidade;
    struct ItemCarrinho* proximo;
} ItemCarrinho;

// Estrutura principal do carrinho
typedef struct Carrinho {
    ItemCarrinho* itens;
    int quantidade_itens;
    int capacidade_maxima;
    float total;
} Carrinho;

// Estrutura do supermercado
typedef struct Supermercado {
    Categoria* categorias;
    Carrinho* carrinho_ativo;
} Supermercado;

// Protótipos de funções
Categoria* adicionar_categoria(Supermercado* supermercado, const char* nome);
Produto* adicionar_produto(Categoria* categoria, const char* nome, float preco, int estoque);
Carrinho* criar_carrinho(int capacidade);
void adicionar_ao_carrinho(Supermercado* supermercado, const char* categoria_nome, const char* produto_nome, int quantidade);
void remover_do_carrinho(Supermercado* supermercado, const char* produto_nome, int quantidade);
void visualizar_carrinho(Carrinho* carrinho);
void finalizar_compra(Supermercado* supermercado);
void liberar_memoria(Supermercado* supermercado);
void menu(Supermercado* supermercado);
void listar_categorias_e_produtos(Supermercado* supermercado);

int main() {
    Supermercado supermercado;
    supermercado.categorias = NULL;
    supermercado.carrinho_ativo = NULL;

    // Adicionar categorias e produtos iniciais
    Categoria* frutas = adicionar_categoria(&supermercado, "Frutas");
    adicionar_produto(frutas, "Maca", 5.99, 100);
    adicionar_produto(frutas, "Banana", 3.49, 150);
    adicionar_produto(frutas, "Laranja", 4.25, 120);

    Categoria* laticinios = adicionar_categoria(&supermercado, "Laticinios");
    adicionar_produto(laticinios, "Leite", 6.89, 80);
    adicionar_produto(laticinios, "Queijo", 15.90, 50);
    adicionar_produto(laticinios, "Iogurte", 3.99, 70);

    Categoria* bebidas = adicionar_categoria(&supermercado, "Bebidas");
    adicionar_produto(bebidas, "Agua", 2.50, 200);
    adicionar_produto(bebidas, "Refrigerante", 7.50, 100);
    adicionar_produto(bebidas, "Suco", 8.00, 90);

    // Criar carrinho com capacidade para 50 itens
    supermercado.carrinho_ativo = criar_carrinho(50);

    // Chamar menu interativo
    menu(&supermercado);

    // Liberar memória ao final
    liberar_memoria(&supermercado);

    return 0;
}

// Implementações das funções

Categoria* adicionar_categoria(Supermercado* supermercado, const char* nome) {
    Categoria* nova = malloc(sizeof(Categoria));
    strcpy(nova->nome, nome);
    nova->produtos = NULL;
    nova->proxima = supermercado->categorias;
    supermercado->categorias = nova;
    return nova;
}

Produto* adicionar_produto(Categoria* categoria, const char* nome, float preco, int estoque) {
    Produto* novo = malloc(sizeof(Produto));
    strcpy(novo->nome, nome);
    novo->preco = preco;
    novo->quantidade_estoque = estoque;
    novo->proximo = categoria->produtos;
    categoria->produtos = novo;
    return novo;
}

Carrinho* criar_carrinho(int capacidade) {
    Carrinho* novo = malloc(sizeof(Carrinho));
    novo->itens = NULL;
    novo->quantidade_itens = 0;
    novo->capacidade_maxima = capacidade;
    novo->total = 0.0f;
    return novo;
}

void adicionar_ao_carrinho(Supermercado* supermercado, const char* categoria_nome, const char* produto_nome, int quantidade) {
    if (supermercado->carrinho_ativo == NULL) {
        printf("Erro: Carrinho nao inicializado.\n");
        return;
    }

    // Verificar se o carrinho está cheio
    if (supermercado->carrinho_ativo->quantidade_itens + quantidade > supermercado->carrinho_ativo->capacidade_maxima) {
        printf("Carrinho cheio! Capacidade maxima: %d itens\n", supermercado->carrinho_ativo->capacidade_maxima);
        return;
    }

    // Buscar categoria
    Categoria* cat_atual = supermercado->categorias;
    while (cat_atual != NULL) {
        if (strcmp(cat_atual->nome, categoria_nome) == 0) {
            break;
        }
        cat_atual = cat_atual->proxima;
    }

    if (cat_atual == NULL) {
        printf("Categoria '%s' nao encontrada.\n", categoria_nome);
        return;
    }

    // Buscar produto na categoria
    Produto* prod_atual = cat_atual->produtos;
    while (prod_atual != NULL) {
        if (strcmp(prod_atual->nome, produto_nome) == 0) {
            break;
        }
        prod_atual = prod_atual->proximo;
    }

    if (prod_atual == NULL) {
        printf("Produto '%s' nao encontrado na categoria '%s'.\n", produto_nome, categoria_nome);
        return;
    }

    // Verificar estoque
    if (quantidade > prod_atual->quantidade_estoque) {
        printf("Estoque insuficiente! Disponivel: %d\n", prod_atual->quantidade_estoque);
        return;
    }

    // Verificar se o produto já está no carrinho (para juntar quantidades)
    ItemCarrinho* item_atual = supermercado->carrinho_ativo->itens;
    while (item_atual != NULL) {
        if (item_atual->produto == prod_atual) {
            // Produto já está no carrinho, atualizar quantidade
            item_atual->quantidade += quantidade;
            supermercado->carrinho_ativo->total += prod_atual->preco * quantidade;
            prod_atual->quantidade_estoque -= quantidade;
            supermercado->carrinho_ativo->quantidade_itens += quantidade;
            printf("Quantidade atualizada: %s - %d unidades\n", prod_atual->nome, item_atual->quantidade);
            return;
        }
        item_atual = item_atual->proximo;
    }

    // Produto não está no carrinho, adicionar novo item
    ItemCarrinho* novo_item = malloc(sizeof(ItemCarrinho));
    novo_item->produto = prod_atual;
    novo_item->quantidade = quantidade;
    novo_item->proximo = supermercado->carrinho_ativo->itens;
    supermercado->carrinho_ativo->itens = novo_item;

    supermercado->carrinho_ativo->quantidade_itens += quantidade;
    supermercado->carrinho_ativo->total += prod_atual->preco * quantidade;
    prod_atual->quantidade_estoque -= quantidade;

    printf("%d x %s adicionado(s) ao carrinho!\n", quantidade, prod_atual->nome);
}

void remover_do_carrinho(Supermercado* supermercado, const char* produto_nome, int quantidade) {
    if (supermercado->carrinho_ativo == NULL || supermercado->carrinho_ativo->itens == NULL) {
        printf("Carrinho vazio!\n");
        return;
    }

    ItemCarrinho* item_atual = supermercado->carrinho_ativo->itens;
    ItemCarrinho* item_anterior = NULL;

    while (item_atual != NULL) {
        if (strcmp(item_atual->produto->nome, produto_nome) == 0) {
            if (quantidade > item_atual->quantidade) {
                printf("Quantidade a remover maior que a existente no carrinho.\n");
                return;
            }

            // Atualizar valores
            item_atual->produto->quantidade_estoque += quantidade;
            supermercado->carrinho_ativo->total -= item_atual->produto->preco * quantidade;
            supermercado->carrinho_ativo->quantidade_itens -= quantidade;
            item_atual->quantidade -= quantidade;

            // Se removeu tudo, remover o item do carrinho
            if (item_atual->quantidade == 0) {
                if (item_anterior == NULL) {
                    supermercado->carrinho_ativo->itens = item_atual->proximo;
                } else {
                    item_anterior->proximo = item_atual->proximo;
                }
                free(item_atual);
            }

            printf("%d x %s removido(s) do carrinho.\n", quantidade, produto_nome);
            return;
        }
        item_anterior = item_atual;
        item_atual = item_atual->proximo;
    }

    printf("Produto '%s' nao encontrado no carrinho.\n", produto_nome);
}

void visualizar_carrinho(Carrinho* carrinho) {
    if (carrinho == NULL || carrinho->itens == NULL) {
        printf("Carrinho vazio!\n");
        return;
    }

    printf("\n----- SEU CARRINHO -----\n");
    printf("%-20s %-10s %-10s %s\n", "Produto", "Quantidade", "Preco", "Subtotal");

    ItemCarrinho* atual = carrinho->itens;
    while (atual != NULL) {
        float subtotal = atual->produto->preco * atual->quantidade;
        printf("%-20s %-10d R$%-9.2f R$%.2f\n",
               atual->produto->nome,
               atual->quantidade,
               atual->produto->preco,
               subtotal);
        atual = atual->proximo;
    }

    printf("\nTOTAL: R$%.2f\n", carrinho->total);
    printf("Itens: %d/%d\n", carrinho->quantidade_itens, carrinho->capacidade_maxima);
}

void finalizar_compra(Supermercado* supermercado) {
    if (supermercado->carrinho_ativo == NULL || supermercado->carrinho_ativo->quantidade_itens == 0) {
        printf("Carrinho vazio! Nada para finalizar.\n");
        return;
    }

    // Imprimir nota fiscal
    printf("\n----- NOTA FISCAL -----\n");
    printf("%-20s %-10s %-10s %s\n", "Produto", "Quantidade", "Preco", "Subtotal");

    ItemCarrinho* atual = supermercado->carrinho_ativo->itens;
    while (atual != NULL) {
        float subtotal = atual->produto->preco * atual->quantidade;
        printf("%-20s %-10d R$%-9.2f R$%.2f\n",
               atual->produto->nome,
               atual->quantidade,
               atual->produto->preco,
               subtotal);
        atual = atual->proximo;
    }

    printf("\nTOTAL: R$%.2f\n", supermercado->carrinho_ativo->total);
    printf("Compra finalizada com sucesso!\n");

    // Liberar memória dos itens do carrinho
    atual = supermercado->carrinho_ativo->itens;
    while (atual != NULL) {
        ItemCarrinho* temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    // Resetar carrinho (mas manter a estrutura)
    supermercado->carrinho_ativo->itens = NULL;
    supermercado->carrinho_ativo->quantidade_itens = 0;
    supermercado->carrinho_ativo->total = 0.0f;
}

void liberar_memoria(Supermercado* supermercado) {
    // Liberar categorias e produtos
    Categoria* cat_atual = supermercado->categorias;
    while (cat_atual != NULL) {
        Categoria* cat_prox = cat_atual->proxima;

        Produto* prod_atual = cat_atual->produtos;
        while (prod_atual != NULL) {
            Produto* prod_prox = prod_atual->proximo;
            free(prod_atual);
            prod_atual = prod_prox;
        }

        free(cat_atual);
        cat_atual = cat_prox;
    }

    // Liberar carrinho
    if (supermercado->carrinho_ativo != NULL) {
        ItemCarrinho* item_atual = supermercado->carrinho_ativo->itens;
        while (item_atual != NULL) {
            ItemCarrinho* item_prox = item_atual->proximo;
            free(item_atual);
            item_atual = item_prox;
        }
        free(supermercado->carrinho_ativo);
    }
}

void listar_categorias_e_produtos(Supermercado* supermercado) {
    printf("\n----- PRODUTOS DISPONIVEIS -----\n");
    Categoria* cat_atual = supermercado->categorias;
    while (cat_atual != NULL) {
        printf("\n[%s]\n", cat_atual->nome);
        Produto* prod_atual = cat_atual->produtos;
        while (prod_atual != NULL) {
            printf("  %-15s R$%-8.2f Estoque: %d\n", prod_atual->nome, prod_atual->preco, prod_atual->quantidade_estoque);
            prod_atual = prod_atual->proximo;
        }
        cat_atual = cat_atual->proxima;
    }
    printf("\n");
}

void menu(Supermercado* supermercado) {
    int opcao;
    char categoria[50], produto[50];
    int quantidade;

    do {
        printf("\n===== SUPERMERCADO =====\n");
        printf("1. Listar produtos\n");
        printf("2. Adicionar produto ao carrinho\n");
        printf("3. Remover produto do carrinho\n");
        printf("4. Visualizar carrinho\n");
        printf("5. Finalizar compra\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listar_categorias_e_produtos(supermercado);
                break;
            case 2:
                printf("Categoria: ");
                scanf("%s", categoria);
                printf("Produto: ");
                scanf("%s", produto);
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                adicionar_ao_carrinho(supermercado, categoria, produto, quantidade);
                break;
            case 3:
                printf("Produto a remover: ");
                scanf("%s", produto);
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                remover_do_carrinho(supermercado, produto, quantidade);
                break;
            case 4:
                visualizar_carrinho(supermercado->carrinho_ativo);
                break;
            case 5:
                finalizar_compra(supermercado);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}
