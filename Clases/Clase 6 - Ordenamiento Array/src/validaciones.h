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
#include <ctype.h>
#include <string.h>

int validacionDosCaracteres (char* mensaje, char caracterUno, char caracterDos);
int validacionCaracter (char *mensaje, char caracter);

//Para Entero
int getInt(int* pNumeroIngresado, char* mensaje, char* mensajeError, int min, int max, int reintentos);
int getIntRange (int* pNumeroIngresado, char* mensaje, char* mensajeError, int min, int max);
int getIntPositivo (int* pNumeroIngresado, char* mensaje, char* mensajeError);
int getIntNegativo(int* pNumeroIngresado, char* mensaje, char* mensajeError);
int getIntAlone (int* pNumeroIngresado, char* mensaje, char* mensajeError);

//Para Float
int getFloat(float* pNumeroIngresado, char* mensaje, char* mensajeError, float min, float max, int reintentos);
int getFloatAlone(float* pNumeroIngresado, char* mensaje, char* mensajeError);

//Para double
int getDouble(double* pNumeroIngresado, char* mensaje, char* mensajeError, double min, double max, int reintentos);
int getDoubleAlone(double* pNumeroIngresado, char* mensaje, char* mensajeError);

void saltoDeLinea (void);
void presionarEnter (void);

#endif /* VALIDACIONES_H_ */
