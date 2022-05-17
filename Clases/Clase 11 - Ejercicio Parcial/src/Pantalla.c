/*
 * Producto.c
 *
 *  Created on: 26 abr. 2022
 *      Author: Agostin
 */

#include "validaciones.h"
#include "Pantalla.h"

static const char TXT_TIPOS [2][4] = {"LCD", "LED"};

static int Pant_idUnico = 0;

int pant_generarIdUnico (void)
{
	return Pant_idUnico++;
}


int pant_initArray (Pantalla* list , int len)
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

int pant_indexEmpty (Pantalla* list , int len)
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

int pant_altaArray(Pantalla* list , int len)
{
	int rtn = -1;
	int indiceLibre;
	Pantalla auxiliarEstructura;

	indiceLibre = pant_indexEmpty (list, len);

	if (list != NULL && len > 0 && indiceLibre != -1)
	{
		if (  utn_getNombre (auxiliarEstructura.nombre, "Ingrese un nombre: ", "Error, ingrese un nombre valido.", NOMBRE_LEN, 3) &&
			  utn_getDescripcion (auxiliarEstructura.direccion, "Ingrese una direccion: ", "Error, ingrese un direccion valida.", DESC_LEN, 3) &&
			  utn_getFloatAlone (&auxiliarEstructura.precio, "Ingrese el precio de la publicidad: ", "Error, ingrese un precio valido.") &&
			  utn_getIntRange (&auxiliarEstructura.tipoDePantalla, "Ingrese 1 para LCD y 2 para LED: ", "Error, ingrese un numero valido.", 1, 2) )
		{
			auxiliarEstructura.isEmpty = OCUPADO;
			auxiliarEstructura.id = pant_generarIdUnico();
			list[indiceLibre] = auxiliarEstructura;
			rtn = 0;
		}
	}
	return rtn;
}

int pant_modificarEstructura (Pantalla* list, int len)
{
	int rtn = -1;
	int idIngresado;
	int index;
	int flagAlta = 0;
	Pantalla auxiliarEstructura;
	if (list != NULL && len >= 0)
	{
		if (pant_imprimirEstructura(list, len) == 0)
		{
			flagAlta = 1;
		}

		if (flagAlta)
		{
			if( utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un ID correcto.\n") == 0)
			{
				while (pant_buscarporID(list, len, idIngresado) == -1)
				{
					puts("NO EXISTE ID.");
					utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un ID correcto.\n");
				}
				index = pant_buscarporID(list, len, idIngresado);
				auxiliarEstructura = pant_ModificarUno( list[index] );
				list[index] = auxiliarEstructura;
				rtn = 0;
			}
		}
	}
	return rtn;
}

Pantalla pant_ModificarUno(Pantalla list)
{
	int opcion;
	int respuesta;
	Pantalla auxiliar = list;
	do
	{
		fflush(stdin);
		utn_getIntRange (&opcion ,"\nIngrese la opcion a modificar:\n "
									"1 - Nombre\n "
									"2 - Direccion\n "
									"3 - Precio\n "
									"4 - Tipo de Pantalla\n ",
									"Error. Ingrese una opcion correcta\n\n", 1, 5);

		switch (opcion)
		{
			case 1:
				if( utn_getNombre(auxiliar.nombre, "Ingrese el nombre del pasajero: ", "Ingrese un nombre valido\n\n", NOMBRE_LEN, 3) == 0)
				{
					puts ("Carga de nombre correcta.\n");
				}
				else
				{
					puts("No se pudo cargar el nombre.\n");
				}
				break;

			case 2:
				if(utn_getString(auxiliar.direccion, "Ingrese el apellido del pasajero: ", "Ingrese un apellido valido\n\n", DESC_LEN, 3) == 0)
				{
					puts ("Carga de direccion correcta.\n");
				}
				else
				{
					puts("No se pudo cargar la direccion.\n");
				}
				break;

			case 3:
				if(utn_getFloatPositivo(&auxiliar.precio, "Ingrese el precio del vuelo: ", "Ingrese un precio valido\n\n") == 0)
				{
					puts ("Carga de precio correcta.\n");
				}
				else
				{
					puts("No se pudo cargar el precio.\n");
				}
				break;

			case 4:
				if(utn_getIntRange(&auxiliar.tipoDePantalla, "Ingrese el tipo del vuelo: "
						"\n\t 1 = LCD\n\t 2 = LED\nIngrese su opcion: ", "Ingrese un tipo de vuelo valido\n", 1,2) == 0)
				{
					puts ("Carga de tipo de pantalla correcta\n");
				}
				else
				{
					puts("No se pudo cargar el tipo de pantalla.\n");
				}
				break;
		}


		respuesta = validacionDosCaracteres ("¿Desea modificar otro campo? (S/N)", 'S', 'N');
	}
	while (respuesta);

	return auxiliar;
}

int pant_buscarporID (Pantalla* list, int len, int id)
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

int pant_removeID(Pantalla* list, int len, int id)
{
	int rtn = -1;

	if (list != NULL && len >= 0 && id < len && id >= 0 && list[id].isEmpty == OCUPADO)
	{
		list[id].isEmpty = BAJA;
		rtn = 0;
	}
	return rtn;
}

int pant_Baja (Pantalla* list, int len)
{
	int rtn = -1;
	int idIngresado;
	int index;
	int flagAlta = 0;

	if (pant_imprimirEstructura(list, len) == 0)
	{
		flagAlta = 1;
	}

	if (flagAlta)
	{
		if( utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n") == 0)
		{
			while (pant_buscarporID(list, len, idIngresado) == -1)
			{
				puts("NO EXISTE ID.");
				utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n");
			}

			index = pant_buscarporID(list, len, idIngresado);
			if (validacionDosCaracteres ("¿Esta seguro de querer borrar el pasajero? (S/N)", 'S', 'N') == 1)
			{
				if (pant_removeID(list, len, index) == 0)
				{
					rtn = 0;
				}
			}
		}
	}

	return rtn;
}



int pant_imprimirEstructura (Pantalla* list, int len)
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
					puts("\n\t\t\t\t> LISTADO PANTALLAS");
					printf("%-6s %-52s %-52s %-15s %-16s\n", "ID", "NOMBRE", "DIRECCION", "PRECIO", "TIPO DE PANTALLA");
				}

				pant_imprimirUnElemento (&list[i]);
				rtn = 0;
			}
		}
	}

	return rtn;
}

int pant_imprimirUnElemento (Pantalla* list)
{
	int rtn = -1;

	if (list->isEmpty == LIBRE || list->isEmpty == BAJA)
	{
		puts ("No hay nada en ese indice.");
		rtn = -2;
	}
	else
	{
		printf ("%-6d %-52s %-52s %-15.2f %-16s\n",
				list->id, list->nombre, list->direccion, list->precio, TXT_TIPOS[ (list->tipoDePantalla) - 1] );

		rtn = 0;
	}
	return rtn;
}


int pant_altaForzadaArray(Pantalla* list , int len, char* nombre, char* direccion, float precio, int tipoDePantalla)
{
	int rtn = -1;
	int indiceLibre;
	Pantalla auxiliarEstructura;

	indiceLibre = pant_indexEmpty (list, len);

	if (list != NULL && len > 0 && indiceLibre != -1)
	{
		strncpy (auxiliarEstructura.nombre,nombre, NOMBRE_LEN);
		strncpy (auxiliarEstructura.direccion,direccion, DESC_LEN);
		auxiliarEstructura.precio = precio;
		auxiliarEstructura.tipoDePantalla = tipoDePantalla;
		auxiliarEstructura.isEmpty = OCUPADO;
		auxiliarEstructura.id = pant_generarIdUnico();
		list[indiceLibre] = auxiliarEstructura;
		rtn = 0;
	}
	return rtn;
}



void menu (void)
{
	puts ("1. Alta de pantalla.");
	puts ("2. Modificar datos de pantalla.");
	puts ("3. Baja de pantalla");
	puts ("4. Contratar una publicidad.");
	puts ("5. Modificar condiciones de publicacion");
	puts ("6. Cancelar contratacion");
	puts ("7. Consulta facturacion.");
	puts ("8. Listar contrataciones.");
	puts ("9. Listar pantallas.");
	puts ("8. Informar.");
}

