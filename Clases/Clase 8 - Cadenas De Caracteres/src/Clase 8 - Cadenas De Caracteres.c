/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
// Clase con Cadenas de caracteres

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD 2
#define MAX_CHARS 10

int main(void) {
	setbuf (stdout, NULL);

	//Array Vector Unidimensional

	char cadena1[5] = "Juan";
	char cadena2[5] = {'A', 'B', 'C', 'D', '\0'};
	char cadena3[] = "Hola"; //El tamaño de la cadena lo dicta como la inicializo aca. Va a tener 5 de tamaño

	//VECTOR BIDIMENCIONAL

	//char arrayBi[CANTIDAD][MAX_CHARS] = {"Juan", "Pepe"};


	printf ("La cadena 1 es: %s y su tamaño es de: %d\n", cadena1, sizeof(cadena1));
	printf ("La cadena 2 es: %s y su tamaño es de: %d\n", cadena2, sizeof(cadena2));
	printf ("La cadena 3 es: %s y su tamaño es de: %d\n", cadena3, sizeof(cadena3));
	return EXIT_SUCCESS;
}
