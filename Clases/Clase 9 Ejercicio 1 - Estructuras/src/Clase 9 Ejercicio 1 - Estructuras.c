/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cliente.h"


#define CANT_EMPLEADOS 3

int main(void) {
	setbuf(stdout, NULL);

	//CREO LA ESTRUCTURA (MI NUEVO TIPO DE DATO)
	Cliente miEmpleado;

	//CARGO MI ESTRUCTURA
	miEmpleado.dni = 37687769;
	miEmpleado.legajo = 1000;
	strcpy(miEmpleado.nombre, "Mathias");
	miEmpleado.sueldo = 500.50;

	//MUESTRO MI ESTRUCTURA
	puts("EMPLEADO");
	printf("LEGAJO: %d\n", miEmpleado.legajo);
	printf("NOMBRE: %s\n", miEmpleado.nombre);
	printf("DNI: %d\n", miEmpleado.dni);
	printf("SUELDO: %.2f\n", miEmpleado.sueldo);

	Cliente empleados[CANT_EMPLEADOS];

	for (int i = 0; i < CANT_EMPLEADOS; i++)
	{
		imprimirUnEmpleado  (&empleados[i]);
	}

	return EXIT_SUCCESS;
}
