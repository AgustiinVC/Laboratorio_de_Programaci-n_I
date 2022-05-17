/*
 * Producto_Usuario_Tracking.h
 *
 *  Created on: 15 may. 2022
 *      Author: Agostin
 */

#ifndef PRODUCTO_USUARIO_TRACKING_H_
#define PRODUCTO_USUARIO_TRACKING_H_

#include "Tracking.h"
#include "Usuario.h"
#include "Producto.h"

#define CANT_SEG_X_10KM 20

int union_usuario (Usuario* usu_list, int usu_len, Producto* pro_list, int pro_len, Tracking* tra_list, int tra_len, int userId);
int union_admin (Usuario* usu_list, int usu_len, Producto* pro_list, int pro_len, Tracking* tra_list, int tra_len, int userId);

int pro_altaArray(Usuario* usu_list, int usu_len, Producto* pro_list , int pro_len, int userId);
int comprarProducto (Usuario* usu_list, int usu_len, Producto* pro_list, int pro_len, Tracking* tra_list, int tra_len, int userId);
int tra_alta (Tracking* tra_list, int tra_len, Producto* auxProd, int cantidad, Usuario* auxUsuario, float totalCompra);

int union_estadoCompras (Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId);
int union_imprimir(Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId);
int union_imprimirENVIAJE(Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId);
void union_printOne (Tracking* list, Producto* auxProducto);

int union_estadoVentas (Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId);
int tra_imprimirVentas(Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId);


#endif /* PRODUCTO_USUARIO_TRACKING_H_ */
