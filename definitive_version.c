#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_and_dynamically_fit_to(char**);

int main() {
	char* heap_string = NULL;
	
	printf("Give a text of any size:\n");
	printf(">>> "); fflush(stdout);
	read_and_dynamically_fit_to(&heap_string);
	
	printf("String stored: %s\n", heap_string);
	printf("len: %d\n", strlen(heap_string));

	printf("Give another piece of text:\n");
	printf(">>> "); fflush(stdout);
	read_and_dynamically_fit_to(&heap_string);
	
	printf("Another string stored: %s\n", heap_string);
	printf("len: %d\n", strlen(heap_string));

	if(heap_string != NULL) free(heap_string);
	return 0;
}

void read_and_dynamically_fit_to(char** heap_string) {
	int bytes_to_read_initially = 1, endline_size = 1;
	int size = bytes_to_read_initially + endline_size;

	if((*heap_string) != NULL) { 
		free(*heap_string); 
		(*heap_string) = NULL;
		(*heap_string) = (char*)realloc((*heap_string),size*sizeof(char));
	} else {
		(*heap_string) = (char*)malloc(size*sizeof(char));
	}

	// error handling after allocating/resizing memory
	if((*heap_string) == NULL) {
		printf("No memory could be provided\n");
		printf("Nothing will be assigned\n");
	} else {
		fgets(*heap_string, size, stdin);
		if( (*heap_string)[0] != '\n' ) {
			char c = 'a';
			while((c = getchar()) != '\n') {
				size++;
				(*heap_string) = (char*)realloc((*heap_string), size*sizeof(char));
				if((*heap_string) == NULL) {
					printf("The OS couldn't provide memory to you\n");
					printf("Nothing will be assigned\n");
					printf("Data will be erased\n");
					do { } while(getchar() != '\n');
					return;
				}
				(*heap_string)[size-2] = c;
			}
			(*heap_string)[size-1] = '\0';
		} else { 
			(*heap_string)[0] = '\0'; 
		}
	}
	return;
}
