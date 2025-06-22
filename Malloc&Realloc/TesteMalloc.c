/**
 * @file lista_encadeada.c
 * @brief Implementação de uma lista encadeada dinâmica em C
 * 
 * Este programa demonstra a criação, manipulação e destruição de uma lista encadeada
 * com alocação dinâmica de memória. A lista é composta por nós que armazenam valores
 * inteiros e ponteiros para o próximo elemento.
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * @struct Lista
 * @brief Estrutura que representa um nó da lista encadeada
 * 
 * A estrutura contém:
 * @var valor: Inteiro armazenado no nó
 * @var proximo: Ponteiro para o próximo nó na lista
 */
typedef struct Lista {
    int valor;              /**< Valor inteiro armazenado no nó */
    struct Lista *proximo;  /**< Ponteiro para o próximo elemento da lista */
} Lista;

/**
 * @brief Função principal que gerencia a lista encadeada
 * 
 * A função realiza as seguintes operações:
 * 1. Solicita valores ao usuário até que ele decida parar
 * 2. Insere os valores em uma lista encadeada dinâmica
 * 3. Imprime todos os elementos da lista com seus endereços de memória
 * 4. Libera toda a memória alocada antes de encerrar
 * 
 * @return int Retorna 0 em caso de sucesso, 1 em falha de alocação
 */
int main() {
    Lista *inicio = NULL;  /**< Ponteiro para o primeiro nó da lista */
    Lista *fim = NULL;     /**< Ponteiro para o último nó (otimiza inserções) */

    char parar = 'N';      /**< Controle de término da entrada de dados */

    // Loop de entrada de dados
    while (parar != 'S' && parar != 's') {
        // Aloca novo nó
        Lista *novo = malloc(sizeof(Lista));
        if (novo == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }

        // Captura valor do usuário
        printf("\nInforme um valor: ");
        scanf("%d", &novo->valor);
        novo->proximo = NULL;

        // Insere na lista
        if (inicio == NULL) {
            // Primeira inserção (lista vazia)
            inicio = novo;
            fim = novo;
        } else {
            // Inserções subsequentes
            fim->proximo = novo;
            fim = novo;
        }

        // Verifica se usuário deseja continuar
        printf("Deseja parar? (S/N): ");
        scanf(" %c", &parar);  // Espaço consome quebra de linha anterior
    }

    // Imprime lista completa
    printf("\n--- Lista criada ---\n");
    Lista *atual = inicio;
    int i = 0;
    while (atual != NULL) {
        printf("Elemento %d: valor = %d, endereço = %p, próximo = %p\n",
               i, atual->valor, (void*)atual, (void*)atual->proximo);
        atual = atual->proximo;
        i++;
    }

    // Libera memória alocada
    atual = inicio;
    while (atual != NULL) {
        Lista *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}