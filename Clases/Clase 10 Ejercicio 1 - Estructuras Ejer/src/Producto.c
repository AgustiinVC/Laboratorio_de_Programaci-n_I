/*
 * Producto.c
 *
 *  Created on: 26 abr. 2022
 *      Author: Agostin
 */
#include "Producto.h"
#include "validaciones.h"

static int idUnicoProd = 0;

int prod_generarIdUnico (void)
{
	return idUnicoProd++;
}

int prod_imprimirEstructura (Producto miProducto[], int tam)
{
	int rtn = -1;

	if (miProducto != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			if (miProducto[i].isEmpty == OCUPADO)
			{
				prod_imprimirUnProducto (miProducto, i);
			}
		}
		rtn = 0;
	}

	return rtn;
}


int prod_initArray (Producto miProducto[], int len)
{
	int rtn = -1;
	int i;
	if (miProducto != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			miProducto[i].isEmpty = LIBRE;
		}
		rtn = OCUPADO;
	}
	return rtn;
}

int prod_indexEmpty (Producto miProducto[], int len)
{
	int rtn = -1;
	int i;
	if (miProducto != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (miProducto[i].isEmpty == LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int prod_cargarProducto (Producto miProducto[], int indice)
{
	int rtn = -1;
	Producto auxiliarProducto;

	if (miProducto != NULL && indice >= 0)
	{
		if (  utn_getNombre (auxiliarProducto.nombre, "Ingrese un nombre: ", "Error, ingrese un nombre valido.", NOMBRE_LEN, 3) &&
			  utn_getDescripcion (auxiliarProducto.descripcion, "Ingrese una descripcion: ", "Error, ingrese un descripcion valida.", DESC_LEN, 3) &&
			  utn_getFloatAlone (&auxiliarProducto.precio, "Ingrese el precio del producto: ", "Error, ingrese un precio valido.") )
		{
			auxiliarProducto.isEmpty = OCUPADO;
			auxiliarProducto.id = prod_generarIdUnico();
			miProducto[indice] = auxiliarProducto;
			rtn = 1;
		}
	}
	return rtn;
}

int prod_imprimirUnProducto (Producto arrayProducto[], int i)
{
	int rtn = -1;
	if (arrayProducto[i].isEmpty == LIBRE || arrayProducto[i].isEmpty == BAJA)
	{
		puts ("No hay nada en ese indice.");
		rtn = 0;
	}
	else
	{
		printf("ID: %d\n", arrayProducto[i].id);
		printf("Nombre: %s\n", arrayProducto[i].nombre);
		printf("Descripcion: %s\n", arrayProducto[i].descripcion);
		printf("Precio: %f\n", arrayProducto[i].precio);
		rtn = 1;
	}
	return rtn;
}

int prod_buscarporID (Producto miProducto[], int len, int identificador)
{
	int rtn = -1;
	int i;
	if (miProducto != NULL && len >= 0 && identificador >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (miProducto[i].id == identificador)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int prod_bajaProductoIndice (Producto miProducto[], int len, int indice)
{
	int rtn = -1;

	if (miProducto != NULL && len >= 0 && indice < len && indice >= 0 && miProducto[indice].isEmpty == OCUPADO)
	{
		miProducto[indice].isEmpty = BAJA;
		rtn = 1;
	}
	return rtn;
}

int prod_bajaProductoID (Producto miProducto[], int len, int identificador)
{
	int i;
	int rtn = -1;

	i = prod_buscarporID (miProducto, len, identificador);
	if (miProducto != NULL && len >= 0)
	{
		if (miProducto[i].isEmpty == OCUPADO)
		{
			miProducto[i].isEmpty = BAJA;
			rtn = 1;
			puts ("ID dado de baja.");
		}
		else
		{
			puts ("ID libre");
		}

	}
	return rtn;

}

void menu (void)
{
	puts ("1. Cargar producto en cualquier indice independiente si esta vacio.");
	puts ("2. Imprimir un indice.");
	puts ("3. Devolver indice de un producto vacio (sin cargar)");
	puts ("4. Dar alta en la ultima posicion libre.");
	puts ("5. Imprimir todo un array");
	puts ("6. Buscar por ID y mostrar indice.");
	puts ("7. Baja por indice.");
	puts ("8. Baja por Id.");
}

