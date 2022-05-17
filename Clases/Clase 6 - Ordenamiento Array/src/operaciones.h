/*
 * operaciones.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Agostin
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include "validaciones.h"


int imprimirArrayInt (char* mensaje, int arrayNros[], int len);
int ordenarArrayIntDesc (int* arrayNros, int len);
int ordenInsercionIntAsc (int* arrayNros, int len);

int promedioArrayInt (int arrayNro[], int len, float* pPromedio);
int buscarMax(int* arrayNro, int len, int* maximo, int* cantMax);
int buscarMin(int* arrayNro, int len, int* minimo, int* cantMin);
int buscarNro(int* arrayNro, int len);

void menu (void);



#endif /* OPERACIONES_H_ */
