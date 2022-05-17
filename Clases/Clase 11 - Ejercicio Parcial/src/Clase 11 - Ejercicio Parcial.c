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

#include "validaciones.h"
#include "Pantalla-Contrataciones.h"

#define CANT_PANT 100
#define CANT_CONTRA 1000

int main(void)
{
	setbuf (stdout,NULL);

	Pantalla miPantalla[CANT_PANT];
	Contrataciones miContrato[CANT_CONTRA];
	int opcion;

	pant_initArray (miPantalla, CANT_PANT);
	cont_initArray (miContrato, CANT_CONTRA);

	do
	{
		menu();
		utn_getIntPositivo ( &opcion ,"\nIngrese un numero: ", "Error. Ingrese solo numeros.\n");
		switch (opcion)
		{
			case 1: //Alta pantalla
				if (pant_altaArray(miPantalla, CANT_PANT) == 0)
				{
					puts("Carga OK");
				}
				else
				{
					puts("No hay lugar");
				}
				break;

			case 2: //modificar Pantalla
				if (pant_modificarEstructura(miPantalla, CANT_PANT) == 0)
				{
					puts("Modificacion OK");
				}
				else
				{
					puts("No se pudo modificar");
				}
				break;

			case 3: //Baja pantalla, falta baja contrataciones
				pant_Baja (miPantalla, CANT_PANT);
				break;

			case 4: //Alta Contratacion
				union_AltaDeContratacion (miPantalla, CANT_PANT, miContrato, CANT_CONTRA);
				break;

			case 5:

				break;

			case 6:

				break;

			case 7:

				break;

			case 8:

				break;

			case 9:

				break;

			case 10:

				break;

			case 11: // Alta Forzada.
				pant_altaForzadaArray(miPantalla, CANT_PANT, "Pantalla 1", "Zapiola 123", 12000.22, 1);
				pant_altaForzadaArray(miPantalla, CANT_PANT, "Pantalla 2", "2 de Mayo 3125", 22000, 2);
				pant_altaForzadaArray(miPantalla, CANT_PANT, "Pantalla 3", "9 de Septiembre 1542", 54896.15, 1);
				pant_altaForzadaArray(miPantalla, CANT_PANT, "Pantalla 4", "Mitre 750", 15483.45, 2);
				pant_altaForzadaArray(miPantalla, CANT_PANT, "Pantalla 5", "9 de Julio 10", 99000.99, 1);
				break;
		}
	}
	while (opcion != 6);

	return EXIT_SUCCESS;
}
