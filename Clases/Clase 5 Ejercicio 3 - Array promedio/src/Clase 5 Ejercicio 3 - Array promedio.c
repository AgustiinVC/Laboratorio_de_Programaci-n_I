/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
/******************************************************************************
1)Hacer un programa en donde el usuario ingrese un array de 5 numeros enteros,
  luego generar un menu en donde el usuario pueda elegir entre las siguientes funciones:

    a)Buscar el MAXIMO y mostrarlo (mostrar la cantidad de ocurrencias)
	b)Buscar el MINIMO y mostrarlo (mostrar la cantidad de ocurrencias)
	c)Calcular el PROMEDIO y mostrarlo
 	d)Ingresar un numero y mostrar si se encontro, cuantas veces y las posiciones del array
 	e) Salir

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "operaciones.h"

#define ARRAY_MAX 5

int main(void)
{
	setbuf (stdout, NULL);

	int i;
	int opcionIngresada;
	int arrayNros [ARRAY_MAX];
	float promedio;
	int maximo;
	int minimo;

	int cantMax = 0;
	int cantMin = 0;

	for (i = 0; i < ARRAY_MAX; i++)
	{
		if (getIntAlone (&arrayNros[i], "Ingrese un numero: ", "Numero ingresado incorrecto"))
		{
			printf ("%d° Numero Ingresado\n", i+1);
		}
	}
	puts ("Carga Terminada.");
	saltoDeLinea();
	menu();
	saltoDeLinea();
	do
	{
		getIntAlone (&opcionIngresada, "Ingrese una opcion: ","Numero Ingresado incorrecto.");

		switch (opcionIngresada)
		{
			case 1:
				buscarMax(arrayNros, ARRAY_MAX, &maximo, &cantMax);
				printf ("El numero maximo es: %d y hay %d ocurrencias.\n",maximo,cantMax);
				break;

			case 2:
				buscarMin(arrayNros, ARRAY_MAX , &minimo, &cantMin);
				printf ("El numero miniimo es: %d y hay %d ocurrencias.\n",minimo,cantMin);
				break;

			case 3:
				promedioArrayInt (arrayNros, ARRAY_MAX, &promedio);
				break;
			case 4:
				buscarNro(arrayNros, ARRAY_MAX);
				break;
			case 5:
				puts ("Saliste del programa. Adios!");
				break;

			default:
				puts ("Ingrese una opcion correcta.");
		}
		presionarEnter();

		if (opcionIngresada != 5)
		{
			saltoDeLinea();
			menu();
			saltoDeLinea();
		}
	}
	while (opcionIngresada != 5);
	return EXIT_SUCCESS;
}
