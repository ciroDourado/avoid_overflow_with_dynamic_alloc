#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char* heap_string;
	int bytes_to_read = 1, endline_size = 1;
	int size = bytes_to_read + endline_size;
	// nossa string começa com capacidade para
	// guardar apenas o primeiro caracter dado
	// mais uma casa para o caracter especial	
	heap_string = (char*)malloc(size*sizeof(char));
	
	printf("Dê uma frase de qualquer tamanho:\n");
	printf(">>> "); fflush(stdout);
	// o fgets lê o que for dado ao stdin,
	// mas salva apenas size-1 caracteres,
	// ou seja, salva apenas o que nossa 
	// string consegue armazenar
	fgets(heap_string, size, stdin);

	if(heap_string[0] != '\n') {	
		char c = 'a';
		while((c = getchar()) != '\n') {
			size++;
			heap_string = (char*)realloc(heap_string,size*sizeof(char));
			heap_string[size-2] = c;
		}
	} else { heap_string[0] = '\0'; }
	// o primeiro trecho do código acima não salva
	// o '\n', justamente por ignorá-lo
	// já o else trata do caso em que nada foi dado
	// ao stdin, apenas '\n', forçando o programa
	// a trocar o caracter especial.
		
	printf("Espaço que a string ocupa na memória: %d\n", strlen(heap_string));
	printf("O que você escreveu foi: %s\n", heap_string);
	free(heap_string);
	
	return 0;
}
