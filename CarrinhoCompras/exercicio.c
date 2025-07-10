#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	

int *numero;

  // Aloca espaço para 10 inteiros
    numero = malloc(10 * sizeof(int));
    
    if (numero == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }	
	numero[10];
	numero[0] = 1;
	numero[1] = 2;
	numero[3] = 3;
	numero[3] = 4;
		
		printf("%i\n", numero[0]);
		
		


printf("tamanho novo é %i", (sizeof(numero) / sizeof(numero[0])) );
	
	return 0;	
}

