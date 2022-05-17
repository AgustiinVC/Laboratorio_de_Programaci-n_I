/*
 ============================================================================
 Name        : h.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 5

int main(void) {
	char nombreA[MAX_CHARS] = "PEPE";
	char nombreB[MAX_CHARS] = "Pepe";

	int rtn;


	//Largo de caracteres de una cadena

	int largo = strlen (nombreA);
	printf ("El largo de NombreA es: %d\n",largo);

	//Copia N cantidad de caracteres

	strncpy (nombreA, nombreB, sizeof(nombreA));
	printf ("El NombreA es: %s\n",nombreA);

	//Compara dos cadenas

	rtn = strncmp (nombreA, nombreB, MAX_CHARS);
	/* retorno == 0 - IGUALEs
	 * RETORNO  > 0 - DESTINO ES MAYOR A ORIGEN
	 * RETORNO  < 0 - ORIGEN ES MAYOR A DESTINO
	 */

	if (rtn == 0)
	{
		puts ("Son Iguales.");
	}
	else if (rtn > 0)
	{
		puts ("NombreA mayor que NombreB");
	}
	else
	{
		puts ("NombreB mayor que NombreA");
	}
	printf ("El valor de rtn es: %d\n",rtn);


	//Concatenar cadenas
	strncat (nombreA, nombreB, sizeof(nombreA));
	printf ("Se copio la siguiente cadena: %s\n", nombreA);

	return EXIT_SUCCESS;
}
