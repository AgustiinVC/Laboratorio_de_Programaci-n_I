/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
Funciones como usarlas y elementos
 */

#include <stdio.h>
#include <stdlib.h>

//Funciones

// RETORNO - NOMBRE (ARGUMENTOS....0 - INFINITOS);
// RETORNO TIPO DE DATO: int - float - double - char - void - void*
// NOMBRE   LO QUE USTEDES QUIERAN PONERLE....PERO QUE TENGA SIGNIFICADO
// ARGUMENTO - LAS VARIABLES DE ENTRADA

int sumaNro (int numA, int numB); //Prototipo cabecera
int multiplicaNro (int numA, int numB);
float divisionNro (float dividendo, float divisor, float* rtadivision);
int restaNro (int numA, int numB);

int main(void) {
	setbuf (stdout, NULL);
	int numUno;
	int numDos;
	int suma;
	int multiplicar;
	float division;
	int resta;

	printf ("Ingrese el primer número: ");
	fflush(stdin);
	scanf ("%d", &numUno);

	printf ("Ingrese el segundo número: ");
	fflush(stdin);
	scanf ("%d", &numDos);

	suma = sumaNro (numUno, numDos);
	multiplicar = multiplicaNro (numUno, numDos);
	resta = restaNro (numUno, numDos);

	printf ("\nLa suma es: %d \n",suma);
	printf ("La multiplicación es: %d \n", multiplicar);

	if (divisionNro (numUno, numDos, &division))
	{
		printf ("La division es: %f \n", division);
	}
	else
	{
		puts ("No se puede realizar la división.");
	}
	printf ("La resta es: %d \n", resta);

	return EXIT_SUCCESS;
}

int sumaNro (int numA, int numB)
{
	int suma;
	suma = numA + numB;
	return suma;
}

int multiplicaNro (int numA, int numB)
{
	int multiplicar;
	multiplicar = numA * numB;
	return multiplicar;
}

float divisionNro (float dividendo, float divisor, float* rtadivision)
{
	int rtn;
	if (divisor != 0)
	{
		*rtadivision = dividendo / divisor;  //modifico directo en la direccion de memoria donde esta la variable resultado
		rtn = 1;
	}
	else
	{
		rtn = 0;
	}

	return rtn;
}

int restaNro (int numA, int numB)
{
	int resta;

	resta = numA - numB;

	return resta;
}
