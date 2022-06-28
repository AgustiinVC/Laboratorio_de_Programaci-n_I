#include "parser.h"

/** \brief Parsea los datos los datos de los Salones desde el archivo dataSalones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSalones LinkedList*
 * \return int
 *
 */
int parser_SalonesFromText(FILE* pFile , LinkedList* pArrayListSalones)
{
	int r;
	int rtn = -1;
	int auxId;
	int ultimoId = 0;
	int cantidadSalones = 0;
	char bufferId[10];
	char bufferNombre[NOMBRE_LEN];
	char bufferDireccion[DIRECCION_LEN];
	char bufferTipoSalon [12];
	char bufferCantidadArcades [10];
	Salon* PauxSalon = NULL;

	if (pFile != NULL && pArrayListSalones != NULL)
	{
		fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferDireccion, bufferTipoSalon, bufferCantidadArcades);

		do
		{
			r = fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferDireccion, bufferTipoSalon, bufferCantidadArcades);
			if (r == 5)
			{
				PauxSalon = Salon_newParametros(bufferId, bufferNombre, bufferDireccion, bufferTipoSalon, bufferCantidadArcades);
			}

			if (PauxSalon != NULL && ll_add(pArrayListSalones, PauxSalon) == 0 )
			{
				Salon_getId(PauxSalon, &auxId);
				if (cantidadSalones == 0 || (auxId > ultimoId && ll_len(pArrayListSalones) < MAX_SALONES))
				{
					Salon_getId(PauxSalon, &ultimoId);
				}
				cantidadSalones++;
			}
		}
		while (feof(pFile) == 0);
		rtn = 0;
		printf ("Se ingresaron: %d salones y su ultimo id es: %d\n", cantidadSalones, ultimoId);
	}
	return rtn;
}


/// @fn int parser_SalonLastIdFromText(FILE*)
/// @brief parseamos el archivo de salones donde tomamos solo el ultimo id para poder tener como referencia
/// parsea el ultimo id que obtenemos del archivo csv
/// @param pFile puntero al archivo donde tenemos los salones y vamos a recorrer viendo el id mas alto
/// @return un 0 si esta Ok y un -1 si hay error
int parser_SalonLastIdFromText(FILE* pFile)
{
	int r;
	int rtn = -1;
	int auxId;
	int ultimoId = 0;
	int cantidadSalones = 0;
	char bufferId[10];
	char bufferNombre[NOMBRE_LEN];
	char bufferDireccion[DIRECCION_LEN];
	char bufferTipoSalon [12];
	char bufferCantidadArcades [10];
	Salon* PauxSalon = NULL;

	if (pFile != NULL)
	{
		fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferDireccion, bufferTipoSalon, bufferCantidadArcades);

		do
		{
			r = fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferDireccion, bufferTipoSalon, bufferCantidadArcades);
			if (r == 5)
			{
				PauxSalon = Salon_newParametros(bufferId, bufferNombre, bufferDireccion, bufferTipoSalon, bufferCantidadArcades);
			}

			if (PauxSalon != NULL)
			{
				Salon_getId(PauxSalon, &auxId);
				if (cantidadSalones == 0 || (auxId > ultimoId) )
				{
					Salon_getId(PauxSalon, &ultimoId);
				}
				cantidadSalones++;
			}
		}
		while (feof(pFile) == 0);
		ultimoId += 1;
		Salon_setUltimoId (ultimoId);
		rtn = 0;
	}
	return rtn;
}

//-------------------------------------------------------------------------------------------------------

/** \brief Parsea los datos los datos de los arcade desde el archivo dataArcades.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListArcades LinkedList*
 * \return int
 */
int parser_ArcadesFromText(FILE* pFile , LinkedList* pArrayListArcades)
{
	int r;
	int rtn = -1;
	int auxId;
	int ultimoId = 0;
	int cantidadArcades = 0;
	char bufferId[10];
	char bufferNacionalida[NACIONALIDAD_LEN];
	char bufferTipoSonido [10];
	char bufferCantidadJugadores [10];
	char bufferCantidadFichas [10];
	char bufferIdSalon [10];
	char bufferIdJuego [10];
	Arcade* PauxArcades = NULL;

	if (pFile != NULL && pArrayListArcades != NULL)
	{
		fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNacionalida, bufferTipoSonido, bufferCantidadJugadores, bufferCantidadFichas, bufferIdSalon, bufferIdJuego);

		do
		{
			r = fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNacionalida, bufferTipoSonido, bufferCantidadJugadores, bufferCantidadFichas, bufferIdSalon, bufferIdJuego);

			if (r == 7)
			{
				PauxArcades = Arcade_newParametros(bufferId, bufferNacionalida, bufferTipoSonido, bufferCantidadJugadores, bufferCantidadFichas, bufferIdSalon, bufferIdJuego);
			}

			if (PauxArcades != NULL && ll_add(pArrayListArcades, PauxArcades) == 0 )
			{
				Arcade_getId(PauxArcades, &auxId);
				if (cantidadArcades == 0 || (auxId > ultimoId && ll_len(pArrayListArcades) < MAX_ARCADES))
				{
					Arcade_getId(PauxArcades, &ultimoId);
				}
				cantidadArcades++;
			}
		}
		while (feof(pFile) == 0);
		rtn = 0;
		printf ("Se ingresaron: %d arcades y su ultimo id es: %d\n", cantidadArcades, ultimoId);
	}
	return rtn;
}


/// @fn int parser_ArcadeLastIdFromText(FILE*)
/// @brief parseamos el archivo de arcade donde tomamos solo el ultimo id para poder tener como referencia
/// parsea el ultimo id que obtenemos del archivo csv
/// @param pFile puntero al archivo donde tenemos los salones y vamos a recorrer viendo el id mas alto
/// @return un 0 si esta Ok y un -1 si hay error
int parser_ArcadeLastIdFromText(FILE* pFile)
{
	int r;
	int rtn = -1;
	int auxId;
	int ultimoId = 0;
	int cantidadArcades = 0;
	char bufferId[10];
	char bufferNacionalida[NACIONALIDAD_LEN];
	char bufferTipoSonido [10];
	char bufferCantidadJugadores [10];
	char bufferCantidadFichas [10];
	char bufferIdSalon [10];
	char bufferIdJuego [10];
	Arcade* PauxArcades = NULL;

	if (pFile != NULL)
	{
		fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNacionalida, bufferTipoSonido, bufferCantidadJugadores, bufferCantidadFichas, bufferIdSalon, bufferIdJuego);

		do
		{
			r = fscanf (pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNacionalida, bufferTipoSonido, bufferCantidadJugadores, bufferCantidadFichas, bufferIdSalon, bufferIdJuego);

			if (r == 7)
			{
				PauxArcades = Arcade_newParametros(bufferId, bufferNacionalida, bufferTipoSonido, bufferCantidadJugadores, bufferCantidadFichas, bufferIdSalon, bufferIdJuego);
			}

			if (PauxArcades != NULL)
			{
				Arcade_getId(PauxArcades, &auxId);
				if (cantidadArcades == 0 || (auxId > ultimoId) )
				{
					Arcade_getId(PauxArcades, &ultimoId);
				}
				cantidadArcades++;
			}
		}
		while (feof(pFile) == 0);
		ultimoId += 1;
		Arcade_setUltimoId (ultimoId);
		rtn = 0;
	}
	return rtn;
}

//--------------------------------------------------------------------------------------------------------
/*
 * int idJuego;
	char nombre[NOMBRE_LEN];
	char empresa[EMPRESA_LEN];
	int tipoGenero;
 */
/** \brief Parsea los datos los datos de los juegos desde el archivo dataJuegos.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJuegos LinkedList*
 * \return int
 *
 */
int parser_JuegoFromText(FILE* pFile , LinkedList* pArrayListJuegos)
{
	int r;
	int rtn = -1;
	int auxId;
	int ultimoId = 0;
	int cantidadJuegos = 0;
	char bufferId[10];
	char bufferNombre[NOMBRE_LEN];
	char bufferEmpresa[EMPRESA_LEN];
	char bufferTipoGenero [12];
	Juego* PauxJuego = NULL;

	if (pFile != NULL && pArrayListJuegos != NULL)
	{
		fscanf (pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEmpresa, bufferTipoGenero);

		do
		{
			r = fscanf (pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEmpresa, bufferTipoGenero);
			if (r == 4)
			{
				PauxJuego = Juego_newParametros(bufferId, bufferNombre, bufferEmpresa, bufferTipoGenero);
			}

			if (PauxJuego != NULL && ll_add(pArrayListJuegos, PauxJuego) == 0 )
			{
				Juego_getId(PauxJuego, &auxId);
				if (cantidadJuegos == 0 || (auxId > ultimoId && ll_len(pArrayListJuegos) < MAX_JUEGOS))
				{
					Juego_getId(PauxJuego, &ultimoId);

				}
				cantidadJuegos++;
			}
		}
		while (feof(pFile) == 0);
		rtn = 0;
		printf ("Se ingresaron: %d juegos y su ultimo id es: %d\n", cantidadJuegos, ultimoId);
	}
	return rtn;
}


/// @fn int parser_JuegoLastIdFromText(FILE*)
/// @brief parseamos el archivo de juegos donde tomamos solo el ultimo id para poder tener como referencia
/// parsea el ultimo id que obtenemos del archivo csv
/// @param pFile puntero al archivo donde tenemos los juegos y vamos a recorrer viendo el id mas alto
/// @return un 0 si esta Ok y un -1 si hay error
int parser_JuegoLastIdFromText(FILE* pFile)
{
	int r;
	int rtn = -1;
	int auxId;
	int ultimoId = 0;
	int cantidadJuegos = 0;
	char bufferId[10];
	char bufferNombre[NOMBRE_LEN];
	char bufferEmpresa[EMPRESA_LEN];
	char bufferTipoGenero [12];
	Juego* PauxJuego = NULL;

	if (pFile != NULL)
	{
		fscanf (pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEmpresa, bufferTipoGenero);

		do
		{
			r = fscanf (pFile, "%[^,],%[^,],%[^,],%[^\n]\n", bufferId, bufferNombre, bufferEmpresa, bufferTipoGenero);
			if (r == 4)
			{
				PauxJuego = Juego_newParametros(bufferId, bufferNombre, bufferEmpresa, bufferTipoGenero);
			}

			if (PauxJuego != NULL)
			{
				Juego_getId(PauxJuego, &auxId);
				if (cantidadJuegos == 0 || (auxId > ultimoId))
				{
					Juego_getId(PauxJuego, &ultimoId);
				}
				cantidadJuegos++;
			}
		}
		while (feof(pFile) == 0);
		ultimoId += 1;
		Juego_setUltimoId (ultimoId);
		rtn = 0;
	}
	return rtn;
}

//--------------------------------------------------------------------------------------------------------
/// @fn int parser_LastIdFromText(FILE*)
/// @brief
/// parsea el entero del archivo donde guardamos el ultimo id
/// @param pFile puntero al archivo donde tenemos guardado el ultimo id
/// @return un 0 si esta Ok y un -1 si hay error
int parser_LastIdFromText(FILE* pFile)
{
	int rtn = -1;

	char ultimoIdSalonStr[8];
	char ultimoIdArcadeStr[8];
	char ultimoIdJuegoStr[8];

	int ultimoIdSalon;
	int ultimoIdArcade;
	int ultimoIdJuego;

	if (pFile != NULL)
	{
		do
		{

			if (fscanf (pFile, "%[^,],%[^,],%[^\n]", ultimoIdSalonStr, ultimoIdArcadeStr, ultimoIdJuegoStr) == 3)
			{
				getIntFromStr(ultimoIdSalonStr, &ultimoIdSalon);
				getIntFromStr(ultimoIdArcadeStr, &ultimoIdArcade);
				getIntFromStr(ultimoIdJuegoStr, &ultimoIdJuego);

				ultimoIdSalon++;
				ultimoIdArcade++;
				ultimoIdJuego++;

				Salon_setUltimoId (ultimoIdSalon);
				Arcade_setUltimoId (ultimoIdArcade);
				Juego_setUltimoId (ultimoIdJuego);
			}
		}
		while (feof(pFile) == 0);
		rtn = 0;
	}
	return rtn;
}
