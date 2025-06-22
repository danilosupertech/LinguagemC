#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Manipulação de arquivos de texto



int main(void) {




	/*
	FILE *file;
	file = fopen("teste.txt","w");
	fprintf(file,"Pao com mortadela.");
	fclose(file);
	return 0;
	

int x, y, z;

FILE *file;
file = fopen("numeros.txt","r");

if(file == NULL){
	printf("Arquivo nao pode ser aberto. Adios Baby !\n");
	system("pause");
	return 0; 
}


fscanf(file,"%i %i %i",&x,&y,&z);

printf("%i -- %i -- %i \n",x,y,z);

fclose(file);

system("pause");
return 0;
*/

FILE *file;
file = fopen("string.txt","r");


if(file == NULL){
	printf("Arquivo nao pode ser aberto. Adios Baby !\n");
	getchar();
	exit(0); 
}

char frase[100];


/*

poderia usar também while (fgets(frase, sizeof(frase), file) != NULL) {};

condição do while aceita qualquer valor não nulo como verdadeiro. E como fgets() 
retorna NULL ao falhar ou ao atingir o fim do arquivo, essa forma funciona perfeitamente.
*/

    while (fgets(frase, sizeof(frase), file)) {
        printf("%s", frase); // Imprime cada linha lida
    }





printf("\n");
fclose(file);
system("pause");
return 0;

}