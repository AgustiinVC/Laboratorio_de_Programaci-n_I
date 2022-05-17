/*
 * operaciones.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Agostin
 */
#include "operaciones.h"

int imprimirArrayInt (char* mensaje, int arrayNros[], int len)
{
	int retorno;
	int i;
	retorno = -1;
	if (arrayNros != 0 && len > 0 && mensaje != NULL)
	{
		retorno = 0;
		printf (mensaje);
		for (i = 0; i < len; i++)
		{
			printf (" %d", arrayNros[i]);
		}
		puts ("");
	}
	return retorno;
}

int ordenarArrayIntDesc (int* arrayNros, int len)
{
	int retorno;
	int flagCambio;
	int aux;
	int i;
	int contador;

	contador = 0;
	retorno = -1;

	if (arrayNros != NULL && len >= 0)
	{
		do
		{
			flagCambio = 0;
			for (i = 0; i < len ; i++)
			{
				contador++;
				if (arrayNros[i] < arrayNros[i+1])
				{
					flagCambio = 1;
					aux = arrayNros[i];
					arrayNros[i] = arrayNros[i+1];
					arrayNros[i+1] = aux;
				}
			}
		}while (flagCambio);
		retorno = contador;
	}
	return retorno;
}

int ordenInsercionIntAsc (int* arrayNros, int len)
{
	int retorno;
	int aux;
	int i;
	int j;

	retorno = -1;

	if (arrayNros != NULL && len >= 0)
	{
		for (i = 0; i < len ; i++)
		{
			j = i - 1;
			aux = arrayNros[i];
			while (j >= 0 && aux < arrayNros[j])
			{
				arrayNros[j+1] = arrayNros[j];
				j--;
			}
			arrayNros[j+1] = aux;
		}
		retorno = 0;
	}
	return retorno;
}

int promedioArrayInt (int arrayNro[], int len, float* pPromedio)
{
	int i;
	int sumaTotal = 0;
	int retorno = -1;

	if (arrayNro != NULL && len > 0)
	{
		retorno = 0;
		for (i = 0; i < len; i++)
		{
			sumaTotal += arrayNro[i];

		}
		*pPromedio = (float)sumaTotal / len;
		printf ("Promedio es: %.2f.\n", *pPromedio);
	}
	return retorno;
}

int buscarMax(int* arrayNros, int len, int* maximo, int* cantMax)
{
	int i;
	int contador = 0;
	int maximoIngresado;
	int retorno = -1;

	if (arrayNros != NULL && len > 0 && maximo != NULL)
	{
		retorno = 0;
		for (i=0; i < len; i++)
		{
			if (i == 0 || maximoIngresado < arrayNros[i])
			{
				maximoIngresado = arrayNros[i];
			}
		}

		*maximo = maximoIngresado;

		for (i=0; i < len; i++)
		{
			if (maximoIngresado == arrayNros[i])
			{
				contador++;
			}
		}
		*cantMax = contador;
	}
	return retorno;
}

int buscarMin(int* arrayNros, int len, int* minimo, int* cantMin)
{
	int i;
	int contador = 0;
	int minimoIngresado;
	int retorno = -1;

	if (arrayNros != NULL && len > 0 && minimo != NULL)
	{
		retorno = 0;
		for (i=0; i < len; i++)
		{
			if (i == 0 || minimoIngresado > arrayNros[i])
			{
				minimoIngresado = arrayNros[i];
			}
		}
		*minimo = minimoIngresado;

		for (i=0; i < len; i++)
			{
				if (minimoIngresado == arrayNros[i])
				{
					contador++;
				}
			}
		*cantMin = contador;
	}
	return retorno;
}

int buscarNro(int* arrayNros, int len)
{
	int i;
	int contador = 0;
	int nroIngresado;
	int direcciones [len];
	int posicion [len];
	int retorno;
	retorno = -1;
	if (arrayNros != NULL && len > 0)
	{
		retorno = 0;
		getIntAlone (&nroIngresado, "Ingrese un numero a comparar: ","Numero Ingresado incorrecto.");
		for (i=0; i < len; i++)
		{
			if (nroIngresado == arrayNros[i])
				{
					direcciones [contador] = (int) &arrayNros[i];
					posicion [contador] = i;
					contador++;
				}
		}
		printf ("\nSe ingreso el %d un total de %d veces.\n", nroIngresado, contador);
		if (contador != 0)
		{
			printf ("En las siguientes direcciones: \n");
			for ( i = 0 ; i < (contador) ; i++)
			{
				printf ("	- Posicion en el array: %d Direccion: %d\n", posicion [i], direcciones[i]);
			}
			puts("");
		}
	}
	return retorno;
}


void menu (void)
{
	puts ("Menu:");
	puts ("		1)Buscar el MAXIMO y mostrarlo (mostrar la cantidad de ocurrencias)\n");
	puts ("		2)Buscar el MINIMO y mostrarlo (mostrar la cantidad de ocurrencias)\n");
	puts ("		3)Calcular el PROMEDIO y mostrarlo\n");
	puts ("		4)Ingresar un numero y mostrar si se encontro, cuantas veces y las posiciones del array\n");
	puts ("		5)Ordenar Array\n");
	puts ("		6)Salir\n");
}
