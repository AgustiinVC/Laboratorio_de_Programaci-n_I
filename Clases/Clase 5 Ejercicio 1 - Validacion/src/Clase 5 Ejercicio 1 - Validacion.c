/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Validacion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int main()
{
	setbuf (stdout,NULL);
	int nroIngresadoInt;
	float nroIngresadoFloat;
	int rtnInt;
	float rtnFloat;
	rtnInt = getInt(&nroIngresadoInt, "Ingrese un numero entero del 0 al 10: " , "Error. Ingrese un numero correcto" ,0,10,3);

	if (rtnInt == 0)
	{
		printf ("Se te acabaron los intentos de numeros enteros.\n");
	}
	else
	{
		printf( "El numero ingresado es: %d\n", nroIngresadoInt);
	}

	rtnFloat = getFloat(&nroIngresadoFloat, "Ingrese el numero flotante del 0 al 10: " , "Error. Ingrese un numero correcto" ,0,10,3);

	if (rtnFloat == 0)
	{
		printf ("Se te acabaron los intentos de numeros flotantes.\n");
	}
	else
	{
		printf( "El numero ingresado es: %f\n", nroIngresadoFloat);
	}
	printf ("Saliste del programa.");
	return 0;
}
