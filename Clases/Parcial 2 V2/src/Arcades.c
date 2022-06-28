/*
 * Arcades.c
 *
 *  Created on: 26 jun. 2022
 *      Author: Agostin
 */

#include "Arcades.h"

static const char ARCADES_TIPOS [2][8] = {"MONO", "ESTEREO"};

static int unicoId = 0;

/// @fn int Arcade_generarIdUnico(void)
/// @brief generamos el id unico para cada Arcade
///
/// @return el id unico
int Arcade_generarIdUnico (void)
{
	return unicoId++;
}

/// @fn void Arcade_setUltimoId(int)
/// @brief seteamos el ultimo id para arrancar desde cierto numero
///
/// @param ultimoId
void Arcade_setUltimoId (int ultimoId)
{
	unicoId = ultimoId;
}

/// @fn int Arcade_getUltimoId(int*)
/// @brief tomamos el ultimo id
///
/// @param id
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_getUltimoId(int* id)
{
	int rtn = -1;
	*id = unicoId;
	rtn = 0;
	return rtn;
}

/// @fn Arcade Arcade_new*()
/// @brief generamos el espacio en memoria de la estructura Arcade
///
/// @return el puntero que apunta a donde arranca la estructura Arcade creada
Arcade* Arcade_new()
{
	Arcade* auxArcade;
	auxArcade = (Arcade*) malloc (sizeof (Arcade));
	return auxArcade;
}

/// @fn Arcade Arcade_newParametros*(char*, char*, char*, char*)
/// @brief  tomamos los datos que queremos guardar en una estructura Arcade. dentro tenemos que convertir algunas cadenas en entero
///
/// @param idStr el ID en cadena
/// @param nacionalidadStr nacionalidad del arcade
/// @param tipoSonidoStr tipo de sonido del arcade
/// @param cantidadJugadoresStr cantidad max de jugadores
/// @param cantMaxFichasStr cantidad max de fichas
/// @param idSalonStr id del salon
/// @param idJuegoStr id del juego a usar
/// @return el Arcade con todos los datos seteados.
Arcade* Arcade_newParametros(char* idStr,char* nacionalidadStr, char* tipoSonidoStr, char* cantidadJugadoresStr, char* cantMaxFichasStr, char* idSalonStr, char* idJuegoStr)
{
	Arcade* auxArcade;
	auxArcade = Arcade_new();
	int id = 0;
	int tipoSonido;
	int cantidadJugadores;
	int cantFichaMax;
	int idSalon;
	int idJuego;

	if ( auxArcade != NULL &&
		getIntFromStr(idStr, &id) == 0 &&
		Arcade_tipoSonidoToInt(tipoSonidoStr, &tipoSonido) == 0 &&
		getIntFromStr(cantidadJugadoresStr, &cantidadJugadores) == 0 &&
		getIntFromStr(cantMaxFichasStr, &cantFichaMax) == 0 &&
		getIntFromStr(idSalonStr, &idSalon) == 0 &&
		getIntFromStr(idJuegoStr, &idJuego) == 0)
	{
		Arcade_setId(auxArcade, id);
		Arcade_setNacionalidad(auxArcade, nacionalidadStr);
		Arcade_setTipoSonido(auxArcade, tipoSonido);
		Arcade_setCantJugadores(auxArcade, cantidadJugadores);
		Arcade_setCantidadMaxFichas(auxArcade, cantFichaMax);
		Arcade_setFK_IdSalon(auxArcade, idSalon);
		Arcade_setFK_IdJuego(auxArcade, idJuego);
	}
	return auxArcade;
}

/// @fn void Arcade_delete(Arcade*)
/// @brief borramos el Arcade de la memoria
///
/// @param this
void Arcade_delete(Arcade* this)
{
	free (this);
}

/// @fn int Arcade_setId(Arcade*, int)
/// @brief guardamos el id del Arcade que queremos
///
/// @param this Arcade
/// @param id queremos guardar en el Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_setId(Arcade* this,int id)
{
	int rtn = -1;

	if (this != NULL && id > 0)
	{
		this -> idArcade = id;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_getId(Arcade*, int*)
/// @brief tomamos el id del Arcade
///
/// @param this Arcade
/// @param id donde queremos guardar el id del Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_getId(Arcade* this,int* id)
{
	int rtn = -1;

	if (this != NULL)
	{
		*id = this -> idArcade;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_setNacionalidad(Arcade*, char*)
/// @brief guardamos la nacionalidad del Arcade que queremos
///
/// @param this Arcade
/// @param nacionalidad es el que queremos guardar en el Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_setNacionalidad(Arcade* this,char* nacionalidad)
{
	int rtn = -1;

	if (this != NULL && nacionalidad != NULL)
	{
		strcpy (this -> nacionalidad, nacionalidad);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_getNacionalidad(Arcade*, char*)
/// @brief tomamos la nacionalidad del Arcade
///
/// @param this Arcade
/// @param nacionalidad donde queremos guardar la nacionalidad del Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_getNacionalidad(Arcade* this,char* nacionalidad)
{
	int rtn = -1;

	if (this != NULL )
	{
		strcpy (nacionalidad, this -> nacionalidad);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_setTipoSonido(Arcade*, int)
/// @brief guardamos el tipo de sonido del Arcade
///
/// @param this Arcade
/// @param tipoSonido  es el tipo de Salon que queremos guardar en el Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_setTipoSonido(Arcade* this,int tipoSonido)
{
	int rtn = -1;

	if (this != NULL && tipoSonido > 0 && tipoSonido < 3)
	{
		this -> tipoSonido = tipoSonido;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_getTipoSonido(Arcade*, int*)
/// @brief tomamos el tipo de sonido del Arcade
///
/// @param this Arcade
/// @param tipoSonido  variable donde queremos guardar el tipo de Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido)
{
	int rtn = -1;

	if (this != NULL)
	{
		*tipoSonido = this -> tipoSonido;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_tipoSonidoToInt(char*, int*)
/// @brief convertimos una cadena del tipo de sonido del arcade en un entero
///
/// @param cadena del tipo de sonido del arcade
/// @param numero donde guardamos el entero
/// @return un 0 si esta OK y un -1 si hay error
int Arcade_tipoSonidoToInt (char* cadena, int* numero)
{
	int rtn = -1;
	if (cadena != NULL)
	{
		for (int i = 0; i < 3; i++)
		{
			if (strcmp(cadena, ARCADES_TIPOS[i]) == 0)
			{
				*numero = i+1;
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

/// @fn int Arcade_setCantJugadores(Arcade*, int)
/// @brief guardamos el cantidad de jugadores del Arcade que queremos
///
/// @param this Arcade
/// @param cantidadJugadores queremos guardar en el Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_setCantJugadores(Arcade* this,int cantidadJugadores)
{
	int rtn = -1;

	if (this != NULL && cantidadJugadores > 0)
	{
		this -> cantidadJugadores = cantidadJugadores;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_getCantJugadores(Arcade*, int*)
/// @brief tomamos el la cantidad de jugadores del Arcade
///
/// @param this Arcade
/// @param cantidadJugadores donde queremos guardar el id del Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_getCantJugadores(Arcade* this,int* cantidadJugadores)
{
	int rtn = -1;

	if (this != NULL)
	{
		*cantidadJugadores = this -> cantidadJugadores;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_setCantidadMaxFichas(Arcade*, int)
/// @brief guardamos la cantidad maxima de fichas del arcade
///
/// @param this Arcade
/// @param id queremos guardar en el Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_setCantidadMaxFichas(Arcade* this,int cantidadMaxFichas)
{
	int rtn = -1;

	if (this != NULL && cantidadMaxFichas > 0)
	{
		this -> cantidadMaxFichas = cantidadMaxFichas;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_getCantidadMaxFichas(Arcade*, int*)
/// @brief tomamos la cantidad maxima de fichas del arcade
///
/// @param this Arcade
/// @param id donde queremos guardar el id del Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_getCantidadMaxFichas(Arcade* this,int* cantidadMaxFichas)
{
	int rtn = -1;

	if (this != NULL)
	{
		*cantidadMaxFichas = this -> cantidadMaxFichas;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_setFK_IdSalon(Arcade*, int)
/// @brief guardamos el id del salon donde ponemos el arcade
///
/// @param this Arcade
/// @param id queremos guardar en el Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_setFK_IdSalon(Arcade* this,int id)
{
	int rtn = -1;

	if (this != NULL && id > 0)
	{
		this -> FK_idSalon = id;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_getFK_IdSalon(Arcade*, int*)
/// @brief tomamos el id del salon donde esta el arcade
///
/// @param this Arcade
/// @param id donde queremos guardar el id del Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_getFK_IdSalon(Arcade* this,int* id)
{
	int rtn = -1;

	if (this != NULL)
	{
		*id = this -> FK_idSalon;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_setFK_IdJuego(Salon*, int)
/// @brief guardamos el id del juego que usaremos en el arcade
///
/// @param this Arcade
/// @param id queremos guardar en el Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_setFK_IdJuego(Arcade* this,int id)
{
	int rtn = -1;

	if (this != NULL && id > 0)
	{
		this -> FK_idJuego = id;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Arcade_getFK_IdJuego(Arcade*, int*)
/// @brief tomamos el id del juego en el arcade
///
/// @param this Arcade
/// @param id donde queremos guardar el id del Arcade
/// @return un 0 si esta Ok y un -1 si hay error
int Arcade_getFK_IdJuego(Arcade* this,int* id)
{
	int rtn = -1;

	if (this != NULL)
	{
		*id = this -> FK_idJuego;
		rtn = 0;
	}
	return rtn;
}
/*
 * int idArcade;
	char nacionalidad[NACIONALIDAD_LEN];
	int tipoSonido;
	int cantidadJugadores;
	int cantidadMaxFichas;
	int FK_idSalon;
	int FK_idJuego;
 */

/// @fn int Arcade_print(Arcade*)
/// @brief impresion de un Salon
///
/// @param this el Salon a imprimir
/// @return un 0 si esta OK y un -1 si hay error
int Arcade_print (Arcade* this)
{
	int rtn = -1;
	Arcade* auxArcade;
	auxArcade = Arcade_new();
	if (this != NULL &&
		Arcade_getId(this, &auxArcade->idArcade) == 0 &&
		Arcade_getNacionalidad(this, auxArcade->nacionalidad) == 0 &&
		Arcade_getTipoSonido(this, &auxArcade->tipoSonido) == 0 &&
		Arcade_getCantJugadores(this, &auxArcade->cantidadJugadores) == 0 &&
		Arcade_getCantidadMaxFichas(this, &auxArcade->cantidadMaxFichas) == 0 &&
		Arcade_getFK_IdSalon(this, &auxArcade->FK_idSalon) == 0 &&
		Arcade_getFK_IdJuego(this, &auxArcade->FK_idJuego) == 0)
	{
		printf ("%-6d %-50s %-12s %-9d %-12d || ",
				auxArcade->idArcade, auxArcade->nacionalidad, ARCADES_TIPOS[(auxArcade->tipoSonido)-1],
				auxArcade->cantidadJugadores, auxArcade->cantidadMaxFichas);
		rtn = 0;
	}
	return rtn;
}


/// @fn int Arcade_orderByID(void*, void*)
/// @brief  orden segun el ID
///
/// @param thisOne un Arcade
/// @param thisTwo otro Arcade
/// @return un 1 si es mayor el primero, -1 si es mayor el segundo y un 0 si son iguales
int Arcade_orderByID (void* thisOne, void* thisTwo)
{
	int rtn;
	if ( ((Arcade*)thisOne) -> idArcade > ((Arcade*)thisTwo) -> idArcade )
	{
		rtn = 1;
	}
	else if ( ((Arcade*)thisOne) -> idArcade < ((Arcade*)thisTwo) -> idArcade )
	{
		rtn = -1;
	}
	else
	{
		rtn = 0;
	}
	return rtn;
}

/*
/// @fn int passenger_orderByID(void*, void*)
/// @brief  orden segun el ID
///
/// @param thisOne un pasajero
/// @param thisTwo otro pasajero
/// @return un 1 si es mayor el primero, -1 si es mayor el segundo y un 0 si son iguales
int passenger_orderByID (void* thisOne, void* thisTwo)
{
	int rtn;
	if ( ((Passenger*)thisOne) -> id > ((Passenger*)thisTwo) -> id )
	{
		rtn = 1;
	}
	else if ( ((Passenger*)thisOne) -> id < ((Passenger*)thisTwo) -> id )
	{
		rtn = -1;
	}
	else
	{
		rtn = 0;
	}
	return rtn;
}

/// @fn int passenger_orderByName(void*, void*)
/// @brief  orden segun el nombre
///
/// @param thisOne un pasajero
/// @param thisTwo otro pasajero
/// @return un 1 si es mayor el primero, -1 si es mayor el segundo y un 0 si son iguales
int passenger_orderByName (void* thisOne, void* thisTwo)
{
	int rtn;
	int resultado;
	resultado = compararCadenas(((Passenger*)thisOne) -> nombre, ((Passenger*)thisTwo) -> nombre, NOMBRE_LEN);
	switch (resultado)
	{
		case 1:
			rtn = 1;
			break;
		case 2:
			rtn = -1;
			break;
		case 0:
			rtn = 0;
			break;
	}
	return rtn;
}

/// @fn int passenger_orderByLastName(void*, void*)
/// @brief  orden segun el apellido
///
/// @param thisOne un pasajero
/// @param thisTwo otro pasajero
/// @return un 1 si es mayor el primero, -1 si es mayor el segundo y un 0 si son iguales
int passenger_orderByLastName (void* thisOne, void* thisTwo)
{
	int rtn;
	int resultado;
	resultado = compararCadenas(((Passenger*)thisOne) -> apellido, ((Passenger*)thisTwo) -> apellido, APELLIDO_LEN);
	switch (resultado)
	{
		case 1:
			rtn = 1;
			break;
		case 2:
			rtn = -1;
			break;
		case 0:
			rtn = 0;
			break;
	}
	return rtn;
}

/// @fn int passenger_orderByPrice(void*, void*)
/// @brief  orden segun el precio
///
/// @param thisOne un pasajero
/// @param thisTwo otro pasajero
/// @return un 1 si es mayor el primero, -1 si es mayor el segundo y un 0 si son iguales
int passenger_orderByPrice (void* thisOne, void* thisTwo)
{
	int rtn;
	if ( ((Passenger*)thisOne) -> precio > ((Passenger*)thisTwo) -> precio )
	{
		rtn = 1;
	}
	else if ( ((Passenger*)thisOne) -> precio < ((Passenger*)thisTwo) -> precio )
	{
		rtn = -1;
	}
	else
	{
		rtn = 0;
	}
	return rtn;
}

/// @fn int passenger_orderByFlightCode(void*, void*)
/// @brief  orden segun el codigo del vuelo
///
/// @param thisOne un pasajero
/// @param thisTwo otro pasajero
/// @return un 1 si es mayor el primero, -1 si es mayor el segundo y un 0 si son iguales
int passenger_orderByFlightCode (void* thisOne, void* thisTwo)
{
	int rtn;
	int resultado;
	resultado = compararCadenas(((Passenger*)thisOne) -> codigoVuelo, ((Passenger*)thisTwo) -> codigoVuelo, APELLIDO_LEN);
	switch (resultado)
	{
		case 1:
			rtn = 1;
			break;
		case 2:
			rtn = -1;
			break;
		case 0:
			rtn = 0;
			break;
	}
	return rtn;
}

/// @fn int passenger_orderByTypePassenger(void*, void*)
/// @brief  orden segun el tipo de pasajero
///
/// @param thisOne un pasajero
/// @param thisTwo otro pasajero
/// @return un 1 si es mayor el primero, -1 si es mayor el segundo y un 0 si son iguales
int passenger_orderByTypePassenger (void* thisOne, void* thisTwo)
{
	int rtn;
	if ( ((Passenger*)thisOne) -> tipoPasajero > ((Passenger*)thisTwo) -> tipoPasajero )
	{
		rtn = 1;
	}
	else if ( ((Passenger*)thisOne) -> tipoPasajero < ((Passenger*)thisTwo) -> tipoPasajero )
	{
		rtn = -1;
	}
	else
	{
		rtn = 0;
	}
	return rtn;
}

/// @fn int passenger_orderByStatusFlight(void*, void*)
/// @brief  orden segun el estado del vuelo
///
/// @param thisOne un pasajero
/// @param thisTwo otro pasajero
/// @return un 1 si es mayor el primero, -1 si es mayor el segundo y un 0 si son iguales
int passenger_orderByStatusFlight (void* thisOne, void* thisTwo)
{
	int rtn;
	if ( ((Passenger*)thisOne) -> estadoVUelo > ((Passenger*)thisTwo) -> estadoVUelo )
	{
		rtn = 1;
	}
	else if ( ((Passenger*)thisOne) -> estadoVUelo < ((Passenger*)thisTwo) -> estadoVUelo )
	{
		rtn = -1;
	}
	else
	{
		rtn = 0;
	}
	return rtn;
}

*/
