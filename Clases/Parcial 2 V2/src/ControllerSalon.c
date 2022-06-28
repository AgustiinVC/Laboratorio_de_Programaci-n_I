/*
 * ControllerSalon.c
 *
 *  Created on: 28 jun. 2022
 *      Author: Agostin
 */


#include "ControllerSalon.h"

static const char SALONES_TIPOS [2][9] = {"Shopping", "Local"};

/** \brief Carga los datos de los salones desde el archivo dataSalones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSalon LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerSalon_loadSalonFromText(char* path , LinkedList* pArrayListSalon)
{
	int rtn = -1;
	FILE* pArchivoSalon;

	if (path != NULL && pArrayListSalon != NULL)
	{
		pArchivoSalon = fopen(path, "r");
		if (pArchivoSalon != NULL)
		{
			if (parser_SalonesFromText(pArchivoSalon, pArrayListSalon) == 0)
			{
				rtn = 0;
			}
		}

	}
	fclose (pArchivoSalon);
    return rtn;
}


//----------------------------------------------------------------------------------------------------------------

/** \brief Guarda los datos de los Salones en el archivo dataSalones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSalones LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerSalon_saveSalonAsText(char* path , LinkedList* pArrayListSalones)
{
	int rtn = -1;
	int lenLista;
	int i;
	Salon* pAux;
	FILE* pArchivo = NULL;

	int auxId;
	char auxIdStr[8];
	char auxNombre [NOMBRE_LEN];
	char auxDireccion [DIRECCION_LEN];
	int auxTipoSalon;
	int cantArcades;

	if (pArrayListSalones != NULL)
	{
		lenLista = ll_len(pArrayListSalones);
		pArchivo = fopen (path, "w");
		pAux = Salon_new();

		if (pArchivo != NULL && lenLista < MAX_SALONES && lenLista > 0)
		{
			fprintf (pArchivo, "%s,%s,%s,%s,%s\n", "id", "nombre", "direccion", "tipoSalon","cantArcades");
			for (i = 0; i < lenLista; i++)
			{
				pAux = ll_get(pArrayListSalones, i);
				if (pAux != NULL)
				{
					Salon_getId(pAux, &auxId);
					sprintf(auxIdStr, "%d",auxId);
					Salon_getNombre(pAux, auxNombre);
					Salon_getDireccion(pAux, auxDireccion);
					Salon_getTipoSalon(pAux, &auxTipoSalon);
					Salon_getCantidadArcades(pAux, &cantArcades);

					fprintf(pArchivo, "%s,%s,%s,%s,%d\n", auxIdStr, auxNombre, auxDireccion, SALONES_TIPOS[auxTipoSalon-1],cantArcades);
					rtn = 0;
				}
			}
			fclose (pArchivo);
		}
	}
    return rtn;
}


//-----------------------------------------------------------------------------------------------------------------
// SALON

/** \brief Alta de Salon
 *
 * \param path char*
 * \param pArrayListSalon LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerSalon_addSalon(LinkedList* pArrayListSalon)
{
	int rtn = -1;
	int auxId;
	char auxNombre[NOMBRE_LEN];
	char auxDireccion [DIRECCION_LEN];
	int auxTipoSalon;
	Salon* pSalon = Salon_new();

	if (pArrayListSalon != NULL)
	{
		if (utn_getNombre(auxNombre, "Ingrese su nombre: ", "Ingrese un nombre valido.", NOMBRE_LEN, 3) == 0 &&
			utn_getDescripcion(auxDireccion, "Ingrese su direccion: ", "Ingrese una direccion valida.", DIRECCION_LEN, 3) == 0 &&
			utn_getIntRange(&auxTipoSalon, "Ingrese el tipo de salon: "
					"\n\t 1 = Shopping\n\t 2 = Local\nIngrese su opcion: ", "Ingrese un tipo de salon valido\n", 1, 2) == 0)
		{
			auxId = Salon_generarIdUnico();
			Salon_setId(pSalon, auxId);
			Salon_setNombre(pSalon, auxNombre);
			Salon_setDireccion(pSalon, auxDireccion);
			Salon_setTipoSalon(pSalon, auxTipoSalon);
			Salon_setCantidadArcades(pSalon, 0);

			if (pSalon != NULL && ll_add(pArrayListSalon, pSalon) == 0)
			{
				printf("%-6s %-50s %-50s %-12s\n", "ID", "NOMBRE", "DIRECCION", "TIPO SALON");
				Salon_print(pSalon);
				rtn = 0;
			}
		}

	}
    return rtn;
}

/** \brief Baja de Salon
 *
 * \param pArrayListSalon LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerSalon_removeSalon(LinkedList* pArrayListSalon, LinkedList* pArrayArcade)
{
	int rtn = -1;
	int auxId;
	int busquedaId;
	int i;
	int FKIdSalon;
	int lenArcade = ll_len(pArrayArcade);
	Salon* pAuxSalon;
	Arcade* pAuxArcade;

	if (pArrayListSalon != NULL && ll_len(pArrayListSalon) > 0)
	{

		do
		{
			controllerSalon_listSalon(pArrayListSalon);
			utn_getIntPositivo(&auxId,"Ingrese el ID del Salon: ", "Error, ingrese un ID valido\n");
			busquedaId = controllerSalon_getIndexSalonById(pArrayListSalon, auxId);
		}
		while (busquedaId == -1);

		pAuxSalon = ll_get(pArrayListSalon, busquedaId);
		puts("\n\t\t\t\t\t\t\t\t> LISTADO Salones\n"
			"--------------------------------------------------------------------------------------"
			"-------------------------------------------------------------------------------");
		printf("%-6s %-50s %-50s %-12s\n", "ID", "NOMBRE", "DIRECCION", "TIPO SALON");
		Salon_print(pAuxSalon);
		if (validacionDosCaracteres ("\n¿Seguro quiere eliminar el Salon? (S/N): ", 'S', 'N') == 1)
		{
			if (lenArcade > 0)
			{
				for (i = 0; i < lenArcade; i++)
				{
					pAuxArcade = ll_get(pArrayArcade, i);
					Arcade_getFK_IdSalon(pAuxArcade, &FKIdSalon);
					if (FKIdSalon == auxId)
					{
						ll_remove(pArrayArcade, i);
					}
				}
			}
			ll_remove(pArrayListSalon, busquedaId);

			rtn = 0;
		}
	}
    return rtn;
}


/** \brief Listar Salones
 *	imprimir la lista de Salon
 * \param pArrayListSalon LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerSalon_listSalon(LinkedList* pArrayListSalon)
{
	int rtn = -1;
	int i;
	int lenSalones;
	Salon* pAuxSalon;

	if (pArrayListSalon != NULL)
	{
		lenSalones = ll_len(pArrayListSalon);
		if (lenSalones > 0 && lenSalones < MAX_SALONES)
		{
			puts("\n\t\t\t\t\t> LISTADO Salones\n"
				"-------------------------------------------------------------------------"
				"---------------------------------------------------");
			printf("%-6s %-50s %-50s %-12s\n", "ID", "NOMBRE", "DIRECCION", "TIPO SALON");
			for (i = 0; i < lenSalones; i++)
			{
				pAuxSalon = (Salon*)ll_get(pArrayListSalon, i);
				if (pAuxSalon != NULL)
				{
					if (Salon_print(pAuxSalon) == 0)
					{
						printf("\n");
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
int controllerSalon_getIndexSalonById(LinkedList* pArrayList, int id)
{
	int rtn = -1;
	int i;
	int auxId;
	int lenLista;
	Salon* auxSalon;

	if (pArrayList != NULL && id > 0)
	{
		lenLista = ll_len(pArrayList);

		if (lenLista > 0)
		{
			for (i = 0; i < lenLista; i++)
			{
				auxSalon = ll_get(pArrayList, i);
				Salon_getId(auxSalon, &auxId);
				if (auxSalon != NULL && auxId == id)
				{
					rtn = i;
					break;
				}
			}
		}
	}
    return rtn;
}
