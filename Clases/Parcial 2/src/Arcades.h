/*
 * Arcades.h
 *
 *  Created on: 26 jun. 2022
 *      Author: Agostin
 */

#ifndef ARCADES_H_
#define ARCADES_H_

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "LinkedList.h"

#define MAX_ARCADES 1000
#define NACIONALIDAD_LEN 128

#define MONO 1
#define ESTEREO 2

typedef struct
{
	int idArcade;
	char nacionalidad[NACIONALIDAD_LEN];
	int tipoSonido;
	int cantidadJugadores;
	int cantidadMaxFichas;
	int FK_idSalon;
	int FK_idJuego;

}Arcade;

int Arcade_generarIdUnico (void);
void Arcade_setUltimoId (int ultimoId);
int Arcade_getUltimoId(int* id);

Arcade* Arcade_new();
Arcade* Arcade_newParametros(char* idStr,char* nacionalidadStr, char* tipoSonidoStr, char* cantidadJugadoresStr, char* cantMaxFichasStr, char* idSalonStr, char* idJuegoStr);
void Passenger_delete(Arcade* this);

int Arcade_setId(Arcade* this,int id);
int Arcade_getId(Arcade* this,int* id);

int Arcade_setNacionalidad(Arcade* this,char* nacionalidad);
int Arcade_getNacionalidad(Arcade* this,char* nacionalidad);

int Arcade_setTipoSonido(Arcade* this,int tipoSonido);
int Arcade_getTipoSonido(Arcade* this,int* tipoSonido);
int Arcade_tipoSonidoToInt (char* cadena, int* numero);

int Arcade_setCantJugadores(Arcade* this,int cantidadJugadores);
int Arcade_getCantJugadores(Arcade* this,int* cantidadJugadores);

int Arcade_setCantidadMaxFichas(Arcade* this,int cantidadMaxFichas);
int Arcade_getCantidadMaxFichas(Arcade* this,int* cantidadMaxFichas);

int Arcade_setFK_IdSalon(Arcade* this,int id);
int Arcade_getFK_IdSalon(Arcade* this,int* id);

int Arcade_setFK_IdJuego(Arcade* this,int id);
int Arcade_getFK_IdJuego(Arcade* this,int* id);

int Arcade_print (Arcade* this);

int Arcade_orderByID (void* thisOne, void* thisTwo);

/*
int passenger_orderByID (void* thisOne, void* thisTwo);
int passenger_orderByName (void* thisOne, void* thisTwo);
int passenger_orderByLastName (void* thisOne, void* thisTwo);
int passenger_orderByPrice (void* thisOne, void* thisTwo);
int passenger_orderByFlightCode (void* thisOne, void* thisTwo);
int passenger_orderByTypePassenger (void* thisOne, void* thisTwo);
int passenger_orderByStatusFlight (void* thisOne, void* thisTwo);
*/


#endif /* ARCADES_H_ */
