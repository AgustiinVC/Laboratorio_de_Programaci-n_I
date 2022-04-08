/*
 * operaciones.c
 *
 *  Created on: 7 abr. 2022
 *      Author: Agostin
 */
#include "operaciones.h"

void imprimirArray (int arrayNros[], int len)
{
	int i;

	for (i = 0; i < len; i++)
	{
		printf ("Numero Ingresado: %d.\n", arrayNros[i]);
	}
}

void promedioArrayInt (int arrayNro[], int len, float* pPromedio)
{
	int i;
	int sumaTotal = 0;
	for (i = 0; i < len; i++)
	{
		sumaTotal += arrayNro[i];

	}
	*pPromedio = (float)sumaTotal / len;
	printf ("Promedio es: %.2f.\n", *pPromedio);
}

void buscarMax(int* array, int len, int* maximo, int* cantMax)
{
	int i;
	int contador = 0;
	int maximoIngresado;

	for (i=0; i < len; i++)
	{
		if (i == 0)
		{
			maximoIngresado = array[i];
		}

		if (maximoIngresado < array[i])
		{
			maximoIngresado = array[i];
		}
	}

	*maximo = maximoIngresado;

	for (i=0; i < len; i++)
	{
		if (maximoIngresado == array[i])
		{
			contador++;
		}
	}
	*cantMax = contador;
}

void buscarMin(int* array, int len, int* minimo, int* cantMin)
{
	int i;
	int contador = 0;
	int minimoIngresado;

	for (i=0; i < len; i++)
	{
		if (i == 0)
		{
			minimoIngresado = array[i];
		}

		if (minimoIngresado > array[i])
		{
			minimoIngresado = array[i];
			contador++;
		}
	}
	*minimo = minimoIngresado;

	for (i=0; i < len; i++)
		{
			if (minimoIngresado == array[i])
			{
				contador++;
			}
		}
	*cantMin = contador;
}

void buscarNro(int* array, int len)
{
	int i;
	int contador = 0;
	int nroIngresado;
	int direcciones [len];

	getIntAlone (&nroIngresado, "Ingrese un numero a comparar: ","Numero Ingresado incorrecto.");
	for (i=0; i < len; i++)
	{
		if (nroIngresado == array[i])
			{
				direcciones [contador] = (int)&array[i];
				contador++;
			}
	}
	printf ("\nSe ingreso el %d un total de %d veces.\n", nroIngresado, contador);
	if (contador != 0)
	{
		printf ("En las siguientes direcciones: ");
		for ( i = 0 ; i < (contador) ; i++)
		{
			printf (" %d ",direcciones[i]);
		}
		puts("");
	}

}


void menu (void)
{
	puts ("Menu:");
	puts ("		1)Buscar el MAXIMO y mostrarlo (mostrar la cantidad de ocurrencias)\n");
	puts ("		2)Buscar el MINIMO y mostrarlo (mostrar la cantidad de ocurrencias)\n");
	puts ("		3)Calcular el PROMEDIO y mostrarlo\n");
	puts ("		4)Ingresar un numero y mostrar si se encontro, cuantas veces y las posiciones del array\n");
	puts ("		5)Salir\n");
}
