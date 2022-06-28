/*
 * Juegos.h
 *
 *  Created on: 26 jun. 2022
 *      Author: Agostin
 */

#ifndef JUEGOS_H_
#define JUEGOS_H_

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "LinkedList.h"

#define MAX_JUEGOS 200
#define NOMBRE_LEN 50
#define EMPRESA_LEN 50

#define PLATAFORMA 1
#define LABERINTO 2
#define AVENTURA 3
#define OTROS 4

typedef struct
{
	int idJuego;
	char nombre[NOMBRE_LEN];
	char empresa[EMPRESA_LEN];
	int tipoGenero;

}Juego;

int Juego_generarIdUnico (void);
void Juego_setUltimoId (int ultimoId);
int Juego_getUltimoId(int* id);

Juego* Juego_new();
Juego* Juego_newParametros(char* idStr,char* nombreStr, char* empresaStr, char* tipoGeneroStr);
void Juego_delete(Juego* this);

int Juego_setId(Juego* this,int id);
int Juego_getId(Juego* this,int* id);

int Juego_setNombre(Juego* this,char* nombre);
int Juego_getNombre(Juego* this,char* nombre);

int Juego_setEmpresa(Juego* this,char* empresa);
int Juego_getEmpresa(Juego* this,char* empresa);

int Juego_setTipoGenero(Juego* this,int tipoGenero);
int Juego_getTipoGenero(Juego* this,int* tipoGenero);
int Juego_tipoGeneroToInt (char* cadena, int* numero);

int Juego_print (Juego* this);

int Juego_orderByName (void* thisOne, void* thisTwo);
/*
int passenger_orderByID (void* thisOne, void* thisTwo);
int passenger_orderByName (void* thisOne, void* thisTwo);
int passenger_orderByLastName (void* thisOne, void* thisTwo);
int passenger_orderByPrice (void* thisOne, void* thisTwo);
int passenger_orderByFlightCode (void* thisOne, void* thisTwo);
int passenger_orderByTypePassenger (void* thisOne, void* thisTwo);
int passenger_orderByStatusFlight (void* thisOne, void* thisTwo);
*/


#endif /* JUEGOS_H_ */
