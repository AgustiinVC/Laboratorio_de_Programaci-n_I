/*
 * Contrataciones.c
 *
 *  Created on: 3 may. 2022
 *      Author: Agostin
 */

#include "validaciones.h"
#include "Contrataciones.h"


static int cont_idUnico = 0;

int cont_generarIdUnico (void)
{
	return cont_idUnico++;
}


int cont_initArray (Contrataciones* list , int len)
{
	int rtn = -1;
	int i;
	if (list != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = LIBRE;
		}
		rtn = 0;
	}
	return rtn;
}

int cont_indexEmpty (Contrataciones* list , int len)
{
	int rtn = -1;
	int i;
	if (list != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int cont__altaArray(Contrataciones* list , int len)
{
	int rtn = -1;
	int indiceLibre;
	Contrataciones auxiliarEstructura;

	indiceLibre = cont_indexEmpty (list, len);

	if (list != NULL && len > 0 && indiceLibre != -1)
	{
		if (  utn_getIntPositivo(&auxiliarEstructura.cuitCLiente, "Ingrese su CUI (solo numeros): ", "Ingrese solo numeros") &&
			  utn_getString(auxiliarEstructura.nombreArchivo, "Ingrese el nombre del archivo: ", "Error, ingrese un nombre valido.", NOMBRE_LEN, 3) &&
			  utn_getIntPositivo(&auxiliarEstructura.cantDias, "Ingrese la cantidad de dias: ", "Error, ingrese una cantidad valida.") )
		{
			auxiliarEstructura.isEmpty = OCUPADO;
			auxiliarEstructura.id = cont_generarIdUnico();
			list[indiceLibre] = auxiliarEstructura;
			rtn = 0;
		}
	}
	return rtn;
}


int cont_modificarEstructura (Contrataciones* list, int len)
{
	int rtn = -1;
	int idIngresado;
	int index;
	int flagAlta = 0;
	Contrataciones auxiliarProducto;
	if (list != NULL && len >= 0)
	{
		if (cont_imprimirEstructura(list, len) == 0)
		{
			flagAlta = 1;
		}

		if (flagAlta)
		{
			if( utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un ID correcto.\n") == 0)
			{
				while (cont_buscarporID(list, len, idIngresado) == -1)
				{
					puts("NO EXISTE ID.");
					utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un ID correcto.\n");
				}
				index = cont_buscarporID(list, len, idIngresado);
				auxiliarProducto = cont_ModificarUno( list[index] );
				list[index] = auxiliarProducto;
				rtn = 0;
			}
		}
	}
	return rtn;
}


Contrataciones cont_ModificarUno(Contrataciones list)
{
	Contrataciones auxiliar = list;
	fflush(stdin);
	utn_getIntPositivo (&auxiliar.cantDias ,"\nIngrese la cantidad de dias:\n ", "Error. Ingrese una cantidad correcta\n\n");

	return auxiliar;
}


int cont_buscarporID (Contrataciones* list, int len, int id)
{
	int rtn = -1;
	int i;
	if (list != NULL && len >= 0 && id >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].id == id && list[i].isEmpty == OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}


int cont_removeID(Contrataciones* list, int len, int id)
{
	int rtn = -1;

	if (list != NULL && len >= 0 && id < len && id >= 0 && list[id].isEmpty == OCUPADO)
	{
		list[id].isEmpty = BAJA;
		rtn = 0;
	}
	return rtn;
}


int cont_Baja (Contrataciones* list, int len)
{
	int rtn = -1;
	int idIngresado;
	int index;
	int flagAlta = 0;

	if (cont_imprimirEstructura(list, len) == 0)
	{
		flagAlta = 1;
	}

	if (flagAlta)
	{
		if( utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n") == 0)
		{
			while (cont_buscarporID(list, len, idIngresado) == -1)
			{
				puts("NO EXISTE ID.");
				utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n");
			}

			index = cont_buscarporID(list, len, idIngresado);
			if (validacionDosCaracteres ("¿Esta seguro de querer borrar el pasajero? (S/N)", 'S', 'N') == 1)
			{
				if (cont_removeID(list, len, index) == 0)
				{
					rtn = 0;
				}
			}
		}
	}

	return rtn;
}



int cont_imprimirEstructura (Contrataciones* list, int len)
{
	int rtn = -1;
	int flagPrimerEntrada = 0;

	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == OCUPADO)
			{
				if (flagPrimerEntrada == 0)
				{
					flagPrimerEntrada = 1;
					puts("\n\t\t\t\t> LISTADO PASAJEROS");
					printf("%-6s %-15s %-6s %-52s %-16s\n", "ID", "CUIT" , "ID PANTALLA", "NOMBRE ARCHIVO", "CANTIDAD DIAS");
				}

				cont_imprimirUnElemento (&list[i]);
				rtn = 0;
			}
		}
	}

	return rtn;
}

int cont_imprimirUnElemento (Contrataciones* list)
{
	int rtn = -1;

	if (list->isEmpty == LIBRE || list->isEmpty == BAJA)
	{
		puts ("No hay nada en ese indice.");
		rtn = -2;
	}
	else
	{
		printf ("%-6d %-15d %-6d %-52s %-16d\n",
				list->id, list->cuitCLiente, list->FK_idPantalla, list->nombreArchivo, list->cantDias);

		rtn = 0;
	}
	return rtn;
}
