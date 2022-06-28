/*
 * Controller.c
 *
 *  Created on: 26 jun. 2022
 *      Author: Agostin
 */

#include "Controller.h"

static const char ARCADES_TIPOS [2][8] = {"MONO", "ESTEREO"};
static const char JUEGOS_TIPOS [4][11] = {"Plataforma", "Laberinto", "Aventura", "Otros"};

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

/// @fn int controller_informes(LinkedList*, LinkedList*, LinkedList*)
///  menu de opcion de informes
/// @param pArrayListSalon
/// @param pArrayListArcade
/// @param pArrayListJuego
/// @return
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
					if (controller_informeH(pArrayListSalon) == 0)
					{

					}
					else
					{
						puts ("Informe H no realizado.");
					}
					break;
				case 'I':
					respuesta = 0;
					break;
				default:
					puts ("Ingrese un caracter valido.");
			}

			if (opcion != 'I')
			{
				respuesta = validacionDosCaracteres ("¿Desea ver otro informe? (S/N)", 'S', 'N');
			}

		}
		while (respuesta);
	}

	return rtn;
}


/// @fn int controller_informeA(LinkedList*)
/// @brief Informe A con la lista de salones con mas de 4 arcade
/// @param pArrayListSalon lista de salones
/// @return un 0 si esta Ok y un -1 si hay error
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

/// @fn int controller_informeB(LinkedList*,LinkedList*,LinkedList*)
/// @brief Informe B con la lista de arcades con mas de 2 jugadores
/// @param pArrayListSalon lista de salones
/// @param pArrayListArcade lista de arcades
/// @param pArrayListJuego lista de juegos
/// @return un 0 si esta Ok y un -1 si hay error
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
				auxIndex = controllerSalon_getIndexSalonById(pArrayListSalon, idSalon);
				pAuxSalon = ll_get(pArrayListSalon, auxIndex);
				Arcade_getFK_IdJuego(pAuxArcade, &idJuego);
				auxIndex = controllerJuego_getIndexJuegoById(pArrayListJuego, idJuego);
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

/// @fn int controller_informeC(LinkedList*)
/// @brief Informe C con la impresion de un salon en especifico
/// @param pArrayListSalon lista de salones
/// @return un 0 si esta Ok y un -1 si hay error
int controller_informeC(LinkedList* pArrayListSalon)
{
	int rtn = -1;
	int auxId;
	int busquedaId;
	Salon* pAuxSalon;

	if (pArrayListSalon != NULL && ll_len(pArrayListSalon) > 0)
	{
		utn_getIntPositivo(&auxId,"Ingrese el ID del Salon: ", "Error, ingrese un ID valido");
		busquedaId = controllerSalon_getIndexSalonById(pArrayListSalon, auxId);
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

/// @fn int controller_informeD(LinkedList*,LinkedList*,LinkedList*)
/// @brief Informe D con la lista de salones completos con 4 Plataforma, 3 Laberinto y 5 Aventura
/// @param pArrayListSalon lista de salones
/// @param pArrayListArcade lista de arcades
/// @param pArrayListJuego lista de juegos
/// @return un 0 si esta Ok y un -1 si hay error
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
						indiceJuego = controllerJuego_getIndexJuegoById(pArrayListJuego, auxIdJuego);
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

/// @fn int controller_informeE(LinkedList*,LinkedList*,LinkedList*)
/// @brief Informe E con la lista de arcades de un salon determinado
/// @param pArrayListSalon lista de salones
/// @param pArrayListArcade lista de arcades
/// @param pArrayListJuego lista de juegos
/// @return un 0 si esta Ok y un -1 si hay error
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
		busquedaId = controllerSalon_getIndexSalonById(pArrayListSalon, auxId);
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
					busquedaId = controllerJuego_getIndexJuegoById(pArrayListJuego, idJuego);
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

/// @fn int controller_informeF(LinkedList*,LinkedList*,LinkedList*)
/// @brief Informe F informe del salon con mas arcades y cuales son ordenamos por nombre del juego ascendente
/// @param pArrayListSalon lista de salones
/// @param pArrayListArcade lista de arcades
/// @param pArrayListJuego lista de juegos
/// @return un 0 si esta Ok y un -1 si hay error
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
	int idJuego;
	int FKIdJuego;
	int lenCloneArcade;
	int lenCloneJuego;
	char auxNombreJuego[NOMBRE_LEN];
	Salon* pAuxSalon;
	Arcade* pAuxArcade;
	Juego* pAuxJuego;
	LinkedList* cloneListJuegos = ll_newLinkedList();
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
		printf ("-------------------------------------------"
				"Este salon posee %d ARCADES"
				"----------------------------------------------------", pAuxSalon->cantidadArcades);
		puts("\n\t\t\t\t\t\t> ARCADES\n"
				"-------------------------------------------------------------"
				"-------------------------------------------------------------");
		printf("%-6s %-50s %-12s %-9s %-12s || %-50s", "ID", "NACIONALIDAD", "TIPO SONIDO", "CANT JUG", "CANT FICHAS", "NOMBRE JUEGO");
		for (i = 0; i < lenListArcade; i++)
		{
			pAuxArcade = ll_get(pArrayListArcade, i);
			Arcade_getFK_IdSalon(pAuxArcade, &FK_idSalon);
			if (FK_idSalon == idsalonMax)
			{
				ll_add(cloneList, pAuxArcade);
			}
		}
		cloneListJuegos = ll_clone(pArrayListJuego);
		ll_sort(cloneListJuegos, Juego_orderByName, 1);
		lenCloneArcade = ll_len(cloneList);
		lenCloneJuego = ll_len(cloneListJuegos);
		for (i = 0; i < lenCloneJuego; i++)
		{
			pAuxJuego = ll_get(cloneListJuegos, i);
			Juego_getId(pAuxJuego, &idJuego);
			for (int j = 0; j < lenCloneArcade; j++)
			{
				pAuxArcade = ll_get(cloneList, j);
				Arcade_getFK_IdJuego(pAuxArcade, &FKIdJuego);
				if (FKIdJuego == idJuego)
				{
					puts("");
					Arcade_print(pAuxArcade);
					Juego_getNombre(pAuxJuego, auxNombreJuego);
					printf ("%-50s", auxNombreJuego);
				}
			}
		}
		/*ll_sort(cloneList, Arcade_orderByID, 1);
		for (i = 0; i < ll_len(cloneList); i++)
		{
			printf("\n");
			pAuxArcade = ll_get(cloneList, i);
			Arcade_print(pAuxArcade);

		}*/
		puts("");
		ll_deleteLinkedList(cloneList);
		ll_deleteLinkedList(cloneListJuegos);
		rtn = 0;

	}

	return rtn;
}

/// @fn int controller_informeG(LinkedList*,LinkedList*,LinkedList*)
/// @brief Informe G Arcades con sonido MONO y juego de Plataforma
/// @param pArrayListSalon lista de salones
/// @param pArrayListArcade lista de arcades
/// @param pArrayListJuego lista de juegos
/// @return un 0 si esta Ok y un -1 si hay error
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
				auxIndex = controllerJuego_getIndexJuegoById(pArrayListJuego, idJuego);
				pAuxJuego = ll_get(pArrayListJuego, auxIndex);

				Arcade_getTipoSonido(pAuxArcade, &tipoSonido);
				Juego_getTipoGenero(pAuxJuego, &generoJuego);

				if (pAuxArcade != NULL && pAuxJuego != NULL && tipoSonido == MONO && generoJuego == PLATAFORMA)
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

/// @fn int controller_informeA(LinkedList*)
/// @brief Informe A con la lista de salones con mas de 4 arcade
/// @param pArrayListSalon lista de salones
/// @return un 0 si esta Ok y un -1 si hay error
int controller_informeH(LinkedList* pArrayListSalon)
{
	int rtn = -1;
	int i;
	int lenSalones;
	int opcion;
	Salon* pAuxSalon;
	LinkedList* filterSalones;
	if (pArrayListSalon != NULL)
	{
		utn_getIntRange (&opcion ,"\nIngrese cual tipo de salon quiere filtrar:\n "
												"1 - LOCAL\n "
												"2 - SHOPPING\n "
												"Ingrese su opcion: ",
												"Error. Ingrese una opcion correcta\n\n", 1, 2);
		lenSalones = ll_len(pArrayListSalon);
		filterSalones = ll_newLinkedList();
		if (lenSalones > 0 && lenSalones < MAX_SALONES)
		{
			puts("\n\t\t\t\t\t> LISTADO Salones Filtrados\n"
				"--------------------------------------------------------------"
				"--------------------------------------------------------------");
			printf("%-6s %-50s %-50s %-12s ||\n", "ID", "NOMBRE", "DIRECCION", "TIPO SALON");
			if (opcion == 1)
			{
				filterSalones = ll_filter(pArrayListSalon, Salon_filterLocal);
			}
			else
			{
				filterSalones = ll_filter(pArrayListSalon, Salon_filterShopping);
			}

			lenSalones = ll_len(filterSalones);
			for (i = 0; i < lenSalones; i++)
			{
				pAuxSalon = (Salon*)ll_get(filterSalones, i);
				if (Salon_print(pAuxSalon) == 0)
				{
					printf("\n");
					rtn = 0;
				}
			}
		}
	}
    return rtn;
}
