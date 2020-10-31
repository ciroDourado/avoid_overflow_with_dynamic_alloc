#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_and_dynamically_fit_to(char**);
void read_a_slice(char**, int);

int main() {
	char* heap_string = NULL;

	printf("\nTesting read with dynamic fit:\n");
	printf(">>> "); fflush(stdout);
	read_and_dynamically_fit_to(&heap_string);
	
	printf("String stored: %s\n", heap_string);
	printf("len: %d\n", strlen(heap_string));
	
	printf("\nTesting read with dynamic fit, and take only a part:\n");
	printf(">>> "); fflush(stdout);
	read_a_slice(&heap_string, 3);
	
	printf("String stored: %s\n", heap_string);
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
			// core of this function
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
			} // end reading from stdin, and automatically allocating memory
			(*heap_string)[size-1] = '\0';
		} else { 
			(*heap_string)[0] = '\0'; 
		} // check wether it was given something, or nothing
	} // end error handling
	return;
}

void read_a_slice(char** heap_string, int limit) {
    read_and_dynamically_fit_to(heap_string);
	
    if((*heap_string) == NULL) {
        printf("Sorry, can't read from it.\n");
    } else {
        if(limit < 0 || limit >= strlen(*heap_string)) {
            printf("Invalid size!\n");
            printf("Nothing to be done.\n");
        } else {
            char temporary_stack_string[limit+1];
            strncpy(temporary_stack_string, (*heap_string), sizeof(temporary_stack_string));
            
            free(*heap_string);
            (*heap_string) = NULL;
            (*heap_string) = (char*)realloc((*heap_string), (limit+1)*sizeof(char));
		    if(*heap_string == NULL) {
			    printf("The OS couldn't provide memory to you\n");
			    printf("Nothing will be assigned\n");
			    printf("Data will be erased\n");
			    return;
		    } // in case of some run out of memory
		    
		    strncpy((*heap_string), temporary_stack_string, sizeof(temporary_stack_string));
		    (*heap_string)[limit] = '\0';
        } // check for an invalid size
    } // check for a fault on reading to it
} // end read_a_slice

















