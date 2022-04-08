/*
 * validaciones.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Agostin
 */
#include "validaciones.h"

int validacionDosCaracteres (char *mensaje, char caracterUno, char caracterDos)
{
	char charIngresado;
	printf(mensaje);
	fflush (stdin);
	charIngresado = toupper(getchar());
	while (charIngresado != caracterUno && charIngresado != caracterDos)
	{
		printf ("Ingrese una opcion valida (%c/%c): ", caracterUno, caracterDos);
		fflush (stdin);
		charIngresado = toupper(getchar());
	}
	return (charIngresado == caracterUno);
}

int validacionCaracter (char *mensaje, char caracter)
{
	char charIngresado;
	printf(mensaje);
	fflush (stdin);
	charIngresado = toupper(getchar());
	while (charIngresado != caracter)
	{
		printf ("Caracter incorrecto. Ingrese %c para continuar: ", caracter);
		fflush (stdin);
		charIngresado = toupper(getchar());
	}
	return 0;
}


//-----------------------------------------------------------------------------------------------------

int getInt(int* pNumeroIngresado, char* mensaje, char* mensajeError, int min, int max, int reintentos)
{
	int auxNum;
	int rtn = -1;
	while (reintentos > 0)
	{
		printf (mensaje);

		if (scanf ("%d", &auxNum) == 1)
		{
			if (auxNum >= min && auxNum <= max)
			{
				*pNumeroIngresado = auxNum;
				rtn = 1;
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
		rtn = 0;
	}
	return rtn;
}

int getIntRange (int* pNumeroIngresado, char* mensaje, char* mensajeError, int min, int max)
{
	int auxNum;
	int rtn = -1;
	while (1)
	{
		printf (mensaje);

		if (scanf ("%d", &auxNum))
		{
			if (auxNum >= min && auxNum <= max)
			{
				*pNumeroIngresado = auxNum;
				rtn = 1;
				break;
			}
		}

		fflush(stdin);
		printf (mensajeError);
	}
	return rtn;
}

int getIntPositivo (int* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	int auxNum;
	int rtn = 0;
	while (1)
	{
		printf (mensaje);

		if (scanf ("%d", &auxNum))
		{
			if (auxNum > 0)
			{
				*pNumeroIngresado = auxNum;
				rtn = 1;
				break;
			}
		}

		fflush(stdin);
		printf (mensajeError);
	}
	return rtn;
}


int getIntNegativo(int* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	int auxNum;
	int rtn = 0;
	while (1)
	{
		printf (mensaje);

		if (scanf ("%d", &auxNum))
		{
			if (auxNum < 0)
			{
				*pNumeroIngresado = auxNum;
				rtn = 1;
				break;
			}
		}

		fflush(stdin);
		printf (mensajeError);
	}
	return rtn;
}

int getIntAlone (int* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	int auxNum;
	int rtn = 0;
	while (1)
	{
		printf (mensaje);

		if (scanf ("%d", &auxNum))
		{

			*pNumeroIngresado = auxNum;
			rtn = 1;
			break;
		}
		fflush(stdin);
		printf (mensajeError);
	}
	return rtn;
}

//--------------------------------------------------------------------------------------------------------------

int getFloat(float* pNumeroIngresado, char* mensaje, char* mensajeError, float min, float max, int reintentos)
{
	float auxNum;
	while (reintentos > 0)
	{
		printf (mensaje);

		if (scanf ("%f", &auxNum))
		{
			if (auxNum >= min && auxNum <= max)
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

int getFloatAlone(float* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	float auxNum;
	while (1)
	{
		printf (mensaje);

		if (scanf ("%f", &auxNum))
		{
			*pNumeroIngresado = auxNum;
			return 1;
			break;
		}

		fflush(stdin);
		printf (mensajeError);
	}
	return 0;
}

//--------------------------------------------------------------------------------------------------------------

int getDouble(double* pNumeroIngresado, char* mensaje, char* mensajeError, double min, double max, int reintentos)
{
	double auxNum;
	while (reintentos > 0)
	{
		printf (mensaje);

		if (scanf ("%lf", &auxNum))
		{
			if (auxNum >= min && auxNum <= max)
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

int getDoubleAlone(double* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	double auxNum;
	while (1)
	{
		printf (mensaje);

		if (scanf ("%lf", &auxNum))
		{
			*pNumeroIngresado = auxNum;
			return 1;
			break;
		}

		fflush(stdin);
		printf (mensajeError);
	}
	return 0;
}

void saltoDeLinea (void)
{
	puts ("------------------------------");
}
