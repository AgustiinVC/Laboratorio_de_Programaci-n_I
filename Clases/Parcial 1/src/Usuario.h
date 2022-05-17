/*
 * Usuario.h
 *
 *  Created on: 14 may. 2022
 *      Author: Agostin
 */

#ifndef USUARIO_H_
#define USUARIO_H_

#include <stdio.h>
#include <stdlib.h>

//ESTADO DE UN USUARIO
#define USU_LIBRE 0
#define USU_OCUPADO 1
#define USU_BAJA 2
#define USU_BAJA_PERMANENTE 3

#define CORREO_LEN 25
#define TEXT_LEN 50
#define PASSWORD 10

//Estructura de Usuario
struct
{
	int idUsuario;
	short int isEmpty;
	char correo [CORREO_LEN];
	char password [PASSWORD];
	char direccion [TEXT_LEN];
	int codPostal;
	int isAdmin;
}typedef Usuario;

int usu_initArray(Usuario* list, int len);
int usu_indexEmpty (Usuario* list, int len);
int cargaDatosUsuario (Usuario* auxList);
int usu_altaArray(Usuario* list , int len);
int buscarUsuario(Usuario* list , int len);
int buscarUsuarioPorCorreo(Usuario* list , int len, char* correo);
int usu_altaForzadaArray(Usuario* list , int len, char* correo, char* password, char* direccion ,int codPostal, int isAdmin);
int usu_findById(Usuario* list, int len,int id);

int usu_remover(Usuario* list, int len, int id);
int usu_Baja (Usuario* list, int len);

int usu_imprimir(Usuario* list, int length);
void usu_printOne (Usuario* list);
int usu_imprimirEstado(Usuario* list, int length);
void usu_printOneEstado (Usuario* list);
int usu_modificarDatos (Usuario* list, int len, int userId);
#endif /* USUARIO_H_ */
