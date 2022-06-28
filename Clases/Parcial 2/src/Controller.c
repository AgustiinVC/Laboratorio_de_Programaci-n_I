/*
 * Controller.c
 *
 *  Created on: 26 jun. 2022
 *      Author: Agostin
 */

#include "Controller.h"

static const char SALONES_TIPOS [2][9] = {"Shopping", "Local"};
static const char ARCADES_TIPOS [2][8] = {"MONO", "ESTEREO"};
static const char JUEGOS_TIPOS [4][11] = {"Plataforma", "Laberinto", "Aventura", "Otros"};

/** \brief Carga los datos de los salones desde el archivo dataSalones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSalon LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controller_loadSalonFromText(char* path , LinkedList* pArrayListSalon)
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

/** \brief Carga los datos de los salones desde el archivo dataSalones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListArcade LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controller_loadArcadeFromText(char* path , LinkedList* pArrayListArcade)
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

/** \brief Carga los datos de los Juegos desde el archivo dataJuegos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJuego LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controller_loadJuegoFromText(char* path , LinkedList* pArrayListJuego)
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

/** \brief Guarda los datos de los Salones en el archivo dataSalones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSalones LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controller_saveSalonAsText(char* path , LinkedList* pArrayListSalones)
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

/** \brief Guarda los datos de los Salones en el archivo dataSalones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSalones LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controller_saveArcadeAsText(char* path , LinkedList* pArrayListArcades)
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

/** \brief Guarda los datos de los Juegos en el archivo dataJuegos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJuegos LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controller_saveJuegoAsText(char* path , LinkedList* pArrayListJuegos)
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

//-----------------------------------------------------------------------------------------------------------------
// SALON

/** \brief Alta de Salon
 *
 * \param path char*
 * \param pArrayListSalon LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controller_addSalon(LinkedList* pArrayListSalon)
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
int controller_removeSalon(LinkedList* pArrayListSalon, LinkedList* pArrayArcade)
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
			controller_listSalon(pArrayListSalon);
			utn_getIntPositivo(&auxId,"Ingrese el ID del Salon: ", "Error, ingrese un ID valido\n");
			busquedaId = controller_getIndexSalonById(pArrayListSalon, auxId);
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
int controller_listSalon(LinkedList* pArrayListSalon)
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
int controller_addArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
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
				controller_listSalon(pArrayListSalon);
				utn_getIntPositivo(&auxIdSalon,"Ingrese el ID del Salon: ", "Error, ingrese un ID valido");
				busquedaIdSalon = controller_getIndexSalonById(pArrayListSalon, auxIdSalon);
			}
			while (busquedaIdSalon == -1);

			do
			{
				controller_listJuego(pArrayListJuego);
				utn_getIntPositivo(&auxIdJuego,"Ingrese el ID del Juego: ", "Error, ingrese un ID valido");
				busquedaId = controller_getIndexJuegoById(pArrayListJuego, auxIdJuego);
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
int controller_editArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
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
			controller_listArcade(pArrayListSalon, pArrayListArcade, pArrayListJuego);
			utn_getIntPositivo(&auxId,"Ingrese el ID del Arcade: ", "Error, ingrese un ID valido");
			idBuscado = controller_getIndexArcadeById(pArrayListArcade, auxId);
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
						controller_listJuego(pArrayListJuego);
						utn_getIntPositivo(&idJuego,"Ingrese el ID del Arcade: ", "Error, ingrese un ID valido");
						idBuscado = controller_getIndexJuegoById(pArrayListJuego, idJuego);
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
int controller_removeArcade (LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int auxId;
	int busquedaId;
	Arcade* pAuxArcade;

	if (pArrayListArcade != NULL && ll_len(pArrayListArcade) > 0)
	{
		do
		{
			controller_listArcade(pArrayListSalon, pArrayListArcade, pArrayListJuego);
			utn_getIntPositivo(&auxId,"Ingrese el ID del Arcade: ", "Error, ingrese un ID valido");
			busquedaId = controller_getIndexArcadeById(pArrayListArcade, auxId);
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
int controller_listArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
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
				auxIndex = controller_getIndexSalonById(pArrayListSalon, pAuxArcade->FK_idSalon);
				pAuxSalon = (Salon*)ll_get(pArrayListSalon, auxIndex);
				auxIndex = controller_getIndexJuegoById(pArrayListJuego, pAuxArcade->FK_idJuego);
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

//--------------------------------------------------------------------------------------------------------------------------------------
//JUEGOS


/** \brief Alta de Juego
 *
 * \param path char*
 * \param pArrayListJuegos LinkedList*
 * \return int un 0 si esta OK y un -1 si hay error
 *
 */
int controller_addJuego(LinkedList* pArrayListJuegos)
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
int controller_listJuego(LinkedList* pArrayListJuegos)
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
int controller_getIndexSalonById(LinkedList* pArrayList, int id)
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

/// @fn int controller_getIndexById(LinkedList*, int)
/// @brief obtenemos el indice del id que tomamos
///
/// @param pArrayList
/// @param id a tener que buscar el indice
/// @return el indice del id a buscar o un -1 si hay error
int controller_getIndexArcadeById(LinkedList* pArrayList, int id)
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

/// @fn int controller_getIndexById(LinkedList*, int)
/// @brief obtenemos el indice del id que tomamos
///
/// @param pArrayList
/// @param id a tener que buscar el indice
/// @return el indice del id a buscar o un -1 si hay error
int controller_getIndexJuegoById(LinkedList* pArrayList, int id)
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

//-----------------------------------------------------------------------------------------------------------

/// @fn int controller_getLastId(void)
/// @brief tomamos el valor entero del archivo donde tenemos guardado el ultimo id
///
/// @return un 0 si esta OK y un -1 si hay error
int controller_getLastId(void)
{
	int rtn = -1;
	FILE* pArchivoUltimoId;


	pArchivoUltimoId = fopen("unicoId.csv", "r");

	if (parser_LastIdFromText(pArchivoUltimoId) == 0)
	{
		rtn = 0;
	}
	else
	{
		fclose (pArchivoUltimoId);
		FILE* pArchivoSalon;
		FILE* pArchivoArcade;
		FILE* pArchivoJuego;
		pArchivoSalon = fopen("dataSalones.csv", "r");
		pArchivoArcade = fopen("dataArcades.csv", "r");
		pArchivoJuego = fopen("dataJuegos.csv", "r");

		if (parser_SalonLastIdFromText(pArchivoSalon) == 0 && parser_ArcadeLastIdFromText(pArchivoArcade) == 0 && parser_JuegoLastIdFromText(pArchivoJuego) == 0)
		{
			rtn = 0;
		}
		else
		{
			Salon_setUltimoId (1);
			Arcade_setUltimoId (1);
			Juego_setUltimoId (1);
		}
		fclose (pArchivoSalon);
		fclose (pArchivoArcade);
		fclose (pArchivoJuego);
	}
	fclose (pArchivoUltimoId);
    return rtn;
}

/// @fn int controller_setLastId()
/// @brief seteamos el ultimo id en un archivo aparte para tenerlo para si damos de alta sin cargar primero los pasajeros
///
/// @return un 0 si esta OK y un -1 si hay error
int controller_setLastId()
{
	int rtn = -1;
	int ultimoIdSalon;
	int ultimoIdArcade;
	int ultimoIdJuego;

	char ultimoIdSalonStr[8];
	char ultimoIdArcadeStr[8];
	char ultimoIdJuegoStr[8];

	FILE* pArchivo = NULL;

	pArchivo = fopen ("unicoId.csv", "w");

	if (pArchivo != NULL)
	{
		Salon_getUltimoId(&ultimoIdSalon);
		Arcade_getUltimoId(&ultimoIdArcade);
		Juego_getUltimoId(&ultimoIdJuego);

		sprintf(ultimoIdSalonStr, "%d",ultimoIdSalon-1);
		sprintf(ultimoIdArcadeStr, "%d",ultimoIdArcade-1);
		sprintf(ultimoIdJuegoStr, "%d",ultimoIdJuego-1);

		fprintf(pArchivo, "%s,%s,%s", ultimoIdSalonStr, ultimoIdArcadeStr, ultimoIdJuegoStr);
		rtn = 0;
	}
	fclose (pArchivo);
    return rtn;
}

//----------------------------------------------------------------------------------------------------------------------------------------
// INFORMES

int controller_informes (LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	char opcion;
	int respuesta;

	if (pArrayListArcade != NULL && pArrayListJuego != NULL && pArrayListSalon != NULL)
	{
		rtn = 0;
		do
		{
			menuInformes();

			utn_getNombre(&opcion, "Ingrese una opcion: ", "Ingrese una opcion valida.", 2, 20);
			opcion = toupper(opcion);

			switch (opcion)
			{
				case 'A':
					if (controller_informeA(pArrayListSalon) == 0)
					{

					}
					else
					{
						puts ("Informe A no realizado.");
					}
					break;

				case 'B':
					if (controller_informeB(pArrayListSalon, pArrayListArcade, pArrayListJuego) == 0)
					{

					}
					else
					{
						puts ("Informe B no realizado.");
					}
					break;

				case 'C':
					if (controller_informeC(pArrayListSalon) == 0)
					{

					}
					else
					{
						puts ("Informe C no realizado.");
					}
					break;

				case 'D':
					if (controller_informeD(pArrayListSalon, pArrayListArcade, pArrayListJuego) == 0)
					{

					}
					else
					{
						puts ("Informe D no realizado.");
					}
					break;

				case 'E':
					if (controller_informeE(pArrayListSalon, pArrayListArcade, pArrayListJuego) == 0)
					{

					}
					else
					{
						puts ("Informe E no realizado.");
					}
					break;

				case 'F':
					if (controller_informeF(pArrayListSalon, pArrayListArcade, pArrayListJuego) == 0)
					{

					}
					else
					{
						puts ("Informe F no realizado.");
					}
					break;

				case 'G':
					if (controller_informeG(pArrayListArcade, pArrayListJuego) == 0)
					{

					}
					else
					{
						puts ("Informe G no realizado.");
					}
					break;

				case 'H':
					respuesta = 0;
					break;
				default:
					puts ("Ingrese un caracter valido.");
			}

			if (opcion != 'H')
			{
				respuesta = validacionDosCaracteres ("¿Desea ver otro informe? (S/N)", 'S', 'N');
			}

		}
		while (respuesta);
	}

	return rtn;
}

int controller_informeA(LinkedList* pArrayListSalon)
{
	int rtn = -1;
	int i;
	int lenSalones;
	Salon* pAuxSalon;

	int cantArcades;

	if (pArrayListSalon != NULL)
	{
		lenSalones = ll_len(pArrayListSalon);
		if (lenSalones > 0 && lenSalones < MAX_SALONES)
		{
			puts("\n\t\t\t\t\t\t\t\t> LISTADO Salones\n"
				"--------------------------------------------------------------------------------------"
				"-------------------------------------------------------------------------------");
			printf("%-6s %-50s %-50s %-12s || %-12s\n", "ID", "NOMBRE", "DIRECCION", "TIPO SALON", "CANT ARCADES");
			for (i = 0; i < lenSalones; i++)
			{
				pAuxSalon = (Salon*)ll_get(pArrayListSalon, i);

				Salon_getCantidadArcades(pAuxSalon, &cantArcades);
				if (pAuxSalon != NULL && cantArcades > 4)
				{
					if (Salon_print(pAuxSalon) == 0)
					{
						printf ("%-12d", pAuxSalon-> cantidadArcades);
						printf("\n");
						rtn = 0;
					}
				}
			}
		}
	}
    return rtn;
}

int controller_informeB(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int i;
	int auxIndex;
	int lenArcade;
	Salon* pAuxSalon;
	Arcade* pAuxArcade;
	Juego* pAuxJuego;

	int idSalon;
	int idJuego;

	int idArcade;
	int cantJug;
	char nombreJuego[NOMBRE_LEN];
	int tipoGenero;
	char nombreSalon [NOMBRE_LEN];

	if (pArrayListSalon != NULL && pArrayListArcade != NULL && pArrayListJuego != NULL)
	{
		lenArcade = ll_len(pArrayListArcade);
		if (lenArcade > 0 && lenArcade < MAX_ARCADES)
		{
			puts("\n\t\t\t\t\t> ARCADE CON MAS DE 2 JUGADORES\n"
				"-----------------------------------------------------"
				"-----------------------------------------------------");
			printf("%-6s %-10s %-50s %-12s %-50s\n", "ID", "CANT JUG", "NOMBRE", "GENERO", "NOMBRE SALON");

			for (i = 0; i < lenArcade; i++)
			{
				pAuxArcade = ll_get(pArrayListArcade, i);
				Arcade_getFK_IdSalon(pAuxArcade, &idSalon);
				auxIndex = controller_getIndexSalonById(pArrayListSalon, idSalon);
				pAuxSalon = ll_get(pArrayListSalon, auxIndex);
				Arcade_getFK_IdJuego(pAuxArcade, &idJuego);
				auxIndex = controller_getIndexJuegoById(pArrayListJuego, idJuego);
				pAuxJuego = ll_get(pArrayListJuego, auxIndex);

				Arcade_getCantJugadores(pAuxArcade, &cantJug);

				if (cantJug > 2)
				{
					rtn = 0;
					Arcade_getId(pAuxArcade, &idArcade);
					Juego_getNombre(pAuxJuego, nombreJuego);
					Juego_getTipoGenero(pAuxJuego, &tipoGenero);
					Salon_getNombre(pAuxSalon, nombreSalon);

					printf ("%-6d %-10d %-50s %-12s %-51s\n",
							idArcade, cantJug, nombreJuego, JUEGOS_TIPOS[tipoGenero-1], nombreSalon);
				}
			}
		}
	}
    return rtn;
}


int controller_informeC(LinkedList* pArrayListSalon)
{
	int rtn = -1;
	int auxId;
	int busquedaId;
	Salon* pAuxSalon;

	if (pArrayListSalon != NULL && ll_len(pArrayListSalon) > 0)
	{
		utn_getIntPositivo(&auxId,"Ingrese el ID del Salon: ", "Error, ingrese un ID valido");
		busquedaId = controller_getIndexSalonById(pArrayListSalon, auxId);
		if (busquedaId != -1)
		{
			pAuxSalon = ll_get(pArrayListSalon, busquedaId);
			puts("\n\t\t\t\t\t\t> SALON\n"
				"---------------------------------------------------------------"
				"--------------------------------------------------------------");
			printf("%-6s %-50s %-50s %-12s\n", "ID", "NOMBRE", "DIRECCION", "TIPO SALON");
			Salon_print(pAuxSalon);
			printf ("\n");
			rtn = 0;
		}
		else
		{
			puts("ID de SALON no encontrado");
		}
	}
    return rtn;
}

int controller_informeD(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int lenListSalon = ll_len(pArrayListSalon);
	int i, j;
	Salon* pAuxSalon;
	Arcade* pAuxArcade;
	int cantArcades;
	int lenCloneSalones;
	int lenListaArcade = ll_len(pArrayListArcade);
	int auxId;
	int auxFKIdSalon;
	int auxIdJuego;
	int indiceJuego;
	int categoriaJuego;
	int plataforma;
	int laberinto;
	int aventura;
	int primerIngreso = 0;
	Juego* pAuxJuego;

	LinkedList* cloneSalones = ll_newLinkedList();

	if (pArrayListSalon != NULL && pArrayListArcade != NULL && pArrayListJuego != NULL && lenListSalon > 0 && lenListaArcade > 0)
	{
		for (i = 0; i < lenListSalon; i++)
		{
			pAuxSalon = ll_get(pArrayListSalon, i);
			Salon_getCantidadArcades(pAuxSalon, &cantArcades);
			if (cantArcades > 11)
			{
				ll_add(cloneSalones, pAuxSalon);
			}
		}

		lenCloneSalones = ll_len(cloneSalones);

		if (lenCloneSalones > 0)
		{
			for (i = 0; i < lenCloneSalones; i++)
			{
				pAuxSalon = ll_get(cloneSalones, i);
				Salon_getId(pAuxSalon, &auxId);
				plataforma = 0;
				laberinto = 0;
				aventura = 0;
				for (j = 0; j < lenListaArcade; j++)
				{
					pAuxArcade = ll_get(pArrayListArcade, j);
					Arcade_getFK_IdSalon(pAuxArcade, &auxFKIdSalon);

					if (auxFKIdSalon == auxId)
					{
						Arcade_getFK_IdJuego(pAuxArcade, &auxIdJuego);
						indiceJuego = controller_getIndexJuegoById(pArrayListJuego, auxIdJuego);
						pAuxJuego = ll_get(pArrayListJuego, indiceJuego);
						Juego_getTipoGenero(pAuxJuego, &categoriaJuego);

						switch (categoriaJuego)
						{
							case 1:
								plataforma++;
								break;
							case 2:
								laberinto++;
								break;
							case 3:
								aventura++;
								break;
						}
					}
				}
				if (plataforma > 3 && laberinto > 2 && aventura > 4)
				{
					if (primerIngreso == 0)
					{
						primerIngreso = 1;
						puts("\t\t\t\t\t\t> LISTADO SALONES COMPLETOS\n"
						"-------------------------------------------------------------"
						"-------------------------------------------------------------");
						printf("%-6s %-50s %-50s %-12s\n", "ID", "NOMBRE", "DIRECCION", "TIPO SALON");
					}
					Salon_print(pAuxSalon);
					puts ("");
					rtn = 0;
				}
			}
		}
	}

	if (rtn == -1)
	{
		puts("No hay Salones Completos.");
	}
	return rtn;
}

int controller_informeE(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int auxId;
	int busquedaId;
	Salon* pAuxSalon;
	Juego* pAuxJuego;
	Arcade* pAuxArcade;
	int i;
	int lenSalon = ll_len(pArrayListSalon);
	int lenArcade = ll_len(pArrayListArcade);
	int lenJuego = ll_len(pArrayListArcade);
	int FK_idSalon;
	int lenListaClonada;

	int idArcade;
	int idJuego;
	int cantJug;
	int cantFichas;
	int tipoSonido;
	char nombreJuego[NOMBRE_LEN];
	char nacionalidad[NACIONALIDAD_LEN];

	LinkedList* cloneList = ll_newLinkedList();

	if (pArrayListSalon != NULL  && pArrayListArcade != NULL && pArrayListJuego != NULL &&
		lenSalon > 0 && lenArcade > 0 && lenJuego > 0)
	{
		utn_getIntPositivo(&auxId,"Ingrese el ID del Salon: ", "Error, ingrese un ID valido");
		busquedaId = controller_getIndexSalonById(pArrayListSalon, auxId);
		if (busquedaId != -1)
		{
			pAuxSalon = ll_get(pArrayListSalon, busquedaId);
			puts ("\n--------------------------------------------------------DATOS"
				    " SALON-------------------------------------------------------||");
			printf("%-6s %-50s %-50s %-12s ||\n", "ID", "NOMBRE", "DIRECCION", "TIPO SALON");
			Salon_print(pAuxSalon);
			puts ("\n----------------------------------------------------------------"
					"----------------------------------------------------------||");
			puts ("-----------------------------------------------------ARCADES"
				" DEL SALON----------------------------------------------------||");
			pAuxSalon = ll_get(pArrayListSalon, busquedaId);
			for (i = 0; i < lenArcade; i++)
			{
				pAuxArcade = ll_get(pArrayListArcade, i);
				Arcade_getFK_IdSalon(pAuxArcade, &FK_idSalon);
				if (FK_idSalon == auxId)
				{
					ll_add(cloneList, pAuxArcade);
				}
			}
			lenListaClonada = ll_len(cloneList);
			if (lenListaClonada > 0)
			{
				printf("%-6s %-50s %-12s %-10s %-10s %-50s\n", "ID ARC", "NACIONALIDAD", "SONIDO", "CANT JUG", "CANT FICHAS", "NOMBRE JUEGO");
				for (i = 0; i < lenListaClonada; i++)
				{
					pAuxArcade = ll_get(cloneList, i);
					Arcade_getId(pAuxArcade, &idArcade);
					Arcade_getFK_IdJuego(pAuxArcade, &idJuego);
					busquedaId = controller_getIndexJuegoById(pArrayListJuego, idJuego);
					pAuxJuego = ll_get(pArrayListJuego, busquedaId);

					Arcade_getCantJugadores(pAuxArcade, &cantJug);
					Arcade_getCantidadMaxFichas(pAuxArcade, &cantFichas);
					Arcade_getTipoSonido(pAuxArcade, &tipoSonido);
					Arcade_getNacionalidad(pAuxArcade, nacionalidad);
					Juego_getNombre(pAuxJuego, nombreJuego);
					printf("%-6d %-50s %-12s %-10d %-11d %-50s\n", idArcade, nacionalidad, ARCADES_TIPOS[tipoSonido-1], cantJug, cantFichas, nombreJuego);

				}
				ll_deleteLinkedList(cloneList);
			}
			else
			{
				puts("No posee ARCADES EL SALON.");
			}
			rtn = 0;
		}
		else
		{
			puts("ID de SALON no encontrado");
		}
	}
    return rtn;
}

int controller_informeF(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int lenListSalon = ll_len(pArrayListSalon);
	int lenListArcade = ll_len(pArrayListArcade);
	int i;
	int cantArcades;
	int indiceSalonMaxArcades;
	int maxArcades;
	int FK_idSalon;
	int idsalonMax;
	Salon* pAuxSalon;
	Arcade* pAuxArcade;
	LinkedList* cloneList = ll_newLinkedList();

	if (pArrayListSalon != NULL && pArrayListArcade != NULL && pArrayListJuego != NULL && lenListSalon > 0)
	{
		for (i = 0; i < lenListSalon; i++)
		{
			pAuxSalon = ll_get(pArrayListSalon, i);
			Salon_getCantidadArcades(pAuxSalon, &cantArcades);
			if (i == 0 || cantArcades > maxArcades)
			{
				maxArcades = cantArcades;
				indiceSalonMaxArcades = i;
			}
		}
		puts("\n\t\t\t\t\t\t> SALON\n"
		"-------------------------------------------------------------"
		"-------------------------------------------------------------");
		printf("%-6s %-50s %-50s %-12s\n", "ID", "NOMBRE", "DIRECCION", "TIPO SALON");
		pAuxSalon = ll_get(pArrayListSalon, indiceSalonMaxArcades);
		Salon_getId(pAuxSalon, &idsalonMax);
		Salon_print(pAuxSalon);
		puts ("");
		puts("\n\t\t\t\t\t\t> ARCADES\n"
				"-------------------------------------------------------------"
				"-------------------------------------------------------------");
		printf("%-6s %-50s %-12s %-9s %-12s || ", "ID", "NACIONALIDAD", "TIPO SONIDO", "CANT JUG", "CANT FICHAS");
		for (i = 0; i < lenListArcade; i++)
		{
			pAuxArcade = ll_get(pArrayListArcade, i);
			Arcade_getFK_IdSalon(pAuxArcade, &FK_idSalon);
			if (FK_idSalon == idsalonMax)
			{
				ll_add(cloneList, pAuxArcade);
			}
		}
		ll_sort(cloneList, Arcade_orderByID, 1);
		for (i = 0; i < ll_len(cloneList); i++)
		{
			printf("\n");
			pAuxArcade = ll_get(cloneList, i);
			Arcade_print(pAuxArcade);

		}
		puts("");
		ll_deleteLinkedList(cloneList);
		rtn = 0;

	}

	return rtn;
}

int controller_informeG(LinkedList* pArrayListArcade, LinkedList* pArrayListJuego)
{
	int rtn = -1;
	int i;
	int auxIndex;
	int lenArcade;
	int lenJuego;
	Arcade* pAuxArcade;
	Juego* pAuxJuego;

	LinkedList* cloneListArcade = ll_newLinkedList();
	LinkedList* cloneListJuegos = ll_newLinkedList();

	int idJuego;
	int FKIdJuego;
	int idArcade;
	char nombreJuego[NOMBRE_LEN];
	int generoJuego;
	int cantJug;
	int tipoSonido;

	if (pArrayListArcade != NULL && pArrayListJuego != NULL)
	{
		cloneListJuegos = ll_clone(pArrayListJuego);
		ll_sort(cloneListJuegos, Juego_orderByName, 1);
		lenArcade = ll_len(pArrayListArcade);
		if (lenArcade > 0 && lenArcade < MAX_ARCADES)
		{
			for (i = 0; i < lenArcade; i++)
			{
				pAuxArcade = ll_get(pArrayListArcade, i);
				Arcade_getFK_IdJuego(pAuxArcade, &idJuego);
				auxIndex = controller_getIndexJuegoById(pArrayListJuego, idJuego);
				pAuxJuego = ll_get(pArrayListJuego, auxIndex);

				Arcade_getTipoSonido(pAuxArcade, &tipoSonido);
				Juego_getTipoGenero(pAuxJuego, &generoJuego);

				if (pAuxArcade != NULL && pAuxJuego != NULL && tipoSonido == 1 && generoJuego == 1)
				{
					ll_add(cloneListArcade, pAuxArcade);
				}
			}
		}

		lenArcade = ll_len(cloneListArcade);
		lenJuego = ll_len(cloneListJuegos);
		puts("\n\t\t\t> ARCADES MONO Y PLATAFORMA\n"
			"----------------------------------------"
			"----------------------------------------");
		printf("%-6s %-50s %-12s %-10s\n", "ID ARC", "NOMBRE JUEGO", "GENERO", "CANT JUG");

		for (i = 0; i < lenJuego; i++)
		{
			pAuxJuego = ll_get(cloneListJuegos, i);
			Juego_getId(pAuxJuego, &idJuego);
			for (int j = 0; j < lenArcade; j++)
			{
				pAuxArcade = ll_get(cloneListArcade, j);
				Arcade_getFK_IdJuego(pAuxArcade, &FKIdJuego);
				if (FKIdJuego == idJuego)
				{
					Arcade_getId(pAuxArcade, &idArcade);
					Juego_getNombre(pAuxJuego, nombreJuego);
					Juego_getTipoGenero(pAuxJuego, &generoJuego);
					Arcade_getCantJugadores(pAuxArcade, &cantJug);
					printf ("%-6d %-50s %-12s %-10d\n",idArcade, nombreJuego, JUEGOS_TIPOS[generoJuego-1], cantJug);
				}
			}
		}
		ll_deleteLinkedList(cloneListArcade);
		ll_deleteLinkedList(cloneListJuegos);
		rtn = 0;
	}
    return rtn;
}
