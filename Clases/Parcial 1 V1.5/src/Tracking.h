/*
 * Tracking.h
 *
 *  Created on: 14 may. 2022
 *      Author: Agostin
 */

#ifndef TRACKING_H_
#define TRACKING_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//ESTADOS DE UN TRACKING
#define TRA_LIBRE 0
#define TRA_EN_VIAJE 1
#define TRA_ENTREGADO 2
#define TRA_CANCELADO 3
#define TRA_BAJA -1

#define NOMBRE_LEN 25

//ESTRUCTURA DE TRACKING
struct
{
	int idTracking;
	int idProducto;
	short int isEmpty;

	int FK_idComprador;
	int FK_idVendedor;

	float costo;
	int cantidad;
	int distanciaKM;
	long int horaLlegada; //20" x 10KM

}typedef Tracking;

long int time_Current (void);
long int time_Add (double secondsAdd);

int tra_initArray(Tracking* list, int len);
int tra_indexEmpty (Tracking* list, int len);
int calculoKM (int codPostal);
int actualizarEstado (Tracking* list, int len, int userId);
int tra_findById(Tracking* list, int len,int id);

int tra_imprimir(Tracking* list, int length);
void tra_printOne (Tracking* list);


#endif /* TRACKING_H_ */
