// funcoesVet.c
// -------------------------------------------------------------------
// Implementação das funções de manipulação de vetor encapsulado
// na struct Vetor. Este módulo permite inserir, exibir, ordenar,
// inverter e somar os valores de um vetor de inteiros.
// -------------------------------------------------------------------

#include <stdio.h>
#include "funcoesVet.h"

/**
 * Solicita ao usuário que insira valores inteiros para preencher uma struct Vetor.
 *
 * @param tam_vetor Quantidade de elementos a serem inseridos (deve ser <= MAX_VET).
 * @return Vetor preenchido com os valores inseridos pelo usuário.
 */
Vetor soInsereVetor(int tam_vetor) {
    Vetor v;

    printf("\n---------- Insercao de %d valores inteiros ----------\n", tam_vetor);
    for (int i = 0; i < tam_vetor; i++) {
        printf("Informe o valor da posicao %d: ", i + 1);
        scanf("%d", &v.valores[i]);  // Armazena cada valor no array da struct
    }

    return v;  // Retorna a struct preenchida
}

/**
 * Insere valores inteiros diretamente em um array local e os imprime.
 * Não utiliza struct nem retorna os dados.
 *
 * @param tam_vetor Quantidade de elementos a serem inseridos.
 */
void inserirVetor(int tam_vetor) {
    int valores[tam_vetor];

    printf("\n---------- Insercao de %d valores inteiros ----------\n", tam_vetor);
    for (int i = 0; i < tam_vetor; i++) {
        printf("Informe o valor da posicao %d: ", i + 1);
        scanf("%d", &valores[i]);  // Preenche array local
    }

    // Imprime os valores armazenados
    printf("\n--- Valores inseridos ---\n");
    for (int i = 0; i < tam_vetor; i++) {
        printf("Valor[%d] = %d\n", i, valores[i]);
    }
}

/**
 * Ordena os valores do vetor em ordem crescente (Bubble Sort).
 *
 * @param v Struct Vetor contendo os dados originais.
 * @return Novo Vetor com os valores ordenados.
 */
Vetor ordenarVetor(Vetor v) {
    Vetor ordenado = v;  // Cria cópia local da struct recebida

	printf("\n\n Tamanho em bytes do vetor -> %i \n", sizeof(ordenado.valores));
	printf(" Tamanho em bytes da primeira posicao vetor -> %i \n", sizeof(ordenado.valores[0]));
	printf(" Tamanho do vetor -> %d \n\n\n", sizeof(ordenado.valores)/sizeof(ordenado.valores[0]));


    // Algoritmo de ordenação simples: Bubble Sort
    for (int i = 0; i < MAX_VET - 1; i++) {
        for (int j = i + 1; j < MAX_VET; j++) {
            if (ordenado.valores[i] > ordenado.valores[j]) {
                // Troca os valores se estiverem fora de ordem
                int temp = ordenado.valores[i];
                ordenado.valores[i] = ordenado.valores[j];
                ordenado.valores[j] = temp;
            }
        }
    }

    return ordenado;  // Retorna vetor ordenado
}


/**
 * Retorna a quantidade de números pares em um vetor informado.
 *
 * @param v Struct Vetor contendo os dados originais.
 * @return Quantidade de números pares em um vetor informado..
 */
 int QtdParesVetor(Vetor v){
 	 int qtdPares = 0;  // Inicializa contagem
 	 size_t max = ARRAY_SIZE(v.valores); //Usando a macro criada no Protótipo
	// size_t max = sizeof(v.valores) / sizeof(v.valores[0]);	
	 
    for (size_t i = 0; i < max; i++) {
        if (v.valores[i] % 2 == 0) {
            qtdPares++;
        }
    }

    return qtdPares;	
}


/**
 * Retorna o maior valor do vetor .
 *
 * @param v Struct Vetor contendo os dados originais.
 * @return Valor do Maior valor que encontra-se no vetor.
 */
 int MaiorVlVetor(Vetor v){
	// Maior valor do vetor
	 int valorMaior =0;
	 int MAX = (sizeof(v.valores) / sizeof(v.valores[0]));
	
		for(int i = 0; i < MAX ;i++ ){
			
			if( v.valores[i] > valorMaior){
				
				valorMaior = v.valores[i];
				
			}
			
	 	}
	 	 return valorMaior;	
}

/**
 * Retorna o menor valor do vetor .
 *
 * @param v Struct Vetor contendo os dados originais.
 * @return Valor do Menor valor que encontra-se no vetor.
 */
 int MenorVlVetor(Vetor v){
	// Maior valor do vetor
	 int valorMenor=0;
	 int MAX = (sizeof(v.valores) / sizeof(v.valores[0]));
	
		for(int i = 0; i < MAX ;i++ ){
			
			if( v.valores[i] < valorMenor){
				
				valorMenor = v.valores[i];
				
			}
			
	 	}
	 	 return valorMenor
		  ;	
}

/**
 * Inverte a ordem dos elementos do vetor.
 *
 * @param v Struct Vetor original.
 * @return Novo Vetor com os valores invertidos.
 */
Vetor inverterVetor(Vetor v) {
    Vetor invertido;

    // Copia os elementos em ordem inversa
    for (int i = 0; i < MAX_VET; i++) {
        invertido.valores[i] = v.valores[MAX_VET - 1 - i];
    }

    return invertido;
}

/**
 * Calcula a soma de todos os elementos do vetor.
 *
 * @param v Struct Vetor com os dados.
 * @return Resultado da soma de todos os valores.
 */
int somarElementos(Vetor v) {
    int soma = 0;

    for (int i = 0; i < MAX_VET; i++) {
        soma += v.valores[i];  // Soma acumulada
    }

    return soma;  // Retorna o total
}

/**
 * - Inicializa um vetor com os valores {1, 0, 5, -2, -5, 7}
 * - Calcula e exibe a soma de A[0] + A[1] + A[5]
 * - Altera A[4] para 100
 * - Retorna o vetor final
 */
Vetor arrayFixos(void) {
    Vetor v;

    // a) Atribuição dos valores
    v.valores[0] = 1;
    v.valores[1] = 0;
    v.valores[2] = 5;
    v.valores[3] = -2;
    v.valores[4] = -5;
    v.valores[5] = 7;

    // b) Soma de A[0], A[1] e A[5]
    int soma = v.valores[0] + v.valores[1] + v.valores[5];
    printf("\n🧮 Soma A[0] + A[1] + A[5] = %d\n", soma);

    // c) Altera A[4] para 100
    v.valores[4] = 100;

    // d) O vetor será retornado para ser impresso no main
    return v;
}