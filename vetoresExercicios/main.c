// vetoresExercicios.c
// --------------------------------------------------
// Programa principal que utiliza funcoes do modulo funcoesVet
// para manipular vetores: insercao, ordenacao, inversao e soma.
// --------------------------------------------------

#include <stdio.h>
#include "funcoesVet.h"

/**
 * Imprime os valores contidos em uma struct Vetor.
 * @param v Struct contendo os valores.
 * @param titulo Titulo descritivo para o grupo de valores.
 */
void imprimirVetor(Vetor v, const char *titulo) {
    printf("\n--- %s ---\n", titulo);
    for (int i = 0; i < MAX_VET; i++) {
        printf("Valor[%d] = %d\n", i, v.valores[i]);
    }
}

int main() {

    /*
    Imagine que sizeof e uma regua de bytes.

    Se voce medir o predio inteiro (array real): ele te da o predio todo.

    Mas se voce medir so o cartao do endereco (ponteiro): ele te da o tamanho do cartao, nao do predio.

    Quando voce passa um vetor para uma funcao, ele vira ponteiro.
    Entao sizeof(v) dentro da funcao vai retornar o tamanho do ponteiro, e nao do vetor original.
    */

    int numeros[MAX_VET];

    // Para saber quantos elementos ha em um vetor, faca isso no escopo onde ele foi declarado:
    int tamanho = sizeof(numeros) / sizeof(numeros[0]);
    printf("O tamanho do array e: %d\n", tamanho);

    // Recebe os valores informados pelo usuario
    Vetor v = soInsereVetor(MAX_VET);
    imprimirVetor(v, "Valores originais");

    // Imprime o maior valor do vetor
    printf("\n\nO maior valor: %i ", MaiorVlVetor(v));

    // Imprime o menor valor do vetor
    printf("e o menor valor: %i\n", MenorVlVetor(v));

    int pares = QtdParesVetor(v);
    printf("--- Quantidade de valores pares no vetor: %d\n", pares);

    Vetor ordenado = ordenarVetor(v);
    imprimirVetor(ordenado, "Vetor ordenado");

    /*
    ordenarVetor(v) -> usar a funcao ordenar para depois inverter
    ou usar v diretamente -> se quiser usar o vetor original
    */
    Vetor invertido = inverterVetor(ordenarVetor(v));
    imprimirVetor(invertido, "Vetor invertido");

    int soma = somarElementos(v);
    printf("\n Soma dos elementos: %d --->\n", soma);

    printf("\n======================== ** ========================\n");

    Vetor resultado = arrayFixos();
    imprimirVetor(resultado, "Vetor alteracoes");



	
	  




    return 0;
}

