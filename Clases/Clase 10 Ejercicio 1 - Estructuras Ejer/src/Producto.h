/*
 * Producto.h
 *
 *  Created on: 26 abr. 2022
 *      Author: Agostin
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <stdio.h>
#include <stdlib.h>
#define LIBRE 0
#define OCUPADO 1
#define BAJA 2

#define NOMBRE_LEN 50
#define DESC_LEN 50

typedef struct
{
	char nombre [NOMBRE_LEN];
	char descripcion [DESC_LEN];
	float precio;
	int isEmpty;
	int id;
}Producto;

int prod_imprimirEstructura (Producto miProducto[], int tam);
int prod_imprimirUnProducto (Producto arrayProducto[], int i);

int prod_initArray (Producto miProducto[], int tam);

int prod_cargarProducto (Producto miProducto[], int indice);
int prod_indexEmpty (Producto miProducto[], int len);
int prod_buscarporID (Producto miProducto[], int len, int identificador);
int prod_bajaProductoIndice (Producto miProducto[], int len, int indice);
int prod_bajaProductoID (Producto miProducto[], int len, int identificador);

void menu (void);

#endif /* PRODUCTO_H_ */
