#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
	// funções nativas do windows
	#define clear_terminal() system("cls")
	#define pause_terminal() system("pause")
#else
	// funções nativas de sistemas unix-like
	#define clear_terminal() system("clear")
	#define pause_terminal() printf("Enter para continuar\n"); getchar()
#endif

void read_and_dynamically_fit_to(char**);
void read_a_slice(char**, int);
