/*
 * Juegos.c
 *
 *  Created on: 26 jun. 2022
 *      Author: Agostin
 */


#include "Juegos.h"

static const char JUEGOS_TIPOS [4][11] = {"Plataforma", "Laberinto", "Aventura", "Otros"};

static int unicoId = 0;

/// @fn int Juego_generarIdUnico(void)
/// @brief generamos el id unico para cada Juego
///
/// @return el id unico
int Juego_generarIdUnico (void)
{
	return unicoId++;
}

/// @fn void Juego_setUltimoId(int)
/// @brief seteamos el ultimo id para arrcncar desde cierto numero
///
/// @param ultimoId
void Juego_setUltimoId (int ultimoId)
{
	unicoId = ultimoId;
}

/// @fn int Juego_getUltimoId(int*)
/// @brief tomamos el ultimo id
///
/// @param id
/// @return un 0 si esta Ok y un -1 si hay error
int Juego_getUltimoId(int* id)
{
	int rtn = -1;
	*id = unicoId;
	rtn = 0;
	return rtn;
}

/// @fn Salon Juego_new*()
/// @brief generamos el espacio en memoria de la estructura juego
///
/// @return el puntero que apunta a donde arranca la estructura juego creada
Juego* Juego_new()
{
	Juego* auxPassenger;
	auxPassenger = (Juego*) malloc (sizeof (Juego));
	return auxPassenger;
}

/// @fn Salon Juego_newParametros*(char*, char*, char*, char*)
/// @brief  tomamos los datos que queremos guardar en una estructura juego. dentro tenemos que convertir algunas cadenas en entero
///
/// @param idStr el ID en cadena
/// @param nombreStr el nombre en cadena
/// @param empresaStr la empresa del juego
/// @param tipoGeneroStr el genero del juego
/// @return el salon con todos los datos seteados.
Juego* Juego_newParametros(char* idStr,char* nombreStr, char* empresaStr, char* tipoGeneroStr)
{
	Juego* auxJuego;
	auxJuego = Juego_new();
	int id = 0;
	int tipoGenero;
	if ( auxJuego != NULL &&
		getIntFromStr(idStr, &id) == 0 &&
		Juego_tipoGeneroToInt(tipoGeneroStr, &tipoGenero) == 0)
	{
		Juego_setId(auxJuego, id);
		Juego_setNombre(auxJuego, nombreStr);
		Juego_setEmpresa(auxJuego, empresaStr);
		Juego_setTipoGenero(auxJuego, tipoGenero);
	}
	return auxJuego;
}

/// @fn void Juego_delete(Salon*)
/// @brief borramos el juego de la memoria
///
/// @param this
void Juego_delete(Juego* this)
{
	free (this);
}

/// @fn int Juego_setId(Juego*, int)
/// @brief guardamos el id del Juego que queremos
///
/// @param this Juego
/// @param id queremos guardar en el Juego
/// @return un 0 si esta Ok y un -1 si hay error
int Juego_setId(Juego* this,int id)
{
	int rtn = -1;

	if (this != NULL && id > 0)
	{
		this -> idJuego = id;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Juego_getId(Juego*, int*)
/// @brief tomamos el id del Juego
///
/// @param this Juego
/// @param id donde queremos guardar el id del Juego
/// @return un 0 si esta Ok y un -1 si hay error
int Juego_getId(Juego* this,int* id)
{
	int rtn = -1;

	if (this != NULL)
	{
		*id = this -> idJuego;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Juego_setNombre(Juego*, char*)
/// @brief guardamos el nombre del Juego que queremos
///
/// @param this Juego
/// @param nombre es el que queremos guardar en el Juego
/// @return un 0 si esta Ok y un -1 si hay error
int Juego_setNombre(Juego* this,char* nombre)
{
	int rtn = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy (this -> nombre, nombre);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Juego_getNombre(Juego*, char*)
/// @brief tomamos el nombre del Juego
///
/// @param this Juego
/// @param nombre donde queremos guardar el nombre del Juego
/// @return un 0 si esta Ok y un -1 si hay error
int Juego_getNombre(Juego* this,char* nombre)
{
	int rtn = -1;

	if (this != NULL )
	{
		strcpy (nombre, this -> nombre);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Juego_setEmpresa(Juego*, char*)
/// @brief guardamos la empresa del Juego que queremos
///
/// @param this Juego
/// @param direccion es lo que queremos guardar en el Juego
/// @return un 0 si esta Ok y un -1 si hay error
int Juego_setEmpresa(Juego* this,char* empresa)
{
	int rtn = -1;

	if (this != NULL && empresa != NULL)
	{
		strcpy (this -> empresa, empresa);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Juego_getEmpresa(Juego*, char*)
/// @brief tomamos la empresa del Juego
///
/// @param this Juego
/// @param direccion variable donde queremos guardar la empresa  del Juego
/// @return un 0 si esta Ok y un -1 si hay error
int Juego_getEmpresa(Juego* this,char* empresa)
{
	int rtn = -1;

	if (this != NULL )
	{
		strcpy (empresa, this -> empresa);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Juego_setTipoGenero(Juego*, int)
/// @brief guardamos el tipo de genero del Juego que queremos
///
/// @param this Juego
/// @param tipoSalon  es el tipo de genero que queremos guardar en el Juego
/// @return un 0 si esta Ok y un -1 si hay error
int Juego_setTipoGenero(Juego* this,int tipoGenero)
{
	int rtn = -1;

	if (this != NULL && tipoGenero > 0 && tipoGenero < 5)
	{
		this -> tipoGenero = tipoGenero;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Juego_getTipoGenero(Juego*, int*)
/// @brief tomamos el tipo de genero de juego
///
/// @param this Juego
/// @param tipoSalon  variable donde queremos guardar el tipo de genero
/// @return un 0 si esta Ok y un -1 si hay error
int Juego_getTipoGenero(Juego* this,int* tipoGenero)
{
	int rtn = -1;

	if (this != NULL)
	{
		*tipoGenero = this -> tipoGenero;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Juego_tipoGeneroToInt(char*, int*)
/// @brief convertimos una cadena del tipo de genero en un entero
///
/// @param cadena del tipo de Juego
/// @param numero donde guardamos el entero
/// @return un 0 si esta OK y un -1 si hay error
int Juego_tipoGeneroToInt (char* cadena, int* numero)
{
	int rtn = -1;
	if (cadena != NULL)
	{
		for (int i = 0; i < 4; i++)
		{
			if (strcmp(cadena, JUEGOS_TIPOS[i]) == 0)
			{
				*numero = i+1;
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

/// @fn int Juego_print(Juego*)
/// @brief impresion de un Juego
///
/// @param this el Juego a imprimir
/// @return un 0 si esta OK y un -1 si hay error
int Juego_print (Juego* this)
{
	int rtn = -1;
	Juego* auxJuego;
	auxJuego = Juego_new();

	if (this != NULL &&
			Juego_getId(this, &auxJuego->idJuego) == 0 &&
			Juego_getNombre(this, auxJuego->nombre) == 0 &&
			Juego_getEmpresa(this, auxJuego->empresa) == 0 &&
			Juego_getTipoGenero(this, &auxJuego->tipoGenero) == 0)
	{
		printf ("%-6d %-50s %-50s %-12s ||\n",
				auxJuego->idJuego, auxJuego->nombre, auxJuego->empresa, JUEGOS_TIPOS [(auxJuego->tipoGenero)-1]);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Juego_orderByName(void*, void*)
/// @brief  orden segun el nombre
///
/// @param thisOne un pasajero
/// @param thisTwo otro pasajero
/// @return un 1 si es mayor el primero, -1 si es mayor el segundo y un 0 si son iguales
int Juego_orderByName (void* thisOne, void* thisTwo)
{
	int rtn;
	int resultado;
	resultado = compararCadenas(((Juego*)thisOne) -> nombre, ((Juego*)thisTwo) -> nombre, NOMBRE_LEN);
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
