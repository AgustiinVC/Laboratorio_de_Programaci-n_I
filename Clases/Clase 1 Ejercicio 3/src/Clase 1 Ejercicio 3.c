/*
 ============================================================================
 Name        : Clase.c
 Author      : Agust�n
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
// Ingreso un numero n de numeros y hallo el promedio
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf (stdout,NULL);

	int nroIngresado;
	int sumaTotal = 0;
	char respuesta;
	int cantidadNumeros = 0;
	float promedio;

	do
	{
		printf ("Ingrese un n�mero: ");
		fflush(stdin);
		scanf ("%d", &nroIngresado);

		sumaTotal += nroIngresado;

		printf ("�Quiere seguir ingresando n�meros? ");
		fflush(stdin);
		scanf ("%c", &respuesta);

		cantidadNumeros++;
	}
	while (respuesta == 's');

	promedio = (float)sumaTotal / cantidadNumeros;

	printf ("El promedio es: %f",promedio);

	return EXIT_SUCCESS;
}
