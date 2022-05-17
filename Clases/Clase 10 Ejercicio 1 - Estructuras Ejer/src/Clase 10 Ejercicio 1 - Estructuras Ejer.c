/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

1) Definir un tipo de dato que represente un producto. El producto tiene un nombre, una descripcion y un precio.

2) Definir un array de 200 productos, indicar de alguna manera que la info de cada item no esta cargada.

3) Realizar una funcion que reciba el array, un indice, y le permita al usuario cargar los datos en el item de la posicion especificada por el indice.

4) Realizar una funcion que reciba el array y un indice e imprima los datos del item de la posicion especificada por el indice.

5) Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).

6) Agregar al tipo de dato el campo ID que represente un identificador unico. Modificar el codigo anterior para que el ID se genere automaticamente. Se debera cargar el ID automaticamente al cargar un producto, y se debera imprimir al imprimir la lista.

7) Realizar una funcion que reciba el array y un ID, y me devuelva el indice del item con dicho ID.

8) Realizar una funcion que reciba el array, un indice, y le permita al usuario modificar los campos nombre y precio del item del array en la posicion especificada por el indice.
*/

#include <stdio.h>
#include <stdlib.h>

#include "Producto.h"
#include "validaciones.h"

#define CANT_PROD 2

int main(void)
{
	setbuf (stdout,NULL);

	Producto miProducto[CANT_PROD];
	int opcion;
	int nroIngresado;

	prod_initArray (miProducto, CANT_PROD);

	do
	{
		menu();
		utn_getIntPositivo ( &opcion ,"\nIngrese un numero: ", "Error. Ingrese solo numeros.\n");
		switch (opcion)
		{
			//Case 1 es el ingreso de los kilómetros.
			case 1:
				utn_getIntRange (&nroIngresado,"\nIngrese un indice: ", "Error. Ingrese un indice valido.\n",0,CANT_PROD);
				prod_cargarProducto (miProducto,nroIngresado);
			break;

			case 2:
				utn_getIntRange (&nroIngresado,"\nIngrese un indice: ", "Error. Ingrese un indice valido.\n",0,CANT_PROD);
				prod_imprimirUnProducto (miProducto,nroIngresado);
			break;

			case 3:
				printf ("\n Primer lugar vacio: %d\n1", prod_indexEmpty (miProducto, CANT_PROD) );
			break;

			case 4:
				nroIngresado = prod_indexEmpty (miProducto, CANT_PROD);
				if (nroIngresado >= 0)
				{
					if (prod_cargarProducto (miProducto,nroIngresado) == 1)
					{
						puts ("Carga OK");
					}
					else
					{
						puts ("No hay lugar");
					}
				}
			break;

			case 5:
				prod_imprimirEstructura (miProducto, CANT_PROD);
			break;

			case 6:
				utn_getIntRange (&nroIngresado,"\nIngrese el ID a buscar: ", "Error. Ingrese un ID valido.\n",1,CANT_PROD);
				prod_buscarporID (miProducto,CANT_PROD, nroIngresado);
			break;

			case 7:
				utn_getIntRange (&nroIngresado,"\nIngrese el indice a buscar: ", "Error. Ingrese un indice valido.\n",0,CANT_PROD);
				prod_bajaProductoIndice (miProducto, CANT_PROD, nroIngresado);
			break;

			case 8:
					utn_getIntRange (&nroIngresado,"\nIngrese el ID a buscar: ", "Error. Ingrese un ID valido.\n",1,CANT_PROD);
					prod_bajaProductoID (miProducto, CANT_PROD, nroIngresado);
			break;

			case 9: //Alta e impresion forzada
				utn_getNombre (miProducto[0].nombre, "Ingrese un nombre: ", "Error, ingrese un nombre valido.", NOMBRE_LEN, 3);
				utn_getDescripcion (miProducto[0].descripcion, "Ingrese una descripcion: ", "Error, ingrese un descripcion valida.", DESC_LEN, 3);
				utn_getFloatAlone (&miProducto[0].precio, "Ingrese el precio del producto: ", "Error, ingrese un precio valido.");
				miProducto[0].isEmpty = 1;
				prod_imprimirUnProducto (miProducto, 0);
			break;
		}
	}
	while (nroIngresado != 6);

	return EXIT_SUCCESS;
}
