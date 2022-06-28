/*
 * Salones.c
 *
 *  Created on: 26 jun. 2022
 *      Author: Agostin
 */
#include "Salones.h"

static const char SALONES_TIPOS [2][9] = {"Shopping", "Local"};

static int unicoId = 0;

/// @fn int Salon_generarIdUnico(void)
/// @brief generamos el id unico para cada salon
///
/// @return el id unico
int Salon_generarIdUnico (void)
{
	return unicoId++;
}

/// @fn void Salon_setUltimoId(int)
/// @brief seteamos el ultimo id para arrcncar desde cierto numero
///
/// @param ultimoId
void Salon_setUltimoId (int ultimoId)
{
	unicoId = ultimoId;
}

/// @fn int Salon_getUltimoId(int*)
/// @brief tomamos el ultimo id
///
/// @param id
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_getUltimoId(int* id)
{
	int rtn = -1;
	*id = unicoId;
	rtn = 0;
	return rtn;
}

/// @fn Salon Salon_new*()
/// @brief generamos el espacio en memoria de la estructura salon
///
/// @return el puntero que apunta a donde arranca la estructura salon creada
Salon* Salon_new()
{
	Salon* auxSalon;
	auxSalon = (Salon*) malloc (sizeof (Salon));
	return auxSalon;
}

/// @fn Salon Salon_newParametros*(char*, char*, char*, char*, char*s)
/// @brief  tomamos los datos que queremos guardar en una estructura salon. dentro tenemos que convertir algunas cadenas en entero
///
/// @param idStr el ID en cadena
/// @param nombreStr el nombre en cadena
/// @param direccionStr la direccion del pasajero
/// @param tipoSalonStr el tipo de salon en formato cadena
/// @return el salon con todos los datos seteados.
Salon* Salon_newParametros(char* idStr,char* nombreStr, char* direccionStr, char* tipoSalonStr, char* cantidadArcadesStr)
{
	Salon* auxSalon;
	auxSalon = Salon_new();
	int id = 0;
	int tipoSalon;
	int cantidadArcades;
	if ( auxSalon != NULL &&
		getIntFromStr(idStr, &id) == 0 &&
		getIntFromStr(cantidadArcadesStr, &cantidadArcades) == 0 &&
		Salon_tipoSalonToInt(tipoSalonStr, &tipoSalon) == 0)
	{
		Salon_setId(auxSalon, id);
		Salon_setNombre(auxSalon, nombreStr);
		Salon_setDireccion(auxSalon, direccionStr);
		Salon_setTipoSalon(auxSalon, tipoSalon);
		Salon_setCantidadArcades(auxSalon, cantidadArcades);
	}
	return auxSalon;
}

/// @fn void Salon_delete(Salon*)
/// @brief borramos el salon de la memoria
///
/// @param this
void Salon_delete(Salon* this)
{
	free (this);
}

/// @fn int Salon_setId(Salon*, int)
/// @brief guardamos el id del salon que queremos
///
/// @param this salon
/// @param id queremos guardar en el salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_setId(Salon* this,int id)
{
	int rtn = -1;

	if (this != NULL && id > 0)
	{
		this -> idSalon = id;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Salon_getId(Salon*, int*)
/// @brief tomamos el id del Salon
///
/// @param this Salon
/// @param id donde queremos guardar el id del Salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_getId(Salon* this,int* id)
{
	int rtn = -1;

	if (this != NULL)
	{
		*id = this -> idSalon;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Salon_setNombre(Salon*, char*)
/// @brief guardamos el nombre del Salon que queremos
///
/// @param this Salon
/// @param nombre es el que queremos guardar en el Salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_setNombre(Salon* this,char* nombre)
{
	int rtn = -1;

	if (this != NULL && nombre != NULL)
	{
		strcpy (this -> nombre, nombre);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Salon_getNombre(Salon*, char*)
/// @brief tomamos el nombre del salon
///
/// @param this Salon
/// @param nombre donde queremos guardar el nombre del Salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_getNombre(Salon* this,char* nombre)
{
	int rtn = -1;

	if (this != NULL )
	{
		strcpy (nombre, this -> nombre);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Salon_setDireccion(Salon*, char*)
/// @brief guardamos la direccion del Salon que queremos
///
/// @param this Salon
/// @param direccion es lo que queremos guardar en el Salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_setDireccion(Salon* this,char* direccion)
{
	int rtn = -1;

	if (this != NULL && direccion != NULL)
	{
		strcpy (this -> direccion, direccion);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Salon_getDireccion(Salon*, char*)
/// @brief tomamos la direccion del Salon
///
/// @param this Salon
/// @param direccion variable donde queremos guardar la direccion  del Salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_getDireccion(Salon* this,char* direccion)
{
	int rtn = -1;

	if (this != NULL )
	{
		strcpy (direccion, this -> direccion);
		rtn = 0;
	}
	return rtn;
}

/// @fn int Salon_setTipoSalon(Salon*, int)
/// @brief guardamos el tipo de Salon del Salon que queremos
///
/// @param this Salon
/// @param tipoSalon  es el tipo de Salon que queremos guardar en el Salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_setTipoSalon(Salon* this,int tipoSalon)
{
	int rtn = -1;

	if (this != NULL && tipoSalon > 0 && tipoSalon < 3)
	{
		this -> tipoSalon = tipoSalon;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Salon_getTipoSalon(Salon*, int*)
/// @brief tomamos el tipo de Salon
///
/// @param this Salon
/// @param tipoSalon  variable donde queremos guardar el tipo de Salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_getTipoSalon(Salon* this,int* tipoSalon)
{
	int rtn = -1;

	if (this != NULL)
	{
		*tipoSalon = this -> tipoSalon;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Salon_tipoSalonToInt(char*, int*)
/// @brief convertimos una cadena del tipo de Salon en un entero
///
/// @param cadena del tipo de Salon
/// @param numero donde guardamos el entero
/// @return un 0 si esta OK y un -1 si hay error
int Salon_tipoSalonToInt (char* cadena, int* numero)
{
	int rtn = -1;
	if (cadena != NULL)
	{
		for (int i = 0; i < 3; i++)
		{
			if (strcmp(cadena, SALONES_TIPOS[i]) == 0)
			{
				*numero = i+1;
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

/// @fn int Salon_setCantidadArcades(Salon*, int)
/// @brief guardamos la cantidad de Arcades del salon que queremos
///
/// @param this salon
/// @param cantidadArcades queremos guardar en el salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_setCantidadArcades(Salon* this,int cantidadArcades)
{
	int rtn = -1;

	if (this != NULL && cantidadArcades >= 0)
	{
		this -> cantidadArcades = cantidadArcades;
		rtn = 0;
	}
	return rtn;
}

/// @fn int Salon_getId(Salon*, int*)
/// @brief tomamos la cantidad de Arcades del salon que queremos
///
/// @param this Salon
/// @param cantidadArcades donde queremos guardar el id del Salon
/// @return un 0 si esta Ok y un -1 si hay error
int Salon_getCantidadArcades(Salon* this,int* cantidadArcades)
{
	int rtn = -1;

	if (this != NULL)
	{
		*cantidadArcades = this -> cantidadArcades;
		rtn = 0;
	}
	return rtn;
}



/// @fn int Salon_print(Salon*)
/// @brief impresion de un Salon
///
/// @param this el Salon a imprimir
/// @return un 0 si esta OK y un -1 si hay error
int Salon_print (Salon* this)
{
	int rtn = -1;
	Salon* auxSalon;
	auxSalon = Salon_new();

	if (this != NULL &&
		Salon_getId(this, &auxSalon->idSalon) == 0 &&
		Salon_getNombre(this, auxSalon->nombre) == 0 &&
		Salon_getDireccion(this, auxSalon->direccion) == 0 &&
		Salon_getTipoSalon(this, &auxSalon->tipoSalon) == 0)
	{
		printf ("%-6d %-50s %-50s %-12s || ",
				auxSalon->idSalon, auxSalon->nombre, auxSalon->direccion, SALONES_TIPOS [(auxSalon->tipoSalon)-1]);
		rtn = 0;
	}
	return rtn;
}

int Salon_filterLocal (void* this)
{
	int rtn = -1;
	if ( ((Salon*)this) -> tipoSalon == LOCAL)
	{
		rtn = 0;
	}
	return rtn;
}

int Salon_filterShopping (void* this)
{
	int rtn = -1;
	if ( ((Salon*)this) -> tipoSalon == SHOPPING)
	{
		rtn = 0;
	}
	return rtn;
}
