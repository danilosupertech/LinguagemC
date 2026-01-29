/**
 * @file arquivo_texto.c
 * @brief Programa demonstrativo de manipulação de arquivos de texto em C
 * 
 * Este programa ilustra operações básicas com arquivos de texto, incluindo:
 * - Abertura e fechamento de arquivos
 * - Tratamento de erros na abertura de arquivos
 * - Leitura linha por linha com tratamento de buffer
 * - Exibição de conteúdo na saída padrão
 * 
 * O programa lê o conteúdo de um arquivo chamado "string.txt" e exibe seu conteúdo
 * linha por linha no console.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 100  /**< Tamanho máximo do buffer para leitura de linhas */
#define FILENAME "string.txt" /**< Nome do arquivo a ser lido */

/**
 * @brief Função principal do programa
 * 
 * Executa as seguintes operações:
 * 1. Abre o arquivo especificado em modo leitura
 * 2. Verifica erros na abertura do arquivo
 * 3. Lê o conteúdo linha por linha usando buffer seguro
 * 4. Exibe cada linha no console
 * 5. Fecha o arquivo e finaliza o programa
 * 
 * @return int Código de saída do programa (0 = sucesso)
 */
int main(void) {
    FILE *file;                 /**< Ponteiro para o arquivo */
    char buffer[MAX_LINE_LENGTH]; /**< Buffer para armazenar linhas lidas */

    // Abre o arquivo em modo leitura
    file = fopen("string.txt", "r");

    // Verifica falha na abertura do arquivo
    if (file == NULL) {
        fprintf(stderr, "Erro: Não foi possível abrir o arquivo '%s'\n", FILENAME);
        fprintf(stderr, "Verifique se o arquivo existe e as permissões de acesso\n");
        getchar();
        return EXIT_FAILURE;
    }

    printf("Conteúdo do arquivo '%s':\n", "string.txt");
    printf("----------------------------------------\n");

    // Lê e exibe o conteúdo linha por linha
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
    }

    printf("\n----------------------------------------\n");
    printf("Fim do arquivo\n\n");

    // Fecha o arquivo
    fclose(file);

    // Pausa para visualização do resultado (Windows)
    printf("Pressione qualquer tecla para sair...");
    getchar();

    return EXIT_SUCCESS;
}