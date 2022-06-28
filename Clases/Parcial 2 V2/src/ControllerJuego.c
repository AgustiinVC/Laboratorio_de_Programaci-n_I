/*
 * ControllerJuego.c
 *
 *  Created on: 28 jun. 2022
 *      Author: Agostin
 */



#include "ControllerJuego.h"

static const char JUEGOS_TIPOS [4][11] = {"Plataforma", "Laberinto", "Aventura", "Otros"};

/** \brief Carga los datos de los Juegos desde el archivo dataJuegos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJuego LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerJuego_loadJuegoFromText(char* path , LinkedList* pArrayListJuego)
{
	int rtn = -1;
	FILE* pArchivoJuego;

	if (path != NULL && pArrayListJuego != NULL)
	{
		pArchivoJuego = fopen(path, "r");
		if (pArchivoJuego != NULL)
		{
			if (parser_JuegoFromText(pArchivoJuego, pArrayListJuego) == 0)
			{
				rtn = 0;
			}
		}

	}
	fclose (pArchivoJuego);
    return rtn;
}

//----------------------------------------------------------------------------------------------------------------

/** \brief Guarda los datos de los Juegos en el archivo dataJuegos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJuegos LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerJuego_saveJuegoAsText(char* path , LinkedList* pArrayListJuegos)
{
	int rtn = -1;
	int lenLista;
	int i;
	Juego* pAux;
	FILE* pArchivo = NULL;

	int auxId;
	char auxIdStr[8];
	char auxNombre [NOMBRE_LEN];
	char auxEmpresa [EMPRESA_LEN];
	int auxTipoJuego;

	if (pArrayListJuegos != NULL)
	{
		lenLista = ll_len(pArrayListJuegos);
		pArchivo = fopen (path, "w");
		pAux = Juego_new();

		if (pArchivo != NULL && lenLista < MAX_JUEGOS && lenLista > 0)
		{
			fprintf (pArchivo, "%s,%s,%s,%s\n", "id", "nombre", "empresa", "tipoGenero");
			for (i = 0; i < lenLista; i++)
			{
				pAux = ll_get(pArrayListJuegos, i);
				if (pAux != NULL)
				{
					Juego_getId(pAux, &auxId);
					sprintf(auxIdStr, "%d",auxId);
					Juego_getNombre(pAux, auxNombre);
					Juego_getEmpresa(pAux, auxEmpresa);
					Juego_getTipoGenero(pAux, &auxTipoJuego);

					fprintf(pArchivo, "%s,%s,%s,%s\n", auxIdStr, auxNombre, auxEmpresa, JUEGOS_TIPOS[auxTipoJuego-1]);
					rtn = 0;
				}
			}
			fclose (pArchivo);
		}
	}
    return rtn;
}

//--------------------------------------------------------------------------------------------------------------------------------------
//JUEGOS


/** \brief Alta de Juego
 *
 * \param path char*
 * \param pArrayListJuegos LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerJuego_addJuego(LinkedList* pArrayListJuegos)
{
	int rtn = -1;
	int auxId;
	char auxNombre[NOMBRE_LEN];
	char auxEmpresa [EMPRESA_LEN];
	int auxTipoGenero;
	Juego* pJuego = Juego_new();

	if (pArrayListJuegos != NULL)
	{
		if (utn_getNombre(auxNombre, "Ingrese su nombre: ", "Ingrese un nombre valido.", NOMBRE_LEN, 3) == 0 &&
			utn_getNombre(auxEmpresa, "Ingrese su empresa: ", "Ingrese una empresa valida.", EMPRESA_LEN, 3) == 0 &&
			utn_getIntRange(&auxTipoGenero, "Ingrese el tipo de genero del juego: "
					"\n\t 1 = Plataforma\n\t 2 = Laberinto\n\t 3 = Aventura\n\t 4 = Otros\nIngrese su opcion: ", "Ingrese un genero de juego valido\n", 1, 4) == 0)
		{

			auxId = Juego_generarIdUnico();
			Juego_setId(pJuego, auxId);
			Juego_setNombre(pJuego, auxNombre);
			Juego_setEmpresa(pJuego, auxEmpresa);
			Juego_setTipoGenero(pJuego, auxTipoGenero);
			if (pJuego != NULL && ll_add(pArrayListJuegos, pJuego) == 0)
			{
				printf("%-6s %-50s %-50s %-12s\n", "ID", "NOMBRE", "EMPRESA", "GENERO");
				Juego_print(pJuego);
				rtn = 0;
			}
		}

	}
    return rtn;
}

/** \brief Listar Juego
 *	imprimir la lista de Juego
 * \param pArrayListJuegos LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerJuego_listJuego(LinkedList* pArrayListJuegos)
{
	int rtn = -1;
	int i;
	int lenJuegos;
	Juego* pAuxJuego;

	if (pArrayListJuegos != NULL)
	{
		lenJuegos = ll_len(pArrayListJuegos);
		if (lenJuegos > 0 && lenJuegos < MAX_JUEGOS)
		{
			puts("\n\t\t\t\t\t> LISTADO JUEGOS\n"
				"--------------------------------------------------------------------------------------"
				"-------------------------------------");
			printf("%-6s %-50s %-50s %-12s\n", "ID", "NOMBRE", "EMPRESA", "GENERO");
			for (i = 0; i < lenJuegos; i++)
			{
				pAuxJuego = (Juego*)ll_get(pArrayListJuegos, i);
				if (pAuxJuego != NULL)
				{
					if (Juego_print(pAuxJuego) == 0)
					{
						rtn = 0;
					}
				}
			}
		}
	}
    return rtn;
}

//---------------------------------------------------------------------------------------------------------------------

/// @fn int controller_getIndexById(LinkedList*, int)
/// @brief obtenemos el indice del id que tomamos
///
/// @param pArrayList
/// @param id a tener que buscar el indice
/// @return el indice del id a buscar o un -1 si hay error
int controllerJuego_getIndexJuegoById(LinkedList* pArrayList, int id)
{
	int rtn = -1;
	int i;
	int auxId;
	int lenLista;
	Juego* auxJuego;

	if (pArrayList != NULL && id > 0)
	{
		lenLista = ll_len(pArrayList);

		if (lenLista > 0)
		{
			for (i = 0; i < lenLista; i++)
			{
				auxJuego = ll_get(pArrayList, i);
				Juego_getId(auxJuego, &auxId);
				if (auxJuego != NULL && auxId == id)
				{
					rtn = i;
					break;
				}
			}
		}
	}
    return rtn;
}
