# Implementação de Alocação Dinâmica - Lista Encadeada em C

## Objetivo
Demonstrar os princípios fundamentais de:
- Alocação dinâmica de memória
- Estruturas de dados encadeadas
- Gerenciamento manual de memória
- Operações básicas em listas encadeadas

## Funcionalidades Implementadas
1. Criação dinâmica de nós
2. Inserção no final da lista (O(1))
3. Travessia/impressão da lista
4. Desalocação completa de memória
5. Tratamento básico de erros de alocação

## 🇺🇸 English Version

## Dynamic Memory Allocation: Malloc vs Calloc

### How Memory Allocation Works
```c
#include <stdlib.h>

// malloc: Allocates uninitialized memory
int *arr_malloc = malloc(5 * sizeof(int)); 

// calloc: Allocates zero-initialized memory
int *arr_calloc = calloc(5, sizeof(int));

// malloc output example:
Element 0: value = -1094795585, address = 0x561a3d5b1260

// calloc output example:
Element 0: value = 0, address = 0x561a3d5b12a0

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

int main() {
    // Safer allocation with calloc
    Node *node = calloc(1, sizeof(Node));
    
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    
    node->data = 42;
    // node->next is automatically NULL
    
    printf("Node data: %d\n", node->data);
    printf("Next address: %p\n", (void*)node->next);
    
    free(node);
    return 0;
}

#include <stdlib.h>

// malloc: Aloca memória não inicializada
int *arr_malloc = malloc(5 * sizeof(int)); 

// calloc: Aloca memória inicializada com zero
int *arr_calloc = calloc(5, sizeof(int));

// Exemplo de saída malloc:
Elemento 0: valor = -1094795585, endereço = 0x561a3d5b1260

// Exemplo de saída calloc:
Elemento 0: valor = 0, endereço = 0x561a3d5b12a0

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dado;
    struct Node *proximo;
} Node;

int main() {
    // Alocação mais segura com calloc
    Node *node = calloc(1, sizeof(Node));
    
    if (node == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        return 1;
    }
    
    node->dado = 42;
    // node->proximo já é automaticamente NULL
    
    printf("Dado do nó: %d\n", node->dado);
    printf("Endereço próximo: %p\n", (void*)node->proximo);
    
    free(node);
    return 0;
}