#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void imprimirVetor(int *v, int tam) {
	int i;
	for(i = 0; i <  tam; i++) {
		printf("\n %d \n ",*(v+i));
	}

};

typedef struct No {
	int valor;
	struct No *proximo;
} No;

typedef struct {
	No *inicio;
	int tam;
} Lista;

void inserirInicio(Lista *lista,int valor) {
	No *novo = (No*)malloc(sizeof(No)); //Novo nó alocando novo endereço de memória


	novo->valor = valor; //equivalente (*novo).valor = valor   -- atribui valor ao novo no criado
	novo->proximo = lista->inicio; //no campo proximo do no criado insere o endereço de memoria da lista


	lista->inicio = novo; //atribui o endereço de memoria de novo na variavel inicio.
	lista->tam++; // incrementa tamanho na lista.

}

void inserirIni(Lista *lista, int valor){
	
	//Criar novo nó.
	No *novo = (No*)malloc(sizeof(No));
	
	//Atribuir valor ao nó
	
	//atribuir endereço de memoria do valor lista inicio que ja e NULL (primeira insercao) ou o valor do endereço de memoria dos demais no campo proximo do no.
	
	//atribui o endereço de memoria do no ao campo inicio da lista.
	
	//incrementa tamanho no campo tam da lista.
	
	
};


void imprimir(Lista *lista) {

	No *inicio = lista->inicio;
	while(inicio!=NULL) {
		printf("%d\n", inicio->valor);
		inicio = inicio->proximo;
	};
	printf("\n\n");

};

void preencheVetor(int *v, int tam) {
	int i;
	for(i=0; i<tam; i++) {

		printf("\nInforme um valor:");
		scanf("%d",(v+i));

	}

	imprimirVetor(v, tam);

}

void preencherVetorInt(int *v, int tam) {
	int i;
	for(i=0; i <tam; i++) {
		printf("Digite um valor qualquer: ");
		scanf("%d",v+i);
	}
}

int main(int argc, char *argv[]) {

	int i, *valor1, valor2 = 50;
	char *letra1, letra2 = 'g';

	int opcao, valor;
	Lista lista;
	lista.inicio = NULL;
	lista.tam = 0;
		
	do {
		printf("1 -  inserir no inicio \n2- Imprimir \n3 - Sair\n");
		scanf("%d",&opcao);


		switch(opcao) {
			case 1:
				printf("Digite um valor a ser inserido: ");
				scanf("%d",&valor);
				inserirInicio(&lista,valor);
				break;
			case 2:
				imprimir(&lista);
				break;
			case 3:
				printf("Finalizando... \n");
				break;
			default:
				printf("Opcao Invalida!\n");
		}
	}while(opcao!=3);

	






//vetor
	int vet[10] = {10,11,12,13,14,15,16,17,18,19};
	int vet2[10];

//imprimirVetor(vet,10);
//preencheVetor(vet2, 10);

//preencherVetorInt(vet,10);
//imprimirVetor(vet,10);


	/*
	//primeiro ponteiro e a primeira posicao do vetor tem o mesmo endereco de memoria
	printf("%p\t%p\n",vet, &vet[0]);


	for(i = 0; i < 10 ; i++){
		printf("\n %d \n ",*(vet+i));
	}

	valor1 = &valor2;
	letra1 = &letra2;


	uso * quando eu quero criar um ponteiro ou quando eu quero ler o conteudo do ponteiro.


	//variavel
	printf("\nValor da variavel valor2: %d \n",valor2);
	printf("Endereco da variavel valor2: %p \n",&valor2);

	//ponteiro
	printf("Conteudo da variavel valor1: %p\n ",valor1);
	printf("Conteudo apontado pela variavel valor1 %d \n", *valor1);


	//variavel
	printf("\nValor da variavel letra2: %d \n",letra2);
	printf("Endereco da variavel letra2: %p \n",&letra2);

	//ponteiro
	printf("Conteudo da variavel letra1: %p\n ",letra1);
	printf("Conteudo apontado pela variavel letra1 %d \n", *letra1);

	*/

	return 0;
}