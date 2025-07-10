#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char nome[30];
    struct No *proximo;
} No;

typedef struct Fila{
    No *inicio;
    No *fim;
    int tamanho;
} Fila;


Fila CriarFila(){

    Fila fila;
    fila.inicio = NULL;
    fila.fim = NULL;
    fila.tamanho = 0;
    return fila;
}

void NovoCliente(Fila *fila,char nome[30]){

    No *novo = malloc(sizeof(No));
    novo->proximo =NULL;// O novo n� n�o aponta pra ningu�m


    strcpy(novo->nome,nome);

    if(fila->inicio == NULL){
        /*
        Se for o primeiro registro ele atribui novo no como inicio na lista
        assim como o ultimo elemento, afinal uma pessoa que entra em uma fila vazia acumula
        as duas posicoes.
        */
        fila->inicio = novo;
        fila->fim = novo;
    }
    else{
        /*
         acessa a struct fila passada para saber qual e o endereco de memoria do ultimo cliente.
         Com esse endere�o de memoria atualiza o campo proximo com o novo endere�o
         de memoria sendo agora o novo fim da fila
        */

        fila->fim->proximo = novo;

        fila->fim = novo;           // E atualiza o ponteiro 'fim' da fila

    }

    fila->tamanho++;

}

void ExibirFila(Fila *fila){
     No *cliente = fila->inicio;
    int pos = 0;

    while(cliente != NULL){
        printf("\n%d | %s", pos, cliente->nome);
        cliente = cliente->proximo;
        pos++;
    }

}


// Fun��o para atender (remover) o primeiro cliente da fila
void atendercliente(Fila *fila) {
    // Verifica se a fila est� vazia (n�o h� ningu�m para atender)
    if (fila->inicio == NULL) {
        printf("\nFila vazia. Ningu�m para atender.\n");
        return; // Sai da fun��o, nada mais a fazer
    }

    // Cria um ponteiro auxiliar que aponta para o primeiro cliente (o que ser� removido)
    No *clienteRemovido = fila->inicio;

    // Atualiza o ponteiro 'inicio' da fila para o pr�ximo cliente
    fila->inicio = clienteRemovido->proximo;

    // Se, ap�s a remo��o, a fila ficar vazia (n�o h� mais ningu�m nela)
    if (fila->inicio == NULL) {
        // Tamb�m precisa atualizar o ponteiro 'fim' para NULL
        fila->fim = NULL;
    }

    // Libera a mem�ria alocada dinamicamente para o cliente que foi atendido
    free(clienteRemovido);

    // Decrementa o tamanho da fila
    fila->tamanho--;

    // Mensagem informando que o cliente foi atendido e removido
    printf("\nCliente atendido e removido da fila.\n");
}

int main() {
    Fila fila = CriarFila();  // cria uma nova fila vazia
    int opcao;
    char nome[30];

    do {
        printf("\nSelecione uma das opcoes abaixo:\n");
        printf("1 - Novo Cliente\n");
        printf("2 - Atender um cliente\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &opcao);
        while(getchar() != '\n');  // limpa o buffer de entrada

        switch(opcao) {
            case 1:
                printf("Qual o nome do cliente? ");
                scanf(" %[^\n]", nome);  // l� nome com espa�os

                NovoCliente(&fila, nome);
                printf("Cliente '%s' adicionado � fila.\n", nome);
                ExibirFila(&fila);
                break;

            case 2:
                atendercliente(&fila);
                ExibirFila(&fila);
                break;

            case 0:
                printf("Encerrando o programa...\n");
                break;

            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}
