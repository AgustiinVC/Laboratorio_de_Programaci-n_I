/*
 ============================================================================
 Name        : Parcial.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Parcial 1
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "validaciones.h"
#include "Producto_Usuario_Tracking.h"

#define CANT_USUARIOS 10
#define CANT_PRODUCTOS 2000
#define CANT_TRACKING 2000

int main(void) {
	setbuf (stdout,NULL);
	int opcionIngreso;
	int usuarioID;

	//ARRAY DE ESTRUCTURAS USUARIO, PRODUCTO Y TRACKING
	Usuario miUsuario [CANT_USUARIOS];
	Producto miProducto [CANT_PRODUCTOS];
	Tracking miTracking [CANT_TRACKING];

	//INICIALIZAR ARRAY DE ESTRUCTURAS USUARIO, PRODUCTO Y TRACKING
	usu_initArray (miUsuario, CANT_USUARIOS);
	pro_initArray (miProducto, CANT_PRODUCTOS);
	tra_initArray (miTracking, CANT_TRACKING);

	//ALTA FORZADA USUARIOS Y ADMIN
	usu_altaForzadaArray(miUsuario, CANT_USUARIOS, "agustin@gmail.com", "admin123", "2 de mayo 2515", 1824, 1);
	usu_altaForzadaArray(miUsuario, CANT_USUARIOS, "usuario@gmail.com", "abc123", "Calle Falsa 123", 1969, 0);
	usu_altaForzadaArray(miUsuario, CANT_USUARIOS, "usuario2@gmail.com", "abc123", "Calle Falsa 421", 1898, 0);

	pro_altaForzadaArray(miProducto , CANT_PRODUCTOS, 1, "Celular" , 120000, 4, 4);
	pro_altaForzadaArray(miProducto , CANT_PRODUCTOS, 2, "Lavaropas" , 230000, 1, 3);
	pro_altaForzadaArray(miProducto , CANT_PRODUCTOS, 1, "Remera" , 600, 14, 1);
	pro_altaForzadaArray(miProducto , CANT_PRODUCTOS, 2, "RemerA" , 1500, 3, 1);
	pro_altaForzadaArray(miProducto , CANT_PRODUCTOS, 1, "Escoba" , 120, 45, 2);


	do
	{
		menuIngreso();
		utn_getIntRange (&opcionIngreso ,"\nIngrese una Opcion: ", "Error. Ingrese una opcion correcta.\n",0,2);
		fflush (stdin);
		switch (opcionIngreso)
		{
			case 1: //Ingreso
				usuarioID = buscarUsuario(miUsuario, CANT_USUARIOS);
				if (usuarioID != -1 && miUsuario[usuarioID].isAdmin == 0)
				{
					// USUARIO INGRESADO
					union_usuario (miUsuario, CANT_USUARIOS, miProducto, CANT_PRODUCTOS, miTracking, CANT_TRACKING, usuarioID);
				}
				else if (usuarioID != -1 && miUsuario[usuarioID].isAdmin == 1)
				{
					//ADMIN INGRESADO
					union_admin(miUsuario, CANT_USUARIOS, miProducto, CANT_PRODUCTOS, miTracking, CANT_TRACKING, usuarioID);
				}
				else
				{
					puts ("Datos ingresados incorrectos.\n");
				}
				break;

			case 2: //ALTA USUARIO
				usu_altaArray(miUsuario, CANT_USUARIOS);
				break;
		}
	}
	while (opcionIngreso != 0);

	puts ("Salida");
	return EXIT_SUCCESS;
}
