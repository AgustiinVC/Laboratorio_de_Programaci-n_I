/*
 * Producto.c
 *
 *  Created on: 14 may. 2022
 *      Author: Agostin
 */

#include "validaciones.h"
#include "Producto.h"

///Nombres de cada categoria
static const char CATEGORIAS_PRODUCTOS [5][15] = {"Indumentaria", "Hogar", "Tecnologia", "Salud", "Repuestos"};

/// Inicio de variable ID Producto
static int Producto_idUnico = 1;

/// @fn int ePro_ObtenerID (void)
/// @brief
///  Generador de ID de cada producto. Suma 1 a la variable
/// @return devuelve el id de cada Producto
static int ePro_ObtenerID (void)
{
	return Producto_idUnico++;
}


/// @fn int pro_initArray(Producto*, int)
/// @brief
/// Funcion para iniciar la estructura producto al poner en LIBRE el campo isEmpty
/// @param list es la estructura Producto
/// @param len es el tamaño de la estructura
/// @return devuelve un 0 si esta OK. Devuelve un -1 si hay algun error.
int pro_initArray(Producto* list, int len)
{
	int rtn = -1;
	int i;
	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = PRO_LIBRE;
			rtn = 0;
		}
	}
	return rtn;
}

/// @fn int pro_indexEmpty(Producto*, int)
/// @brief
/// funcion para buscar un indice que este vacio
/// @param list es la estructura Producto
/// @param len es el tamaño de la estructura
/// @return devuelve el indice que se encuentra libre.. Devuelve un -1 si hay algun error.
int pro_indexEmpty (Producto* list, int len)
{
	int rtn = -1;
	int i;
	if (list != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == PRO_LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/// @fn int cargaDatosProducto(Producto*)
/// @brief
/// carga de datos en un Producto auxiliar para luego ser cargada en la estructura de Producto
/// @param auxList un Producto auxiliar
/// @return devuelve un 0 si esta OK. un -1 si hay algun error
int cargaDatosProducto (Producto* auxList)
{
	int rtn = -1;
	if (auxList != NULL)
	{
		if (utn_getNombre(auxList->nombreProducto, "\nIngrese el nombre del producto: ", "Ingrese un nombre valido\n", NOMBRE_LEN, 3) == 0 &&
			utn_getFloatPositivo(&auxList->precio, "Ingrese el precio del producto: ", "Ingrese un precio valido\n") == 0 &&
			utn_getIntPositivo(&auxList->stock, "Ingrese la cantidad a vender: ", "Ingrese una cantidad valido\n") == 0 &&
			utn_getIntRange(&auxList->categoria, "Ingrese una categoria:\n"
					"\t1 - Indumentaria\n"
					"\t2 - Hogar\n"
					"\t3 - Tecnologia\n"
					"\t4 - Salud\n"
					"\t5 - Repuestos\n"
					"Ingrese la categoria: ", "Ingrese una categoria valido\n", 1,5) == 0)
		{
			auxList->idProducto = ePro_ObtenerID();
			auxList->isEmpty = PRO_OCUPADO;
			rtn = 0;
		}
	}

	return rtn;
}

/// @fn int pro_imprimir(Producto*, int)
/// @brief
/// Funcion para imprimir los Producto dados de alta y con stock
/// @param list es la estructura Producto
/// @param length es la cantidad maxima de Producto
/// @return devuelve un 0 si esta ok. un -1 si hay un error.
int pro_imprimir(Producto* list, int length)
{
	int rtn = -1;
	int flagPrimerProducto = 0;

	if (list != NULL && length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i].isEmpty == PRO_OCUPADO && list[i].stock > 0)
			{
				if (flagPrimerProducto == 0)
				{
					flagPrimerProducto = 1;
					puts("\n\t\t\t\t\t> LISTADO PRODUCTOS\n"
							"-----------------------------------------------------------------------------");
					printf("%-6s %-27s %-11s %-13s %-15s %-6s\n", "ID", "NOMBRE", "ID VENDEDOR" ,"PRECIO", "CATEGORIA", "STOCK");
				}

				pro_printOne (&list[i]);
				rtn = 0;
			}
		}
	}

	return rtn;
}

/// @fn void pro_printOne(Producto*)
/// @brief
/// impresion de un solo Producto
/// @param list es el Producto que se va a imprimir
void pro_printOne (Producto* list)
{
	printf ("%-6d %-27s %-11d %-13.2f %-15s %-6d\n",
		list->idProducto, list->nombreProducto, list->FK_idVendedor , list->precio, CATEGORIAS_PRODUCTOS [(list->categoria)-1], list->stock);
}

/// @fn int pro_imprimirMismoVendedor(Producto*, int, int)
/// @brief
/// funcion para imprimir los Producto dados de alta y con stock de un mismo vendedor
/// @param list es la estructura Producto
/// @param length es la cantidad maxima de Producto
/// @param userId es usuario logueado
/// @return devuelve un 0 si esta ok. un -1 si hay un error.
int pro_imprimirMismoVendedor(Producto* list, int length, int userId)
{
	int rtn = -1;
	int flagPrimerProducto = 0;

	if (list != NULL && length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i].isEmpty == PRO_OCUPADO && list[i].stock > 0 && list[i].FK_idVendedor == userId)
			{
				if (flagPrimerProducto == 0)
				{
					flagPrimerProducto = 1;
					puts("\n\t\t\t\t\t> LISTADO PRODUCTOS\n"
							"-----------------------------------------------------------------------------");
					printf("%-6s %-27s %-11s %-13s %-15s %-6s\n", "ID", "NOMBRE", "ID VENDEDOR" ,"PRECIO", "CATEGORIA", "STOCK");
				}

				pro_printOne (&list[i]);
				rtn = 0;
			}
		}
	}

	return rtn;
}


/// @fn int pro_sortsByCategory(Producto*, int)
/// @brief
/// funcion para ordenar los Productos por CATEGORIA menor a mayor
/// @param list es la estructura Producto
/// @param len es la cantidad maxima de Producto
/// @return devuelve un 0 si esta OK. un -1 si hay error
int pro_sortsByCategory(Producto* list, int len)
{
	int rtn = -1;
	int i;
	int j;
	Producto auxProducto;

	if (list != NULL && len > 0)
	{
				for (i = 1; i < len; i++)
				{
					auxProducto = list[i];
					j = i - 1;
					while ( (j >= 0) && (auxProducto.categoria < list[j].categoria) )
					{
						list[j + 1] = list[j];
						j--;
					}
					list[j + 1] = auxProducto;
				}

				rtn = 0;
	}
	return rtn;
}

/// @fn int pro_sortsByCategoryName(Producto*, int)
/// @brief
/// funcion para ordenar los Producto por CATEGORIA y nombre si son iguales
/// @param list es la estructura Producto
/// @param len es la cantidad maxima de Producto
/// @return devuelve un 0 si esta OK. un -1 si hay error
int pro_sortsByCategoryName(Producto* list, int len)
{
	int rtn = -1;
	int i;
	int j;
	Producto auxProducto;

	if (list != NULL && len > 0)
	{
				for (i = 1; i < len; i++)
				{
					auxProducto = list[i];
					j = i - 1;
					while ( (j >= 0) && (auxProducto.categoria < list[j].categoria ||
							(auxProducto.categoria == list[j].categoria && compararCadenas(list[j].nombreProducto, auxProducto.nombreProducto, len) == 1) ) )
					{
						list[j + 1] = list[j];
						j--;
					}
					list[j + 1] = auxProducto;
				}

				rtn = 0;
	}
	return rtn;
}


/// @fn int pro_findById(Producto*, int, int)
/// @brief
/// busca el id en todos los Producto dados de alta.
/// @param list es la estructura Producto
/// @param len es la cantidad maxima de Producto
/// @param id del Producto a buscar
/// @return devuelve el indice del ID buscado si se encontro y no esta dado de baja. un -1 si hay algun error
int pro_findById(Producto* list, int len,int id)
{
	int rtn = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].idProducto == id && list[i].isEmpty != PRO_LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}


/// @fn int pro_remover(Producto*, int, int)
/// @brief
/// funcion para dar de baja a un Producto que se haya dado de alta.
/// @param list es la estructura Producto
/// @param len es la cantidad maxima de Producto
/// @param id del Producto a dar de baja
/// @return devuelve un 0 si esta OK. Un -1 si hay algun error
int pro_remover(Producto* list, int len, int id)
{
	int rtn = -1;

	if (list != NULL && len >= 0 && id < len && id >= 0 && list[id].isEmpty != PRO_LIBRE)
	{
		list[id].isEmpty = PRO_BAJA;
		rtn = 0;
	}
	return rtn;
}

/// @fn int pro_Baja(Producto*, int)
/// @brief funcion para dar de baja un Producto. se imprime la lista de Producto si hay dados de alta. Luego se pide ingresar
/// un id que se quiere dar de baja. si se ingreso un id que se encuentra dado de alta, se preocede a dar de baja en la funcion pro_remover.
/// @param list es la estructura Producto
/// @param len es la cantidad maxima de Producto
/// @return devuelve un 0 si esta OK. Un -1 si hay algun error
int pro_Baja (Producto* list, int len)
{
	int rtn = -1;
	int idIngresado;
	int index;
	int flagAlta = 0;
	if (pro_sortsByID(list,len) == 0 && pro_imprimir(list, len) == 0)
	{
		flagAlta = 1;
	}

	if (flagAlta)
	{
		if( utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n") == 0)
		{
			while (pro_findById(list, len, idIngresado) == -1)
			{
				puts("NO EXISTE ID.");
				utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n");
			}

			index = pro_findById(list, len, idIngresado);
			if (validacionDosCaracteres ("¿Esta seguro de querer borrar el producto? (S/N)", 'S', 'N') == 1)
			{
				if (pro_remover(list, len, index) == 0)
				{
					rtn = 0;
				}
			}
		}
	}
	return rtn;
}

/// @fn int pro_reponerStock(Producto*, int)
/// funcion para reponer stock
/// @param list de producto
/// @param len maxima cantidad de productos
/// @return devuelve un 0 si esta ok o -1 si hay error
int pro_reponerStock (Producto* list, int len)
{
	int rtn = -1;
	int idIngresado;
	int stockReponer = 0;
	int index;

	if (list != NULL && len > 0)
	{
		if( utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n") == 0)
		{
			while (pro_findById(list, len, idIngresado) == -1)
			{
				puts("NO EXISTE ID.");
				utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n");
			}

			index = pro_findById(list, len, idIngresado);
			utn_getIntPositivo(&stockReponer, "Ingrese la cantidad a reponer: ", "Ingrese un numero valido.");
			if (validacionDosCaracteres ("¿Esta seguro de querer reponer el producto? (S/N)", 'S', 'N') == 1)
			{
				list[index].stock += stockReponer;
				puts ("Stock añadido.");
			}
		}
		rtn = 0;
	}
	return rtn;
}

/// @fn int pro_buscarImprimirNombre(Producto*, int)
/// funcion para buscar todos los productos con el mismo nombre y ordenarlos por stock
/// @param list el array de estructuras de productos
/// @param len la cantidad maxima de productos
/// @return devuelve un 0 si esta Ok
int pro_buscarImprimirNombre(Producto* list, int len)
{
	int rtn = -1;
	char nombre[NOMBRE_LEN];
	int primer = 0;

	if (list != NULL && len > 0)
	{
		if (utn_getNombre(nombre, "Ingrese el nombre del producto: ", "Ingrese un nombre valido", NOMBRE_LEN, 3) == 0)
		{
			for (int i = 0; i < len; i++)
			{
				if (compararCadenas(nombre, list[i].nombreProducto, NOMBRE_LEN) == 3)
				{
					if (primer == 0)
					{
						primer++;
						puts("\n\t\t\t\t\t> LISTADO PRODUCTOS\n"
								"-----------------------------------------------------------------------------");
						printf("%-6s %-27s %-11s %-13s %-15s %-6s\n", "ID", "NOMBRE", "ID VENDEDOR" ,"PRECIO", "CATEGORIA", "STOCK");
					}
					pro_printOne(&list[i]);
				}
			}
			if (primer == 0)
			{
				puts ("No se encontro el producto a buscar");
			}
		}
		rtn = 0;
	}
	return rtn;
}

/// @fn int pro_sortsByStock(Producto*, int)
/// funcion para ordenar por stock
/// @param list el array de estructuras de productos
/// @param len la cantidad maxima de productos
/// @return devuelve un 0 si esta Ok
int pro_sortsByStock(Producto* list, int len)
{
	int rtn = -1;
	int i;
	int j;
	Producto auxProducto;

	if (list != NULL && len > 0)
	{
				for (i = 1; i < len; i++)
				{
					auxProducto = list[i];
					j = i - 1;
					while ( (j >= 0) && (auxProducto.stock < list[j].stock) )
					{
						list[j + 1] = list[j];
						j--;
					}
					list[j + 1] = auxProducto;
				}

				rtn = 0;
	}
	return rtn;
}


/// @fn int pro_sortsByID(Producto*, int)
/// funcion para ordenar por ID del producto
/// @param list el array de estructuras de productos
/// @param len la cantidad maxima de productos
/// @return devuelve un 0 si esta Ok
int pro_sortsByID(Producto* list, int len)
{
	int rtn = -1;
	int i;
	int j;
	Producto auxProducto;

	if (list != NULL && len > 0)
	{
				for (i = 1; i < len; i++)
				{
					auxProducto = list[i];
					j = i - 1;
					while ( (j >= 0) && (auxProducto.idProducto < list[j].idProducto) )
					{
						list[j + 1] = list[j];
						j--;
					}
					list[j + 1] = auxProducto;
				}

				rtn = 0;
	}
	return rtn;
}


int pro_altaForzadaArray(Producto* list , int len, int idVendedor, char* nombreProducto , float precio, int stock, int categoria)
{
	int rtn = -1;
	int indiceLibre;
	Producto auxiliarEstructura;

	indiceLibre = pro_indexEmpty (list, len);

	if (list != NULL && len > 0 && indiceLibre != -1)
	{
		strncpy (auxiliarEstructura.nombreProducto,nombreProducto, NOMBRE_LEN);
		auxiliarEstructura.categoria = categoria;
		auxiliarEstructura.precio = precio;
		auxiliarEstructura.stock = stock;
		auxiliarEstructura.FK_idVendedor = idVendedor;
		auxiliarEstructura.isEmpty = PRO_OCUPADO;
		auxiliarEstructura.idProducto = ePro_ObtenerID();
		list[indiceLibre] = auxiliarEstructura;
		rtn = 0;
	}
	return rtn;
}
