/*
 * operaciones.h
 *
 *  Created on: 7 abr. 2022
 *      Author: Agostin
 */

#ifndef OPERACIONES_H_
#define OPERACIONES_H_

#include "validaciones.h"


void imprimirArray (int arrayNros[], int len);

void promedioArrayInt (int arrayNro[], int len, float* pPromedio);
void buscarMax(int* array, int len, int* maximo, int* cantMax);
void buscarMin(int* array, int len, int* minimo, int* cantMin);
void buscarNro(int* array, int len);

void menu (void);



#endif /* OPERACIONES_H_ */
