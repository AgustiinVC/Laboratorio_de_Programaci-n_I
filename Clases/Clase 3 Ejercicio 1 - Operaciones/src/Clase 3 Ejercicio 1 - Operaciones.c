/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Operaciones (Suma, Resta, Multiplicacion, division) con biblioteca en archivo aparte
 ============================================================================


 */

#include "BibliotecaOperaciones.h"

int main(void) {
	setbuf (stdout,NULL);

	float nroUno;
	float nroDos;
	float suma;
	float resta;
	float multiplicacion;
	int divisionInt;
	float division;

	printf ("Ingrese un número: ");
	fflush(stdin);
	scanf("%f", &nroUno);
	printf ("Ingrese un número: ");
	fflush(stdin);
	scanf("%f", &nroDos);

	suma = sumar (nroUno, nroDos);
	resta = restar (nroUno, nroDos);
	multiplicacion = multiplicar (nroUno, nroDos);

	printf ("La suma es: %.2f\n", suma);
	printf ("La resta es: %.2f\n", resta);
	printf ("La multiplicacion es: %.2f\n", multiplicacion);

	if (nroDos != 0)
	{
		divisionInt = dividirInt (nroUno, nroDos);
		division = dividir (nroUno, nroDos);
		printf ("La división con Enteros es: %d\n", divisionInt);
		printf ("La division es: %.2f", division);
	}
	else
	{
		puts ("No se puede realizar la división.");
	}


	return EXIT_SUCCESS;
}
