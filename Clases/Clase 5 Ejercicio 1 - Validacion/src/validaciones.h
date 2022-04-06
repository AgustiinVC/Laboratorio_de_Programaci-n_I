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

int getInt(int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int getFloat(float* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

#endif /* VALIDACIONES_H_ */
