// funcoesVet.h
// --------------------------------------------------
// Módulo de operações com vetor encapsulado em struct
// --------------------------------------------------

#ifndef FUNCOESVET_H
#define FUNCOESVET_H

#define MAX_VET 3  // Tamanho fixo do vetor usado em todas as operações
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0])) // Macro para medir o tamanho de um array

/**
 * Struct que representa um vetor de inteiros com tamanho fixo.
 */
typedef struct {
    int valores[MAX_VET];
} Vetor;

/**
 * Solicita ao usuário a inserção de valores e retorna a struct preenchida.
 * @param tam_vetor Quantidade de valores a serem inseridos.
 * @return Vetor preenchido.
 */
 
 
Vetor soInsereVetor(int tam_vetor);

/**
 * Versão alternativa que apenas insere e imprime valores (sem retorno).
 * @param tam_vetor Quantidade de valores.
 */
void inserirVetor(int tam_vetor);

/**
 * Retorna a quantidade de números pares em um vetor informado.
 *
 * @param v Struct Vetor contendo os dados originais.
 * @return Quantidade de números pares no vetor.
 */
int QtdParesVetor(Vetor v);

/**
 * Retorna o menor valor do vetor.
 *
 * @param v Struct Vetor contendo os dados originais.
 * @return Menor valor encontrado no vetor.
 */
int MenorVlVetor(Vetor v);

/**
 * Retorna o maior valor do vetor.
 *
 * @param v Struct Vetor contendo os dados originais.
 * @return Maior valor encontrado no vetor.
 */
int MaiorVlVetor(Vetor v);

/**
 * Ordena os valores do vetor em ordem crescente.
 *
 * @param v Vetor a ser ordenado.
 * @return Vetor ordenado.
 */
Vetor ordenarVetor(Vetor v);

/**
 * Retorna os valores do vetor em ordem inversa.
 *
 * @param v Vetor a ser invertido.
 * @return Vetor invertido.
 */
Vetor inverterVetor(Vetor v);

/**
 * Soma todos os elementos do vetor.
 *
 * @param v Vetor cujos elementos serão somados.
 * @return Soma dos elementos.
 */
int somarElementos(Vetor v);

/**
 * Objetivo:
 * - Criar um array A com 6 inteiros.
 * - Atribuir valores fixos.
 * - Somar A[0], A[1] e A[5].
 * - Modificar A[4] para 100.
 * - Imprimir todos os elementos.
 */
Vetor arrayFixos(void);

#endif

