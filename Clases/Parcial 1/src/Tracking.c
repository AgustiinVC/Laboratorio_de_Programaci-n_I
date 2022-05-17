/*
 * Tracking.c
 *
 *  Created on: 14 may. 2022
 *      Author: Agostin
 */

#include "validaciones.h"
#include "Tracking.h"

//ESTADOS DE TRACKING A IMPRIMIR
static const char ESTADO_TRACKING [3][10] = {"EN VIAJE", "ENTREGADO", "CANCELADO"};

//TABLA CODIGO POSTAL Y KM SEGUN COD POSTAL
static const int CODIGO_POSTAL [4] = {1000, 3000, 5000, 8000};
static const int KM_COD_POSTAL [5] = {20, 30, 50, 80, 150};

/// @fn long int time_Current(void)
/// @return tiempo actual
long int time_Current (void)
{
	return time (NULL);
}

/// @fn long int time_Add(double)
/// @param secondsAdd cantidad de segundos a añadir
/// @return el tiempo actual mas la cantidad de segundos que hayamos ingresado
long int time_Add (double secondsAdd)
{
	return secondsAdd + time_Current ();
}


/// @fn int tra_initArray(Tracking*, int)
/// @brief
/// funcion para iniciar la estructura Tracking al poner en LIBRE el campo isEmpty
/// @param list es la estructura Tracking
/// @param len es el tamaño de la estructura
/// @return devuelve un 0 si esta OK. Devuelve un -1 si hay algun error.
int tra_initArray(Tracking* list, int len)
{
	int rtn = -1;
	int i;
	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = TRA_LIBRE;
			rtn = 0;
		}
	}
	return rtn;
}

/// @fn int tra_indexEmpty(Tracking*, int)
/// @brief
/// funcion para buscar un indice que este vacio
/// @param list es la estructura Tracking
/// @param len es el tamaño de la estructura
/// @return devuelve el indice que se encuentra libre.. Devuelve un -1 si hay algun error.
int tra_indexEmpty (Tracking* list, int len)
{
	int rtn = -1;
	int i;
	if (list != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == TRA_LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/// @fn int calculoKM(int)
/// @param codPostal
/// @return la cantidad de km segun el codigo postal
int calculoKM (int codPostal)
{
	int rtn;
	if (codPostal < CODIGO_POSTAL[0]+1)
	{
		rtn = 0;
	}
	else if (codPostal > CODIGO_POSTAL[0] && codPostal < CODIGO_POSTAL[1]+1)
	{
		rtn = 1;
	}
	else if (codPostal > CODIGO_POSTAL[1] && codPostal < CODIGO_POSTAL[2]+1)
	{
		rtn = 2;
	}
	else if (codPostal > CODIGO_POSTAL[2] && codPostal < CODIGO_POSTAL[3]+1)
	{
		rtn = 3;
	}
	else
	{
		rtn = 4;
	}
	return rtn = KM_COD_POSTAL[rtn];
}


/// @fn int actualizarEstado(Tracking*, int, int)
/// @brief funcion para actualizar el estado de los tracking. si ya paso el tiempo que tardaba una compra,
/// esta pasa de En Viaje a Entregado si no se encuentra Cancelada durante el vieja.
/// @param list es el array de estructura de tracking
/// @param len es la cantidad maxima de trakcing
/// @param userId es el usuario logueado
/// @return un 0 si esta Ok y un -1 si hay error
int actualizarEstado (Tracking* list, int len, int userId)
{
	int rtn = -1;

	if (list != NULL && len > 0 && userId >= 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].FK_idComprador == userId &&list[i].isEmpty == TRA_EN_VIAJE)
			{
				if (difftime(list[i].horaLlegada, time_Current() ) < 0)
				{
					list[i].isEmpty = TRA_ENTREGADO;
				}
			}
			if (list[i].FK_idComprador == userId &&
				list[i].isEmpty == TRA_CANCELADO)
			{
				list[i].horaLlegada = 0;
			}
		}
		rtn = 0;
	}
	return rtn;
}

/// @fn int tra_findById(Tracking*, int, int)
/// @brief
/// busca el id en todos los Tracking EN VIaje
/// @param list es la estructura Tracking
/// @param len es la cantidad maxima de Tracking
/// @param id del Producto a buscar
/// @return devuelve el indice del ID buscado si se encontro y no esta dado de baja. un -1 si hay algun error
int tra_findById(Tracking* list, int len,int id)
{
	int rtn = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].idProducto == id && list[i].isEmpty == TRA_EN_VIAJE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/// @fn int tra_imprimir(Tracking*, int)
/// @brief
/// funcion para imprimir los Tracking dados de alta
/// @param list es la estructura Tracking
/// @param length es la cantidad maxima de Tracking
/// @return devuelve un 0 si esta ok. un -1 si hay un error.
int tra_imprimir(Tracking* list, int length)
{
	int rtn = -1;
	int flagPrimerProducto = 0;

	if (list != NULL && length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i].isEmpty != TRA_LIBRE)
			{
				if (flagPrimerProducto == 0)
				{
					flagPrimerProducto = 1;
					puts("\n\t> LISTADO TRACKING GLOBAL\n"
							"--------------------------------------------");
					printf("%-6s %-11s %-13s %-s\n", "ID", "ESTADO", "ID COMPRADOR", "ID VENDEDOR");
				}

				tra_printOne (&list[i]);
				rtn = 0;
			}
		}
		puts (" ");
	}

	return rtn;
}

/// @fn void tra_printOne(Tracking*)
/// @brief
/// impresion de un solo Tracking
/// @param list es el Producto que se va a imprimir
void tra_printOne (Tracking* list)
{
	printf ("%-6d %-11s %-13d %-d\n",
		list->idTracking, ESTADO_TRACKING [(list->isEmpty)-1], list->FK_idComprador, list->FK_idVendedor);
}
