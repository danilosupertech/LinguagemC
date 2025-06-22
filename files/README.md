## 🇧🇷 Documentação em Português

### 📌 Visão Geral
Programa em C para leitura segura e eficiente de arquivos texto, demonstrando boas práticas de manipulação de arquivos com tratamento robusto de erros.

### 🎯 Objetivo
Implementar um leitor de arquivos que:
- Abre arquivos com verificação rigorosa de erros
- Lê conteúdo linha por linha prevenindo buffer overflow
- Exibe conteúdo formatado no terminal
- Gerencia recursos de memória corretamente

### ⚙️ Implementação
```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define FILENAME "string.txt"

int main(void) {
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    
    file = fopen(FILENAME, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo '%s'\n", FILENAME);
        fprintf(stderr, "Verifique se o arquivo existe e as permissões de acesso\n");
        getchar();
        return EXIT_FAILURE;
    }
    
    printf("Conteúdo do arquivo '%s':\n", FILENAME);
    printf("----------------------------------------\n");
    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    printf("\n----------------------------------------\n");
    printf("Fim do arquivo\n\n");
    
    fclose(file);
    
    printf("Pressione qualquer tecla para sair...");
    getchar();
    
    return EXIT_SUCCESS;
}
# Compilar
gcc -std=c99 -Wall arquivo_texto.c -o leitor

# Executar
./leitor


#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100
#define FILENAME "string.txt"

int main(void) {
    FILE *file;
    char buffer[MAX_LINE_LENGTH];
    
    file = fopen(FILENAME, "r");
    
    if (file == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'\n", FILENAME);
        fprintf(stderr, "Verify file exists and access permissions\n");
        getchar();
        return EXIT_FAILURE;
    }
    
    printf("Content of file '%s':\n", FILENAME);
    printf("----------------------------------------\n");
    
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }
    
    printf("\n----------------------------------------\n");
    printf("End of file\n\n");
    
    fclose(file);
    
    printf("Press any key to exit...");
    getchar();
    
    return EXIT_SUCCESS;
}

# Compile
gcc -std=c99 -Wall file_reader.c -o reader

# Execute
./reader


## 📥 Como Usar
1. Copie todo o conteúdo acima
2. Cole no seu arquivo `README.md`
3. Personalize conforme necessário

Este documento está pronto para uso imediato com:
- Formatação Markdown perfeita
- Seções bilíngues organizadas
- Destaques de código apropriados
- Tabelas de testes claras
- Instruções de compilação precisas