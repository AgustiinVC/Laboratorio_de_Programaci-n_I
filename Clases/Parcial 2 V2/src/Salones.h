/*
 * Salones.h
 *
 *  Created on: 26 jun. 2022
 *      Author: Agostin
 */

#ifndef SALONES_H_
#define SALONES_H_

#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "LinkedList.h"

#define MAX_SALONES 100
#define NOMBRE_LEN 50
#define DIRECCION_LEN 128

#define SHOPPING 1
#define LOCAL 2

typedef struct
{
	int idSalon;
	char nombre[NOMBRE_LEN];
	char direccion[DIRECCION_LEN];
	int tipoSalon;
	int cantidadArcades;

}Salon;

int Salon_generarIdUnico (void);
void Salon_setUltimoId (int ultimoId);
int Salon_getUltimoId(int* id);

Salon* Salon_new();
Salon* Salon_newParametros(char* idStr,char* nombreStr, char* direccionStr, char* tipoSalonStr, char* cantidadArcadesStr);
void Salon_delete(Salon* this);

int Salon_setId(Salon* this,int id);
int Salon_getId(Salon* this,int* id);

int Salon_setNombre(Salon* this,char* nombre);
int Salon_getNombre(Salon* this,char* nombre);

int Salon_setDireccion(Salon* this,char* direccion);
int Salon_getDireccion(Salon* this,char* direccion);

int Salon_setTipoSalon(Salon* this,int tipoSalon);
int Salon_getTipoSalon(Salon* this,int* tipoSalon);
int Salon_tipoSalonToInt (char* cadena, int* numero);

int Salon_setCantidadArcades(Salon* this,int cantidadArcades);
int Salon_getCantidadArcades(Salon* this,int* cantidadArcades);

int Salon_print (Salon* this);

int Salon_filterLocal (void* this);
int Salon_filterShopping (void* this);

#endif /* SALONES_H_ */
