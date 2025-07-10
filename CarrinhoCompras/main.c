#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura do produto
typedef struct Carrinho {
    int codigo;
    char nome[50];
    float preco;
    int quantidade;
    struct Carrinho *proximo;
} Carrinho;

// Adiciona um novo produto ao início da lista
Carrinho* adicionarProduto(Carrinho *inicio, int codigo, const char *nome, float preco, int quantidade) {
    Carrinho *novo = (Carrinho *)malloc(sizeof(Carrinho));
    
    if (novo == NULL) {
        printf("Erro de alocacao!\n");
        exit(1);
    }

    novo->codigo = codigo;
    strcpy(novo->nome, nome);
    novo->preco = preco;
    novo->quantidade = quantidade;
    novo->proximo = inicio;

    return novo;
}

// Imprime todos os produtos do carrinho
void listarProdutos(Carrinho *inicio) {
    Carrinho *atual = inicio;
    printf("\n--- Lista de Produtos ---\n");
    while (atual != NULL) {
        printf("Codigo: %d\n", atual->codigo);
        printf("Produto: %s\n", atual->nome);
        printf("Preco: R$ %.2f\n", atual->preco);
        printf("Quantidade: %d\n\n", atual->quantidade);
        atual = atual->proximo;
    }
}

// Libera a memória do carrinho
void liberarCarrinho(Carrinho *inicio) {
    Carrinho *atual = inicio;
    while (atual != NULL) {
        Carrinho *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

int main() {
    Carrinho *meuCarrinho = NULL;

    // Adiciona produtos (o último inserido aparece primeiro na lista)
    meuCarrinho = adicionarProduto(meuCarrinho, 101, "Arroz", 25.90, 2);
    meuCarrinho = adicionarProduto(meuCarrinho, 102, "Feijao", 8.50, 1);
    meuCarrinho = adicionarProduto(meuCarrinho, 103, "Macarrao", 4.99, 3);

    listarProdutos(meuCarrinho);
    liberarCarrinho(meuCarrinho);

    return 0;
}

