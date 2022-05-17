/*
 * Producto.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Agostin
 */

#ifndef PANTALLA_H_
#define PANTALLA_H_

#include <stdio.h>
#include <stdlib.h>
#define LIBRE 0
#define OCUPADO 1
#define BAJA 2

#define LCD 1
#define LED 2


#define NOMBRE_LEN 50
#define DESC_LEN 50

typedef struct
{
	char nombre [NOMBRE_LEN];
	char direccion [DESC_LEN];
	float precio;
	int tipoDePantalla;
	int isEmpty;
	int id;
}Pantalla;

int pant_initArray (Pantalla* list , int len);
int pant_indexEmpty (Pantalla* list , int len);
int pant_altaArray(Pantalla* list , int len);
int pant_modificarEstructura (Pantalla* list, int len);
Pantalla pant_ModificarUno(Pantalla list);
int pant_buscarporID (Pantalla* list, int len, int id);
int pant_Baja(Pantalla* list, int len);
int pant_imprimirEstructura (Pantalla* list, int len);
int pant_imprimirUnElemento (Pantalla* list);
int pant_altaForzadaArray(Pantalla* list , int len, char* nombre, char* direccion, float precio, int tipoDePantalla);


void menu (void);

#endif /* PANTALLA_H_ */
