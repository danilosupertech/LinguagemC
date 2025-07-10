#include <stdio.h>
#include <stdlib.h>



typedef struct No
{
    int valor;
    struct No *proximo;
} No;

typedef struct
{
    No *inicio;
    int tam;
} Lista;


void inserirIni(Lista *lista, int valor)
{

    //Criar novo n�.
    No *novo = (No*)malloc(sizeof(No));


    if(novo == NULL)
    {
        printf("Algo deu errado ao alocar memoria para criacao de novo No");
        return; // sair da fun��o
    };

    //Atribuir valor ao n�
    novo->valor = valor;
    //atribuir endere�o de memoria do valor lista inicio que ja e NULL (primeira insercao) ou o valor do endere�o de memoria dos demais no campo proximo do no.
    novo->proximo = lista->inicio;
    //atribui o endere�o de memoria do no ao campo inicio da lista.
    lista->inicio = novo;
    //incrementa tamanho no campo tam da lista.
    lista->tam++;


};

void inserirFim(Lista *lista, int valor)
{
    // Alocar novo n�
    No *novo = (No*)malloc(sizeof(No));
    if(novo == NULL)
    {
        printf("Erro ao alocar mem�ria\n");
        return;
    }
    // Inicializar o novo n�
    novo->valor = valor;
    novo->proximo = NULL; // Sempre ser� o �ltimo, ent�o pr�ximo � NULL

    if(lista->inicio == NULL)
    {
        // Lista vazia: novo n� � o primeiro
        lista->inicio = novo;
    }
    else
    {
        // Encontrar o �ltimo n�
        No *atual = lista->inicio;

        while(atual->proximo != NULL)
        {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
    lista->tam++;

};


void removerInicio(Lista *lista) {
    if(lista->inicio == NULL) return;

    No* removido = lista->inicio;
    lista->inicio = removido->proximo;

    free(removido); // Libera o n� removido
    lista->tam--;
}

void removerElemento(Lista *lista, int valor) {
    // Verifica se a lista est� vazia
    if (lista->inicio == NULL) {
        printf("A lista est� vazia. Nada a remover.\n");
        return;
    }

    // Ponteiro para percorrer a lista
    No *atual = lista->inicio;

    // Ponteiro que ir� guardar o n� anterior ao que queremos remover
    No *anterior = NULL;

    // Percorre a lista at� encontrar o valor ou chegar ao fim
    while (atual != NULL && atual->valor != valor) {
        anterior = atual;           // Atualiza o ponteiro anterior
        atual = atual->proximo;     // Move para o pr�ximo n�
    }

    // Se atual � NULL, o valor n�o est� na lista
    if (atual == NULL) {
        printf("Valor %d n�o encontrado na lista.\n", valor);
        return;
    }

    // Se anterior � NULL, o n� a ser removido est� no in�cio
    if (anterior == NULL) {
        lista->inicio = atual->proximo;  // Atualiza o in�cio da lista
    } else {
        // "Pula" o n� atual, ligando anterior diretamente ao pr�ximo
        anterior->proximo = atual->proximo;
    }

    // Libera a mem�ria do n� removido
    free(atual);

    // Decrementa o tamanho da lista
    lista->tam--;

    // Informa ao usu�rio
    printf("Valor %d removido com sucesso.\n", valor);
}




void imprimir(Lista *lista)
{

    No *inicio = lista->inicio;
    while(inicio!=NULL)
    {
        printf("%d\t", inicio->valor);
        inicio = inicio->proximo;
    };
    printf("\n\n");
}

int maixn()
{
    Lista lista;
    lista.inicio = NULL;
    lista.tam =0;
    int opcao = 0;
    int valor = 0;


    do
    {

        printf("Selecione uma das opcoes\n1 - inserir valor inicio. \n2 - Inserir fim Lista. \n3 - Imprimir lista. \n4 - Remover\n5 - Sair\n-->");
        scanf("%d",&opcao);

        switch(opcao)
        {

        case 1:
            printf("\nDigite um valor a ser inserido: ");
            scanf("%d",&valor);
            inserirIni(&lista,valor);
            imprimir(&lista);
            break;
        case 2:
            printf("\nDigite um valor a ser inserido: ");
            scanf("%d",&valor);
            inserirFim(&lista,valor);
            imprimir(&lista);
        case 3:
            imprimir(&lista);
            break;
        case 4:
            printf("\nDigite o valor a ser removido: ");
            scanf("%d", &valor);
            removerElemento(&lista, valor);
            imprimir(&lista);
    break;
        case 5:
            break;
        default:
            printf(" Voce escolheu uma opcao invalida !!!!");
        }

    }
    while(opcao!=5);



    return 0;

}
