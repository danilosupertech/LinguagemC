#include <stdio.h>
#include <stdlib.h>

// Estrutura para demonstração
typedef struct Data {
    int id;
    char status;
    float value;
    struct Data *next;
} Data;

// Função para imprimir estado da memória
void print_memory_state(Data *data, const char *label) {
    printf("\n%s:\n", label);
    printf("  id:     %d\n", data->id);
    printf("  status: %c (ASCII: %d)\n", data->status, data->status);
    printf("  value:  %f\n", data->value);
    printf("  next:   %p\n", (void*)data->next);
    printf("  Memory dump: ");
    unsigned char *bytes = (unsigned char*)data;
    for (int i = 0; i < sizeof(Data); i++) {
        printf("%02X ", bytes[i]);
    }
    printf("\n");
}

int main() {
    printf("=== Simulador: Malloc vs Calloc ===\n");
    
    // Simulação com MALLOC
    printf("\n[1] ALOCACAO COM MALLOC\n");
    Data *malloc_data = malloc(sizeof(Data));
    
    // Mostrar estado inicial
    print_memory_state(malloc_data, "Estado INICIAL (lixo de memoria)");
    
    // Atribuir valores
    malloc_data->id = 100;
    malloc_data->status = 'A';
    malloc_data->value = 3.14;
    malloc_data->next = NULL;
    
    // Mostrar estado após atribuição
    print_memory_state(malloc_data, "Estado APOS atribuicao");

    // Simulação com CALLOC
    printf("\n[2] ALOCACAO COM CALLOC\n");
    Data *calloc_data = calloc(1, sizeof(Data));
    
    // Mostrar estado inicial
    print_memory_state(calloc_data, "Estado INICIAL (inicializado com zero)");
    
    // Atribuir valores (idênticos ao caso anterior)
    calloc_data->id = 100;
    calloc_data->status = 'A';
    calloc_data->value = 3.14;
    calloc_data->next = NULL;
    
    // Mostrar estado após atribuição
    print_memory_state(calloc_data, "Estado APOS atribuicao");

    // Liberar memória
    free(malloc_data);
    free(calloc_data);

    printf("\n=== Conclusoes ===\n");
    printf("Malloc: Deixa conteudo anterior da memoria (lixo)\n");
    printf("Calloc: Inicializa toda memoria com zero\n");
    printf("Vantagem Calloc: Evita valores aleatorios e ponteiros perigosos\n");
    
    return 0;
}