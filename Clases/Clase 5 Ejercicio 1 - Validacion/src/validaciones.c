/*
 * validaciones.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Agostin
 */
#include "validaciones.h"


int getInt(int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int auxNum;
	while (reintentos > 0)
	{
		printf (mensaje);

		if (scanf ("%d", &auxNum) == 1)
		{
			if (auxNum >= minimo && auxNum <= maximo)
			{
				break;
			}
		}

		fflush(stdin);
		reintentos--;
		printf (mensajeError);
		printf ("\nTe quedan %d intentos.\n", reintentos);
	}

	if (reintentos == 0)
	{
		return 0;
	}
	else
	{
		*pNumeroIngresado = auxNum;
		return 1;
	}
}

int getFloat(float* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	float auxNum;
	while (reintentos > 0)
	{
		printf (mensaje);

		if (scanf ("%f", &auxNum) == 1)
		{
			if (auxNum >= minimo && auxNum <= maximo)
			{
				break;
			}
		}

		fflush(stdin);
		reintentos--;
		printf (mensajeError);
		printf ("\n Te quedan %d intentos.\n", reintentos);
	}

	if (reintentos == 0)
	{
		return 0;
	}
	else
	{
		*pNumeroIngresado = auxNum;
		return 1;
	}
}
