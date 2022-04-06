/*
 * BibliotecaOperaciones.c
 *
 *  Created on: 31 mar. 2022
 *  Author: Agostin
 *
 *  Aca van solo el desarrollo de las funciones que estan en el prototipo en el .h
 *  Tambien la llamada a la biblioteca .h donde estan los prototipos
 *
 */

#include "BibliotecaOperaciones.h"

float sumar (float numUno, float numDos)
{
	float suma;
	suma = numUno + numDos;
	return suma;
}

float restar (float numUno, float numDos)
{
	float resta;
	resta = numUno - numDos;
	return resta;
}

float multiplicar (float numUno, float numDos)
{
	float multiplicar;
	multiplicar = numUno * numDos;
	return multiplicar;
}

float dividirInt (int numUno, int numDos)
{
	float division;

	if (numDos != 0)
	{
		division = (float) numUno / numDos;
	}
	else
	{
		division = 0;
	}
	return division;
}

float dividir (float numUno, float numDos)
{
	float division;

	if (numDos != 0)
	{
		division = numUno / numDos;
	}
	else
	{
		division = 0;
	}
	return division;
}
