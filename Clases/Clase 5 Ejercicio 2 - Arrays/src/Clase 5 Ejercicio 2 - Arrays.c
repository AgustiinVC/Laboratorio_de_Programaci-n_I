/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

//Ejercicio: Pedirle al usuario 5 edades y Luego imprimir las 5 edades.
//Definir un array de 5 posiciones y usar la funcion getNro para pedir los valores

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

#define EDADES_SIZE 5

void imprimirArray (int listaEdades[], int len);

int main(void) {
	setbuf (stdout, NULL);

	int edades [EDADES_SIZE];
	int i;

	for (i = 0; i < EDADES_SIZE; i++)
	{
		if (getInt (&edades[i], "Ingrese una edad: ", "Edad ingresada erronea.", 1, 120, 3))
		{
			puts ("Edad ingresada valida.");
		}
		else
		{
			puts ("Error. Ingresaste muchas veces mal. Proxima edad.");
		}
	}

	saltoDeLinea();
	imprimirArray(edades,EDADES_SIZE);

	return EXIT_SUCCESS;
}

void imprimirArray (int listaEdades[], int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		printf ("La edad ingresada es: %d.\n", listaEdades[i]);
	}
}
