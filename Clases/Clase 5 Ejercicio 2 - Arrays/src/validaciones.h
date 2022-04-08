/*
 * validaciones.h
 *
 *  Created on: 5 abr. 2022
 *      Author: Agostin
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

#include <stdio.h>
#include <stdlib.h>

/// @fn int getInt(int*, char*, char*, int, int, int)
/// @param pNumeroIngresado puntero del numero que se ingresa
/// @param mensaje	mensaje que se muestra para ver lo que se pide
/// @param mensajeError	mje de error en caso de ingresar algo mal
/// @param minimo	numero minimo a ingresar
/// @param maximo	numero maximo a ingresar
/// @param reintentos	cantidad de reintentos
/// @return	devuelve un 1 si esta todo bien y un 0 si esta mal el ingreso del numero,
int getInt(int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

//Lo mismo que el anterior pero con float
int getFloat(float* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/// @fn void saltoDeLinea(void)
/// Esta funcion solo hace un salto de linea para emprolijar
void saltoDeLinea (void);

#endif /* VALIDACIONES_H_ */
