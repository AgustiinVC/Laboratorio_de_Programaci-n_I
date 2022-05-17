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
	char buffer[64];
	int aux;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL && max > min && reintentos > 0)
	{
		while (reintentos > 0)
		{
			printf (mensaje);

			if (myGets(buffer, sizeof (buffer))==0 && esNumerica(buffer))
			{
				aux = atoi (buffer);
				if (aux >= min && aux <= max)
				{
					*pNumeroIngresado = aux;
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
	char buffer[64];
	int aux;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL && max > min)
	{
		while (1)
		{
			printf (mensaje);

			if (myGets(buffer, sizeof (buffer))==0 && esNumerica(buffer))
			{
				aux = atoi (buffer);
				if (aux >= min && aux <= max)
				{
					*pNumeroIngresado = aux;
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
	char buffer[64];
	int rtn = 0;
	if (mensaje != NULL && mensajeError != NULL)
	{
		while (1)
		{
			printf (mensaje);

			if (myGets(buffer, sizeof (buffer))==0 && esNumerica(buffer))
			{
				if (buffer > 0)
				{
					*pNumeroIngresado = atoi (buffer);
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
	char buffer[64];
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL)
	{
		while (1)
		{
			printf (mensaje);

			if (myGets(buffer, sizeof (buffer))==0 && esNumerica(buffer))
			{
				if (buffer < 0)
				{
					*pNumeroIngresado = atoi (buffer);
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
	char buffer[64];
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL)
	{
		while (1)
		{
			printf (mensaje);

			if (myGets(buffer, sizeof (buffer)) == 0 && esNumerica(buffer))
			{

				*pNumeroIngresado = atoi (buffer);
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
	char buffer[64];
	float aux;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL && max > min && reintentos > 0)
	{
		while (reintentos > 0)
		{
			printf (mensaje);

			if (myGets(buffer, sizeof (buffer)) == 0 && esNumericaDecimal(buffer))
			{
				aux = atof (buffer);
				if (aux >= min && aux <= max)
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
			*pNumeroIngresado = aux;
			rtn = 1;
		}
	}
	return rtn;

}

int getFloatAlone(float* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	char buffer[64];
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL)
	{
		while (1)
		{
			printf (mensaje);

			if (myGets(buffer, sizeof (buffer)) == 0 && esNumericaDecimal(buffer))
			{
				*pNumeroIngresado = atof (buffer);
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
	char buffer[128];
	double aux;
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL && max > min && reintentos > 0)
	{
		while (reintentos > 0)
		{
			printf (mensaje);

			if (myGets(buffer, sizeof (buffer)) == 0 && esNumericaDecimal(buffer))
			{
				aux = atof(buffer);
				if (aux >= min && aux <= max)
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
			*pNumeroIngresado = aux;
			rtn = 1;
		}
	}
	return rtn;

}

int getDoubleAlone(double* pNumeroIngresado, char* mensaje, char* mensajeError)
{
	char buffer[128];
	int rtn = -1;
	if (mensaje != NULL && mensajeError != NULL)
	{
		while (1)
		{
			printf (mensaje);

			if (myGets(buffer, sizeof (buffer)) == 0 && esNumericaDecimal(buffer))
			{
				*pNumeroIngresado = atof (buffer);
				rtn = 1;
				break;
			}

			fflush(stdin);
			printf (mensajeError);
		}
	}
	return rtn;
}

//-----------------------------------------------------------------------------------------------------------
//Funciones estaticas

static int esNumerica ( char * cadenaPosiblesNumeros)
{
	int i = 0;
	int retorno = 1;
	if (cadenaPosiblesNumeros != NULL && strlen (cadenaPosiblesNumeros) > 0)
	{
		while (cadenaPosiblesNumeros[i] != '\0' )
		{
			if (cadenaPosiblesNumeros[i] < '0' || cadenaPosiblesNumeros[i] > '9' )
			{
				if (cadenaPosiblesNumeros[i] == '-' && i == 0) continue;

				retorno = 0;
				break ;
			}
			i++;
		}
	}
	return retorno;
}

static int esNumericaDecimal ( char * cadenaPosiblesNumeros)
{
	int i = 0;
	int flagPunto = 0;
	int retorno = 1;
	if (cadenaPosiblesNumeros != NULL && strlen (cadenaPosiblesNumeros) > 0)
	{
		while (cadenaPosiblesNumeros[i] != '\0' )
		{
			if (cadenaPosiblesNumeros[i] < '0' || cadenaPosiblesNumeros[i] > '9')
			{
				if (cadenaPosiblesNumeros[i] == '-' && i == 0) continue;

				if ( (cadenaPosiblesNumeros[i] == ',' || cadenaPosiblesNumeros[i] == '.') && !flagPunto)
				{
					flagPunto = 1;
					continue;
				}

				retorno = -1;
				break ;
			}
			i++;
		}
	}
	return retorno;
}

//Reemplaza el scanf
static int myGets ( char * cadena, int len)
{
	if (cadena != NULL && len > 0 && fgets (cadena,len,stdin) == cadena)
	{
		fflush (stdin);
		if (cadena[strlen (cadena)-1] == '\n' )
		{
			cadena[strlen (cadena)-1] = '\0' ;
		}
		return 0;
	}
	return -1;
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
