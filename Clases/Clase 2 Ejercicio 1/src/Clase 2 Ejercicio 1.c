/*
 ============================================================================
 Name        : Clase.c
 Author      : Agust�n
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Pedir 10 numeros al usuario
Mostrar el maximo y minimo a medida que se ingresan los numeros.
 */

#include <stdio.h>
#include <stdlib.h>
#define MAX_NROS 10

int main(void) {
	setbuf (stdout,NULL);

	int nroIngresado;
	int maximo;
	int minimo;
	int contador;

	for (contador = 0; contador < MAX_NROS ; contador++)
	{
		printf ("Ingrese un N�mero (ha ingresado %d n�meros): ", contador);
		fflush (stdin);
		scanf ("%d", &nroIngresado);

		if (contador == 0)
		{
			maximo = nroIngresado;
			minimo = nroIngresado;
		}
		else
		{
			if (nroIngresado > maximo)
			{
				maximo = nroIngresado;
			}

			if (nroIngresado < minimo)
			{
				minimo = nroIngresado;
			}
		}

		printf ("El numero m�ximo es: %d \n", maximo);
		printf ("El numero m�nimo es: %d \n", minimo);
	}

	printf ("Fin del ingreso de n�meros");

	return EXIT_SUCCESS;
}
