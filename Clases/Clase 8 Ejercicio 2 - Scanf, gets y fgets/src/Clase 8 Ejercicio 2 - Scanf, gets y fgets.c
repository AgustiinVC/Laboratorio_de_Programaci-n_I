/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CANTIDAD 2
#define MAX_CHARS 10

int main(void)
{
	setbuf (stdout, NULL);

	int n;
	char nombreA[MAX_CHARS];
	char nombreB[MAX_CHARS];

	/*  scanf ()   */

	fflush (stdin);
	puts ("Dame un entero: ");
	scanf ("%d", &n);
	printf ("El entero es: %d\n", n);

	//Poco seguro y puede pisar memoria al ingresar mas que el maximo de la cadena permite. Conviene no usar

	/* gets() */

	puts ("Dame un nombre: ");
	gets (nombreA);
	printf ("La cadena 1 es: %s\n", nombreA);

	// En gets nos deja el \n en el buffer por lo que hay que hacer un purge luego de usarlo

	/* fgets() */

	puts ("Dame un nombre: ");
	fgets (nombreB, MAX_CHARS, stdin);
	printf ("La cadena 2 es: %s\n", nombreB);

	// El mas conveniente a usar. Especificamos el maximo de caracteres que ingresamos y al final le agrega el \0 automaticamente.
	//stdin puede cambiarse para escribit en un txt.

	/* String.h funciones */




	return EXIT_SUCCESS;
}
