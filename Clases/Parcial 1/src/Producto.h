/*
 * Producto.h
 *
 *  Created on: 14 may. 2022
 *      Author: Agostin
 */

#ifndef PRODUCTO_H_
#define PRODUCTO_H_

#include <stdio.h>
#include <stdlib.h>

//ESTADOS DE UN PRODUCTO
#define PRO_LIBRE 0
#define PRO_OCUPADO 1
#define PRO_SIN_STOCK 2
#define PRO_BAJA -1

#define NOMBRE_LEN 25
#define CODIGO 10

//ESTRUCTURA DE UN PRODUCTO
struct
{
	int idProducto;
	short int isEmpty;
	int FK_idVendedor;
	char nombreProducto [NOMBRE_LEN];
	float precio;
	int stock;
	int categoria;
}typedef Producto;

int pro_initArray(Producto* list, int len);
int pro_indexEmpty (Producto* list, int len);
int cargaDatosProducto (Producto* auxList);
int pro_imprimir(Producto* list, int length);
void pro_printOne (Producto* list);
int pro_imprimirMismoVendedor(Producto* list, int length, int userId);
int pro_sortsByCategory(Producto* list, int len);
int pro_sortsByCategoryName(Producto* list, int len);
int pro_findById(Producto* list, int len,int id);

int pro_remover(Producto* list, int len, int id);
int pro_Baja (Producto* list, int len);

#endif /* PRODUCTO_H_ */
