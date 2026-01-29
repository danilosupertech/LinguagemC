//main.c
#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char *argv[]) {
	
    int resultado = somadois(5, 3);
    printf("Resultado da soma: %d\n", resultado);
  
    
    int vet1[5] = {1,22,43,54,75};
    
    int tamanho = sizeof(vet1) / sizeof(vet1[0]);
    
    
    
    lervetor(vet1,5);
    
      return 0;
}
