/*
 * Cliente.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Agostin
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHARS 30

//ESTRUCTURA
typedef struct {
	int legajo;
	char nombre[MAX_CHARS];
	int dni;
	float sueldo;
}Cliente;


void imprimirUnEmpleado (Cliente arrayCliente[]);

#endif /* CLIENTE_H_ */
