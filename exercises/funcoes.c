//funcoes.c
#include "funcoes.h"
#include <stdio.h>
#include <stdlib.h>

int somadois(int a,int b){
	return a + b;
}

void lervetor(int a[], int tamanho){
	
	int tamanhovet = sizeof(a[tamanho]);
	
	 printf("Tamano do vetor %i",tamanhovet);

	for(int i = 0; i <= tamanhovet+1; i++){
		printf("O valor da posicao %i e %i \n",i,a[i]);
	} 
	
//	return 0;	
}