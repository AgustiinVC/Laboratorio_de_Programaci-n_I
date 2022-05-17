/*
 * validaciones.c
 *
 *  Created on: 5 abr. 2022
 *      Author: Agostin
 */
#include "validaciones.h"

int validacionDosCaracteres (char* mensaje, char caracterUno, char caracterDos)
{
	char charIngresado;
	int retorno = -1;

	if (mensaje != NULL)
	{
		retorno = 0;
		printf(mensaje);
		fflush (stdin);
		charIngresado = toupper(getchar());
		while (charIngresado != caracterUno && charIngresado != caracterDos)
		{
			printf ("Ingrese una opcion valida (%c/%c): ", caracterUno, caracterDos);
			fflush (stdin);
			charIngresado = toupper(getchar());
		}
		if (charIngresado == caracterUno)
		{
			retorno = 1;
		}
	}
	return retorno;
}

int validacionCaracter (char *mensaje, char caracter)
{
	char charIngresado;
	int retorno = -1;

	if (mensaje != NULL)
	{
		retorno = 0;
		printf(mensaje);
		fflush (stdin);
		charIngresado = toupper(getchar());
		while (charIngresado != caracter)
		{
			printf ("Caracter incorrecto. Ingrese %c para continuar: ", caracter);
			fflush (stdin);
			charIngresado = toupper(getchar());
		}
	}

	return retorno;
}


//-----------------------------------------------------------------------------------------------------

int getInt(int* pNumeroIngresado, char* mensaje, char* mensajeError, int min, int max, int reintentos)
{
	int auxNum;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL && max > min && reintentos > 0)
	{
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
	}
	return rtn;
}

int getIntRange (int* pNumeroIngresado, char* mensaje, char* mensajeError, int min, int max)
{
	int auxNum;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL && max > min)
	{
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
	}
	return rtn;
}

int getIntPositivo (int* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	int auxNum;
	int rtn = 0;
	if (mensaje != NULL && mensajeError != NULL)
	{
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
	}
	return rtn;
}


int getIntNegativo(int* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	int auxNum;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL)
	{
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
	}
	return rtn;
}

int getIntAlone (int* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	int auxNum;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL)
	{
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
			puts (mensajeError);
		}
	}
	return rtn;
}

//--------------------------------------------------------------------------------------------------------------

int getFloat(float* pNumeroIngresado, char* mensaje, char* mensajeError, float min, float max, int reintentos)
{
	float auxNum;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL && max > min && reintentos > 0)
	{
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
			rtn = 0;
		}
		else
		{
			*pNumeroIngresado = auxNum;
			rtn = 1;
		}
	}
	return rtn;

}

int getFloatAlone(float* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	float auxNum;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL)
	{
		while (1)
		{
			printf (mensaje);

			if (scanf ("%f", &auxNum))
			{
				*pNumeroIngresado = auxNum;
				rtn = 1;
				break;
			}

			fflush(stdin);
			printf (mensajeError);
		}
	}
	return rtn;
}

//--------------------------------------------------------------------------------------------------------------

int getDouble(double* pNumeroIngresado, char* mensaje, char* mensajeError, double min, double max, int reintentos)
{
	double auxNum;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL && max > min && reintentos > 0)
	{
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
			rtn = 0;
		}
		else
		{
			*pNumeroIngresado = auxNum;
			rtn = 1;
		}
	}
	return rtn;

}

int getDoubleAlone(double* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	double auxNum;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL)
	{
		while (1)
		{
			printf (mensaje);

			if (scanf ("%lf", &auxNum))
			{
				*pNumeroIngresado = auxNum;
				rtn = 1;
				break;
			}

			fflush(stdin);
			printf (mensajeError);
		}
	}
	return rtn;
}

//------------------------------------------------------------------------------------------------------------
//Mejoras de Visualizacion

void saltoDeLinea (void)
{
	puts ("------------------------------");
}

void presionarEnter (void)
{
  printf ( "Presiona ENTER para continuar..." );
  fflush (stdin);
  getchar();
}
