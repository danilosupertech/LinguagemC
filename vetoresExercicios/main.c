// vetoresExercicios.c
// --------------------------------------------------
// Programa principal que utiliza funções do módulo funcoesVet
// para manipular vetores: inserção, ordenação, inversão e soma.
// --------------------------------------------------

#include <stdio.h>
#include "funcoesVet.h"



/**
 * Imprime os valores contidos em uma struct Vetor.
 * @param v Struct contendo os valores.
 * @param titulo Título descritivo para o grupo de valores.
 */
 
void imprimirVetor(Vetor v, const char *titulo) {
    printf("\n--- %s ---\n", titulo);
    for (int i = 0; i < MAX_VET; i++) {
        printf("Valor[%d] = %d\n", i, v.valores[i]);
    }
}

int main() {
	
	

	
/*

Imagine que sizeof é uma régua de bytes.

Se você medir o prédio inteiro (array real): ele te dá o prédio todo.

Mas se você medir só o cartão do endereço (ponteiro): ele te dá o tamanho do cartão, não do prédio

	Se você passa um vetor para uma função, ele vira ponteiro. 
	Então sizeof(v) dentro da função vai te dar o 
	tamanho do ponteiro, e não do vetor original.

*/
int numeros[MAX_VET];

// Se você precisa saber quantos elementos tem um vetor, faça isso somente no escopo onde ele foi declarado:

int tamanho = sizeof(numeros) / sizeof(numeros[0]);
printf("O tamanho do array e: %d\n", tamanho);
	
		
    // Recebe os valores informados pelo usuário
    Vetor v = soInsereVetor(MAX_VET);
    imprimirVetor(v, "Valores originais");

	/*Imprime o maior valor do vetor*/
	printf("\n\n O Maior valor: %i ", MaiorVlVetor(v));

	/*Imprime o menor  valor do vetor*/
	printf("e o Menor valor %i do vetor.\n", MenorVlVetor(v));

	int pares = QtdParesVetor(v);
	printf("--- Quantidade de valores pares no vetor: %d\n", pares);



    Vetor ordenado = ordenarVetor(v);
    imprimirVetor(ordenado, "Vetor ordenado");
	
	/* 
	ordenarVetor(v) -> usar a função ordenar para depois inverter
	ou v -> se quiser usar o vetor original
	*/
    Vetor invertido = inverterVetor(ordenarVetor(v));
    imprimirVetor(invertido, "Vetor invertido");

    int soma = somarElementos(v);
    printf("\n--- Soma dos elementos: %d ---\n", soma);


  printf("\n======================== ** ========================\n");
    Vetor resultado = arrayFixos();
    imprimirVetor(resultado, "Vetor alteracoes");
    
    return 0;
}
