/*
 * Cliente.c
 *
 *  Created on: 26 abr. 2022
 *      Author: Agostin
 */

#include "Cliente.h"

void imprimirUnEmpleado (Cliente arrayCliente[])
{
	puts ("EMPLEADO");
	printf("LEGAJO: %d\n", arrayCliente->legajo);
	printf("NOMBRE: %s\n", arrayCliente->nombre);
	printf("DNI: %d\n", arrayCliente->dni);
	printf("SUELDO: %.2f\n", arrayCliente->sueldo);
}
