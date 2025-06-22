#include <stdio.h>
#include <stdlib.h>

typedef struct Lista {
    int valor;
    struct Lista *proximo;
} Lista;

int main() {
    Lista *inicio = NULL;  // Ponteiro para o primeiro nó
    Lista *fim = NULL;     // Ponteiro para o último nó (para facilitar inserção)

    char parar = 'N';

    while (parar != 'S' && parar != 's') {
        Lista *novo = malloc(sizeof(Lista));  // Aloca um novo nó

        if (novo == NULL) {
            printf("Erro ao alocar memória!\n");
            return 1;
        }

        printf("\nInforme um valor: ");
        scanf("%d", &novo->valor);
        novo->proximo = NULL;

        // Inserir na lista
        if (inicio == NULL) {
            // Primeiro elemento
            inicio = novo;
            fim = novo;
        } else {
            fim->proximo = novo;
            fim = novo;
        }

        printf("Deseja parar? (S/N): ");
        scanf(" %c", &parar);  // espaço antes de %c para consumir enter
    }

    // Impressão da lista
    printf("\n--- Lista criada ---\n");
    Lista *atual = inicio;
    int i = 0;
    while (atual != NULL) {
        printf("Elemento %d: valor = %d, endereço = %p, próximo = %p\n",
               i, atual->valor, (void*)atual, (void*)atual->proximo);
        atual = atual->proximo;
        i++;
    }

    // Liberação da memória
    atual = inicio;
    while (atual != NULL) {
        Lista *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
