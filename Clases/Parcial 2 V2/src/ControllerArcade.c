/*
 * ControllerArcade.c
 *
 *  Created on: 28 jun. 2022
 *      Author: Agostin
 */



#include "ControllerArcade.h"


static const char ARCADES_TIPOS [2][8] = {"MONO", "ESTEREO"};


/** \brief Carga los datos de los salones desde el archivo dataSalones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerArcade_loadArcadeFromText(char* path , LinkedList* pArrayListArcade)
{
	int rtn = -1;
	FILE* pArchivoArcade;

	if (path != NULL && pArrayListArcade != NULL)
	{
		pArchivoArcade = fopen(path, "r");
		if (pArchivoArcade != NULL)
		{
			if (parser_ArcadesFromText(pArchivoArcade, pArrayListArcade) == 0)
			{
				rtn = 0;
			}
		}

	}
	fclose (pArchivoArcade);
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
int controllerArcade_saveArcadeAsText(char* path , LinkedList* pArrayListArcades)
{
	int rtn = -1;
	int lenLista;
	int i;
	Arcade* pAux;
	FILE* pArchivo = NULL;

	int auxId;
	int auxIdSalon;
	int auxIdJuego;
	int auxCantJug;
	int auxCantFichas;
	char auxIdStr[8];
	char auxIdSalonStr[8];
	char auxIdJuegoStr[8];
	char auxCantJugStr[8];
	char auxCantFichasStr[8];
	char auxNacionalidad [NACIONALIDAD_LEN];
	int auxTipoSonido;

	if (pArrayListArcades != NULL)
	{
		lenLista = ll_len(pArrayListArcades);
		pArchivo = fopen (path, "w");
		pAux = Arcade_new();

		if (pArchivo != NULL && lenLista < MAX_ARCADES && lenLista > 0)
		{
			fprintf (pArchivo, "%s,%s,%s,%s,%s,%s,%s\n", "id", "nacionalidad", "tipoSonido", "cantJugadores", "cantFichas","idSalon", "idJuego");
			for (i = 0; i < lenLista; i++)
			{
				pAux = ll_get(pArrayListArcades, i);
				if (pAux != NULL)
				{
					Arcade_getId(pAux, &auxId);
					sprintf(auxIdStr, "%d",auxId);
					Arcade_getNacionalidad(pAux, auxNacionalidad);
					Arcade_getTipoSonido(pAux, &auxTipoSonido);
					Arcade_getCantJugadores(pAux, &auxCantJug);
					sprintf(auxCantJugStr, "%d",auxCantJug);
					Arcade_getCantidadMaxFichas (pAux, &auxCantFichas);
					sprintf(auxCantFichasStr, "%d",auxCantFichas);
					Arcade_getFK_IdSalon (pAux, &auxIdSalon);
					sprintf(auxIdSalonStr, "%d",auxIdSalon);
					Arcade_getFK_IdJuego (pAux, &auxIdJuego);
					sprintf(auxIdJuegoStr, "%d",auxIdJuego);

					fprintf(pArchivo, "%s,%s,%s,%s,%s,%s,%s\n", auxIdStr, auxNacionalidad, ARCADES_TIPOS[auxTipoSonido-1], auxCantJugStr, auxCantFichasStr, auxIdSalonStr, auxIdJuegoStr);
					rtn = 0;
				}
			}
			fclose (pArchivo);
		}
	}
    return rtn;
}

//------------------------------------------------------------------------------------------------------------------------
// ARCADES

/** \brief Alta de ARCADE
 *
 * \param path char*
 * \param pArrayListSalon LinkedList*
 * \param pArrayListArcade LinkedList*
 * \param pArrayListJuego LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerArcade_addArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int auxId;
	char auxNacionalidad [NACIONALIDAD_LEN];
	int auxTipoSonido;
	int auxCantidadJugadores;
	int auxCantidadFichas;
	int auxIdSalon;
	int auxIdJuego;
	int busquedaId;
	int busquedaIdSalon;
	int auxCantArcades;
	int lenSalon = ll_len(pArrayListSalon);
	int lenJuego = ll_len(pArrayListJuego);
	Arcade* pArcade = Arcade_new();
	Salon* pAuxSalon;


	if (pArrayListArcade != NULL && lenSalon > 0 && lenJuego > 0)
	{
		if (utn_getNombre(auxNacionalidad, "Ingrese su nacionalidad: ", "Ingrese una nacionalidad.", NACIONALIDAD_LEN, 3) == 0 &&
			utn_getIntRange(&auxTipoSonido, "Ingrese el tipo de sonido: "
					"\n\t 1 = MONO\n\t 2 = ESTEREO\nIngrese su opcion: ", "Ingrese un tipo de salon valido\n", 1, 2) == 0 &&
			utn_getIntPositivo (&auxCantidadJugadores, "Ingrese la cantidad de jugadores: ", "Ingrese una cantidad de jugadores valida.") == 0 &&
			utn_getIntPositivo (&auxCantidadFichas, "Ingrese la cantidad maxima de fichas: ", "Ingrese una cantidad valida.") == 0)
		{
			do
			{
				controllerSalon_listSalon(pArrayListSalon);
				utn_getIntPositivo(&auxIdSalon,"Ingrese el ID del Salon: ", "Error, ingrese un ID valido");
				busquedaIdSalon = controllerSalon_getIndexSalonById(pArrayListSalon, auxIdSalon);
			}
			while (busquedaIdSalon == -1);

			do
			{
				controllerJuego_listJuego(pArrayListJuego);
				utn_getIntPositivo(&auxIdJuego,"Ingrese el ID del Juego: ", "Error, ingrese un ID valido");
				busquedaId = controllerJuego_getIndexJuegoById(pArrayListJuego, auxIdJuego);
			}
			while (busquedaId == -1);
			pAuxSalon = ll_get(pArrayListSalon, busquedaIdSalon);
			Salon_getCantidadArcades(pAuxSalon, &auxCantArcades);
			auxCantArcades++;
			Salon_setCantidadArcades(pAuxSalon, auxCantArcades);
			ll_set(pArrayListSalon, busquedaIdSalon, pAuxSalon);
			auxId = Arcade_generarIdUnico();
			Arcade_setId(pArcade, auxId);
			Arcade_setNacionalidad(pArcade, auxNacionalidad);
			Arcade_setTipoSonido(pArcade, auxTipoSonido);
			Arcade_setCantJugadores(pArcade, auxCantidadJugadores);
			Arcade_setCantidadMaxFichas(pArcade, auxCantidadFichas);
			Arcade_setFK_IdSalon(pArcade, auxIdSalon);
			Arcade_setFK_IdJuego(pArcade, auxIdJuego);

			if (pArcade != NULL && ll_add(pArrayListArcade, pArcade) == 0)
			{
				printf("\n%-6s %-50s %-10s %-9s %-12s\n", "ID", "NACIONALIDAD", "TIPO ARCADE", "CANT JUG", "CANT FICHAS");
				Arcade_print(pArcade);
				rtn = 0;
			}
		}

	}
    return rtn;
}


/** \brief Modificar datos de Arcade
 *
 * \param path char*
 * \param pArrayListSalon LinkedList*
 * \param pArrayListArcade LinkedList*
 * \param pArrayListJuego LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerArcade_editArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int idBuscado;
	int opcion;
	int auxId;
	int idJuego;
	int respuesta;

	Arcade* pAuxArcade;

	pAuxArcade = Arcade_new();

	if (pArrayListJuego != NULL && ll_len(pArrayListJuego) > 0 && pArrayListArcade != NULL && ll_len(pArrayListArcade) > 0)
	{
		do
		{
			controllerArcade_listArcade(pArrayListSalon, pArrayListArcade, pArrayListJuego);
			utn_getIntPositivo(&auxId,"Ingrese el ID del Arcade: ", "Error, ingrese un ID valido");
			idBuscado = controllerArcade_getIndexArcadeById(pArrayListArcade, auxId);
		}
		while (idBuscado == -1);

		do
		{
			pAuxArcade = ll_get(pArrayListArcade, idBuscado);
			puts("\n\t\t\t\t\t\t\t\t> ARCADE\n"
			"--------------------------------------------------------------------------------------"
			"-------------------------------------------------------------------------------");
			printf("%-6s %-50s %-12s %-12s %-12s %-10s %-10s\n", "ID", "NACIONALIDAD", "TIPO SONIDO", "CANT JUG", "CANT FICHAS", "ID SALON", "ID JUEGO");
			Arcade_print(pAuxArcade);
			fflush(stdin);

			utn_getIntRange (&opcion ,"\nIngrese la opcion a modificar:\n "
										"1 - Cantidad Jugadores\n "
										"2 - Juego\n "
										"3 - Salir\n"
										"Ingrese su opcion: ",
										"Error. Ingrese una opcion correcta\n\n", 1, 3);

			switch (opcion)
			{
				case 1:
					if( utn_getIntPositivo (&pAuxArcade->cantidadJugadores, "Ingrese la cantidad de jugadores: ", "Ingrese una cantidad valida\n\n") == 0)
					{
						puts ("Cantidad de jugadores actualizado.\n");
					}
					else
					{
						puts("No se pudo actualizar la cantidad de jugadores.");
					}
					break;

				case 2:
					do
					{
						controllerJuego_listJuego(pArrayListJuego);
						utn_getIntPositivo(&idJuego,"Ingrese el ID del Arcade: ", "Error, ingrese un ID valido");
						idBuscado = controllerJuego_getIndexJuegoById(pArrayListJuego, idJuego);
					}
					while (idBuscado == -1);

					Arcade_setFK_IdJuego(pAuxArcade, idJuego);
					break;

				case 3:
					respuesta = 0;
					break;
			}
			if (opcion != 3)
			{
				respuesta = validacionDosCaracteres ("¿Desea modificar otro campo? (S/N)", 'S', 'N');
			}
		}
		while (respuesta);

		if (ll_set(pArrayListArcade, idBuscado, pAuxArcade) == 0)
		{
			rtn = 0;
		}
	}
    return rtn;
}


/** \brief Baja de Arcade
 *
 * \param path char*
 * \param pArrayListSalon LinkedList*
 * \param pArrayListArcade LinkedList*
 * \param pArrayListJuego LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerArcade_removeArcade (LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int auxId;
	int busquedaId;
	Arcade* pAuxArcade;

	if (pArrayListArcade != NULL && ll_len(pArrayListArcade) > 0)
	{
		do
		{
			controllerArcade_listArcade(pArrayListSalon, pArrayListArcade, pArrayListJuego);
			utn_getIntPositivo(&auxId,"Ingrese el ID del Arcade: ", "Error, ingrese un ID valido");
			busquedaId = controllerArcade_getIndexArcadeById(pArrayListArcade, auxId);
		}while (busquedaId == -1);

		pAuxArcade = ll_get(pArrayListArcade, busquedaId);
		puts("\n\t\t\t\t\t\t\t\t> ARCADE\n"
					"--------------------------------------------------------------------------------------"
					"-------------------------------------------------------------------------------");
		printf("%-6s %-50s %-12s %-12s %-12s %-10s %-10s\n", "ID", "NACIONALIDAD", "TIPO SONIDO", "CANT JUG", "CANT FICHAS", "ID SALON", "ID JUEGO");
		Arcade_print(pAuxArcade);
		if (validacionDosCaracteres ("¿Seguro quiere eliminar el Arcade? (S/N): ", 'S', 'N') == 1)
		{
			ll_remove(pArrayListArcade, busquedaId);
			rtn = 0;
		}
	}
    return rtn;
}


/** \brief Listar Arcade
 *	imprimir la lista de Arcade, Salon y Juegos
 * \param pArrayListSalon LinkedList*
 * \param pArrayListArcade LinkedList*
 * \param pArrayListJuego LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controllerArcade_listArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int i;
	int auxIndex;
	int lenArcade;
	Salon* pAuxSalon;
	Arcade* pAuxArcade;
	Juego* pAuxJuego;

	if (pArrayListSalon != NULL && pArrayListArcade != NULL && pArrayListJuego != NULL)
	{
		lenArcade = ll_len(pArrayListArcade);
		if (lenArcade > 0 && lenArcade < MAX_ARCADES)
		{
			puts("\n\t\t\t\t> ARCADE \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t> SALON \t\t\t\t\t\t\t\t\t\t\t\t\t\t> JUEGO");
			puts("------------------------------------------------------------------------------------------------------"
			"------------------------------------------------------------------------------------------------------"
			"------------------------------------------------------------------------------------------------------"
			"---------------------------------------");
			printf("%-6s %-50s %-12s %-9s %-12s || ", "ID", "NACIONALIDAD", "TIPO SONIDO", "CANT JUG", "CANT FICHAS");
			printf("%-6s %-50s %-50s %-12s || ", "ID", "NOMBRE", "DIRECCION", "TIPO SALON");
			printf ("%-6s %-50s %-50s %-12s\n", "ID", "NOMBRE", "EMPRESA", "GENERO");
			for (i = 0; i < lenArcade; i++)
			{
				pAuxArcade = (Arcade*)ll_get(pArrayListArcade, i);
				auxIndex = controllerSalon_getIndexSalonById(pArrayListSalon, pAuxArcade->FK_idSalon);
				pAuxSalon = (Salon*)ll_get(pArrayListSalon, auxIndex);
				auxIndex = controllerJuego_getIndexJuegoById(pArrayListJuego, pAuxArcade->FK_idJuego);
				pAuxJuego = (Juego*)ll_get(pArrayListJuego, auxIndex);
				if (pAuxArcade != NULL && pAuxSalon != NULL && pAuxJuego != NULL)
				{
					if (Arcade_print(pAuxArcade) == 0 && Salon_print(pAuxSalon) == 0 && Juego_print(pAuxJuego) == 0)
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
int controllerArcade_getIndexArcadeById(LinkedList* pArrayList, int id)
{
	int rtn = -1;
	int i;
	int auxId;
	int lenLista;
	Arcade* auxArcade;

	if (pArrayList != NULL && id > 0)
	{
		lenLista = ll_len(pArrayList);

		if (lenLista > 0)
		{
			for (i = 0; i < lenLista; i++)
			{
				auxArcade = ll_get(pArrayList, i);
				Arcade_getId(auxArcade, &auxId);
				if (auxArcade != NULL && auxId == id)
				{
					rtn = i;
					break;
				}
			}
		}
	}
    return rtn;
}
