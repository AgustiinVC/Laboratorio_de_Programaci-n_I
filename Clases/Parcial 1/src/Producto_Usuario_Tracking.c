/*
 * Producto_Usuario_Tracking.c
 *
 *  Created on: 15 may. 2022
 *      Author: Agostin
 */


#include "Producto_Usuario_Tracking.h"
#include "validaciones.h"

//ESTADO DE LOS PRODUCTOS
static const char ESTADO_PRODUCTO [3][10] = {"EN VIAJE", "ENTREGADO", "CANCELADO"};

/// Inicio de variable ID Tracking
static int Tracking_idUnico = 1;

/// @fn int eTra_ObtenerID (void)
/// @brief
///  Generador de ID de cada Tracking. Suma 1 a la variable
/// @return devuelve el id de cada Tracking
static int eTra_ObtenerID (void)
{
	return Tracking_idUnico++;
}


/// @fn int union_usuario(Usuario*, int, Producto*, int, Tracking*, int, int)
/// @brief luego del login estamos en el menu usuario con todas las opciones de compra, venta y sus estados.
/// @param usu_list es el array de estructuras de Usuario
/// @param usu_len es la cantidad maxima de Usuarios
/// @param pro_list es el array de estructuras de Productos
/// @param pro_len es la cantidad maxima de Productos
/// @param tra_list es el array de estructuras de Tracking
/// @param tra_len es la cantidad maxima de Tracking
/// @param userId es el id del user que se logueo
/// @return devuelve un 0 si esta OK o un -1 si hay error
int union_usuario (Usuario* usu_list, int usu_len, Producto* pro_list, int pro_len, Tracking* tra_list, int tra_len, int userId)
{
	int rtn = -1;
	int opcion;
	if (usu_list != NULL && usu_len > 0 && pro_list != NULL && pro_len > 0 && tra_list != NULL && tra_len > 0)
	{
		 do
		{
			//Menu del usuario
			menuUsuario();

			utn_getIntRange (&opcion ,"\nIngrese una Opcion: ", "Error. Ingrese una opcion correcta.\n",0,5);
			fflush (stdin);
			switch (opcion)
			{
				case 1: //Comprar
					if (comprarProducto (usu_list, usu_len, pro_list , pro_len, tra_list, tra_len, userId) == 0)
					{
						puts("Compra realizada :)");
					}
					else
					{
						puts ("No se pudo realizar la compra");
					}
					break;

				case 2: //Vender es un alta de producto

					if(pro_altaArray(usu_list, usu_len, pro_list , pro_len, userId) == 0)
					{
						puts("Alta de producto realizada.");
					}
					else
					{
						puts ("Error en el alta del producto.");
					}
					break;

				case 3: // Estado de Compras
					if (union_estadoCompras (tra_list, tra_len, pro_list, pro_len , userId) == 0)
					{
						puts("Estado de Compras realizado.");
					}
					else
					{
						puts ("No hay Compras para mostrar.");
					}
					break;

				case 4: // Estado de Ventas
					if ( union_estadoVentas (tra_list, tra_len, pro_list, pro_len , userId) == 0)
					{
						puts("Estado de Ventas realizado.");
					}
					else
					{
						puts ("No hay Ventas para mostrar.");
					}
					break;
				case 5: // Modificar Datos usuario
					if ( usu_modificarDatos (usu_list, usu_len, userId) == 0)
					{
						if (usu_list[userId].isEmpty == USU_BAJA)
						{
							opcion = 0;
						}
					}
					else
					{
						puts ("No se pudo modificar los datos");
					}
					break;
			}
		}
		while (opcion != 0);
		rtn = 0;
	}
	return rtn;
}

/// @fn int union_admin(Usuario*, int, Producto*, int, Tracking*, int, int)
/// @brief luego del login estamos en el menu admin con todas las opciones
/// @param usu_list es el array de estructuras de Usuario
/// @param usu_len es la cantidad maxima de Usuarios
/// @param pro_list es el array de estructuras de Productos
/// @param pro_len es la cantidad maxima de Productos
/// @param tra_list es el array de estructuras de Tracking
/// @param tra_len es la cantidad maxima de Tracking
/// @param userId es el id del user que se logueo
/// @return devuelve un 0 si esta OK o un -1 si hay error
int union_admin(Usuario* usu_list, int usu_len, Producto* pro_list, int pro_len, Tracking* tra_list, int tra_len, int userId)
{
	int rtn = -1;
	int opcion;
	if (usu_list != NULL && usu_len > 0 &&
		pro_list != NULL && pro_len > 0 &&
		tra_list != NULL && tra_len > 0)
	{
		do
		{
			menuAdmin();
			opcion = opcionCaracter("\nIngrese una Opcion: ");
			fflush (stdin);
			switch (opcion)
			{
				case 1: //Listado Usuarios Estado
					if (usu_imprimirEstado(usu_list, usu_len) == 0)
					{
						puts ("Listado Finalizado");
					}
					else
					{
						puts ("No se pudo mostrar el listado.");
					}
					break;

				case 2: // Ordenar por categoria y nombre
					if (pro_sortsByCategoryName(pro_list, pro_len) == 0 && pro_imprimir (pro_list, pro_len) == 0)
					{
						puts ("Listado Productos ordenados");
					}
					else
					{
						puts ("No se pudo mostrar el listado.");
					}
					break;
				case 3: //Baja Producto
					if (pro_Baja (pro_list, pro_len) == 0)
					{
						puts ("Producto dado de baja");
					}
					else
					{
						puts ("No se dio de baja a ningun producto.");
					}

					break;

				case 4: //Baja Usuario
					if (usu_Baja (usu_list, usu_len) == 0)
					{
						puts ("Usuario dado de baja");
					}
					else
					{
						puts ("No se dio de baja a ningun usuario.");
					}
					break;
				case 5: //Tracking Global

					if (actualizarEstado (tra_list, tra_len, userId) == 0 && tra_imprimir(tra_list, tra_len) == 0)
					{
						puts ("Lista de tracking global mostrada.");
					}
					else
					{
						puts ("No se pudo mostrar el listado.");
					}
					break;
			}
		}
		while (opcion != 0);
		rtn = 0;
	}
	return rtn;
}

/// @fn int pro_altaArray(Usuario*, int, Producto*, int, int)
/// @brief alta de producto
/// @param usu_list es el array de estructuras de Usuario
/// @param usu_len es la cantidad maxima de Usuarios
/// @param pro_list es el array de estructuras de Productos
/// @param pro_len es la cantidad maxima de Productos
/// @param userId es el id del user que se logueo
/// @return devuelve un 0 si esta OK o un -1 si hay error
int pro_altaArray(Usuario* usu_list, int usu_len, Producto* pro_list , int pro_len, int userId)
{
	int rtn = -1;
	int indiceLibreProducto;
	Producto auxiliarEstructura;

	indiceLibreProducto = pro_indexEmpty (pro_list, pro_len);

	if (pro_list != NULL && pro_len > 0 &&
		usu_list != NULL && usu_len > 0 &&
		indiceLibreProducto != -1)
	{
		if (cargaDatosProducto(&auxiliarEstructura) == 0)
		{
			pro_list[indiceLibreProducto] = auxiliarEstructura;
			pro_list[indiceLibreProducto].FK_idVendedor = userId;
			rtn = 0;
		}
	}
	return rtn;
}

/// @fn int comprarProducto(Usuario*, int, Producto*, int, Tracking*, int, int)
/// @brief funcion para comprar un producto
/// @param usu_list es el array de estructuras de Usuario
/// @param usu_len es la cantidad maxima de Usuarios
/// @param pro_list es el array de estructuras de Productos
/// @param pro_len es la cantidad maxima de Productos
/// @param tra_list es el array de estructuras de Tracking
/// @param tra_len es la cantidad maxima de Tracking
/// @param userId es el id del user que se logueo
/// @return devuelve un 0 si esta OK o un -1 si hay error
int comprarProducto (Usuario* usu_list, int usu_len, Producto* pro_list, int pro_len, Tracking* tra_list, int tra_len, int userId)
{
	int rtn = -1;
	int flagAlta;
	int idIngresado;
	int indiceUsuario;
	int indPro;
	int cantidad;
	float totalCompra;

	if (usu_list != NULL && usu_len > 0 &&
		pro_list != NULL && pro_len > 0 &&
		tra_list != NULL && tra_len > 0)
	{
		if (pro_sortsByCategory(pro_list,pro_len) == 0 && pro_imprimir (pro_list,pro_len) == 0)
		{
			flagAlta = 1;
		}

		if (flagAlta == 1)
		{
			if( utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un ID correcto.\n") == 0)
			{
				indPro = pro_findById(pro_list,pro_len, idIngresado);
				while (pro_list[indPro].isEmpty != PRO_OCUPADO)
				{
					puts("NO EXISTE ID.");
					utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un ID correcto.\n\n");
					indPro = pro_findById(pro_list,pro_len, idIngresado);
				}

				if (utn_getIntRange(&cantidad, "Indique la cantidad a comprar: ", "Error. Ingrese una cantidad valida\n", 1, pro_list[indPro].stock) == 0)
				{
					totalCompra = pro_list[indPro].precio * cantidad;
					printf ("El total de su compra sera de: $%.3f\n", totalCompra);
					if (validacionDosCaracteres ("¿Esta seguro de querer realizar la compra? (S/N) : ", 'S', 'N') == 1)
					{
						pro_list[indPro].stock -= cantidad;
						if (pro_list[indPro].stock == 0)
						{
							pro_list[indPro].isEmpty = PRO_SIN_STOCK;
						}
						printf ("--Compra Realizada--\n"
								"El total de su compra es de: $%.3f\n", totalCompra);
						indiceUsuario = usu_findById (usu_list, usu_len, userId);
						//ALTA TRACKING
						if (tra_alta (tra_list, tra_len, &pro_list[indPro], cantidad, &usu_list[indiceUsuario], totalCompra) == 0)
						{
							rtn = 0;
						}
					}
				}
			}
		}
	}
	return rtn;
}

//long int horaLlegada; //20seg cada 10KM

/// @fn int tra_alta(Tracking*, int, Producto*, int, Usuario*, float)
/// @brief alta de tracking
/// @param tra_list es el array de estructuras de Tracking
/// @param tra_len es la cantidad maxima de Tracking
/// @param pro_list es el array de estructuras de Productos
/// @param pro_len es la cantidad maxima de Productos
/// @param usu_list es el array de estructuras de Usuario
/// @param usu_len es la cantidad maxima de Usuarios
/// @param totalCompra es el id del user que se logueo
/// @return devuelve un 0 si esta OK o un -1 si hay error
int tra_alta (Tracking* tra_list, int tra_len, Producto* auxProd, int cantidad, Usuario* auxUsuario, float totalCompra)
{
	int rtn = -1;
	int indiceLibre;
	int segundosTotal;
	segundosTotal = calculoKM (auxUsuario->codPostal) * (CANT_SEG_X_10KM/10);

	if (tra_list != NULL && tra_len > 0 && auxProd != NULL && cantidad > 0)
	{
		rtn = 0;
		indiceLibre = tra_indexEmpty (tra_list, tra_len);
		tra_list[indiceLibre].idProducto = auxProd->idProducto;
		tra_list[indiceLibre].cantidad = cantidad;
		tra_list[indiceLibre].idTracking = eTra_ObtenerID();
		tra_list[indiceLibre].FK_idComprador = auxUsuario->idUsuario;
		tra_list[indiceLibre].FK_idVendedor = auxProd->FK_idVendedor;
		tra_list[indiceLibre].isEmpty = TRA_EN_VIAJE;
		tra_list[indiceLibre].horaLlegada = time_Add (segundosTotal);
		tra_list[indiceLibre].costo = totalCompra;

	}
	return rtn;
}

/// @fn int union_estadoCompras(Tracking*, int, Producto*, int, int)
/// @brief el estado de compras del usuario
/// @param tra_list es el array de estructuras de Tracking
/// @param tra_len es la cantidad maxima de Tracking
/// @param pro_list es el array de estructuras de Productos
/// @param pro_len es la cantidad maxima de Productos
/// @param userId el usuario que se loguea
/// @return devuelve un 0 si esta OK o un -1 si hay error
int union_estadoCompras (Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId)
{
	int rtn = -1;
	int flagAlta;
	int opcion;
	int idIngresado;
	int indiceTracking;
	int indProducto;

	if (tra_list != NULL && tra_len > 0 &&
		pro_list != NULL && pro_len > 0 &&
		userId >= 0)
	{
		if (union_imprimir(tra_list, tra_len, pro_list, pro_len, userId) == 0)
		{
			flagAlta = 1;
		}

		if (flagAlta == 1)
		{
			do
			{
				utn_getIntRange(&opcion, "Desea: 1 - Cancelar un producto En VIAJE\n"
										 "       2 - Actualizar Estado Compras\n"
										 "       3 - Salir\n"
										"Ingrese su opcion: ", "Ingrese un numero valido.\n", 1, 3);
				switch (opcion)
				{
					case 1:
						if (actualizarEstado (tra_list, tra_len, userId) == 0 && union_imprimirENVIAJE(tra_list, tra_len, pro_list, pro_len, userId) == 0)
						{
							if( utn_getIntAlone (&idIngresado ,"\nIngrese un ID de un producto EN VIAJE: ", "Error. Ingrese un ID correcto.\n") == 0)
							{
								while (tra_findById(tra_list, tra_len, idIngresado) == -1)
								{
									puts("NO EXISTE ID.");
									utn_getIntAlone (&idIngresado ,"\nIngrese un ID de un producto EN VIAJE: ", "Error. Ingrese un ID correcto.\n\n");
								}
								indiceTracking = tra_findById(tra_list, tra_len, idIngresado);
								tra_list[indiceTracking].isEmpty = TRA_CANCELADO;
								indProducto = pro_findById(pro_list, pro_len, idIngresado);
								if (pro_list[indProducto].isEmpty == PRO_SIN_STOCK)
								{
									pro_list[indProducto].isEmpty = USU_OCUPADO;
								}
								pro_list[indProducto].stock += tra_list[indiceTracking].cantidad;
							}
						}
						else
						{
							puts ("No hay Compras en viaje para cancelar.");
						}
						break;

					case 2:
						actualizarEstado (tra_list, tra_len, userId);
						union_imprimir(tra_list, tra_len, pro_list, pro_len, userId);
						break;
				}
			}
			while (opcion != 3);
			rtn = 0;
		}
	}
	return rtn;
}

/// @fn int union_imprimir(Tracking*, int, Producto*, int, int)
/// @brief imprimir
/// @param tra_list es el array de estructuras de Tracking
/// @param tra_len es la cantidad maxima de Tracking
/// @param pro_list es el array de estructuras de Productos
/// @param pro_len es la cantidad maxima de Productos
/// @param userId
/// @return devuelve un 0 si esta OK o un -1 si hay error
int union_imprimir(Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId)
{
	int rtn = -1;
	int flagPrimerCompra = 0;
	int indiceProducto;

	if (tra_list != NULL && tra_len > 0 &&
		pro_list != NULL && pro_len > 0 &&
		userId >= 0)
	{
		for (int i = 0; i < tra_len; i++)
		{
			if (tra_list[i].isEmpty != TRA_LIBRE && tra_list[i].FK_idComprador == userId)
			{
				if (flagPrimerCompra == 0)
				{
					flagPrimerCompra = 1;
					puts("\n\t\t\t\t\t> LISTADO COMPRAS\n"
							"--------------------------------------------------------"
							"-------------------------------------------------------");
					printf("%-11s %-11s %-27s %-8s %-10s %-14s %-s\n", "ID TRACKING", "ID PRODUCTO", "NOMBRE PRODUCTO", "CANTIDAD", "PRECIO", "ESTADO PROD", "HORA LLEGADA");
				}
				indiceProducto = pro_findById(pro_list, pro_len, tra_list[i].idProducto);
				union_printOne (&tra_list[i], &pro_list [indiceProducto]);
				rtn = 0;
			}
		}
	}

	return rtn;
}

int union_imprimirENVIAJE(Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId)
{
	int rtn = -1;
	int flagPrimerCompra = 0;
	int indiceProducto;

	if (tra_list != NULL && tra_len > 0 &&
		pro_list != NULL && pro_len > 0 &&
		userId >= 0)
	{
		for (int i = 0; i < tra_len; i++)
		{
			if (tra_list[i].isEmpty == TRA_EN_VIAJE && tra_list[i].FK_idComprador == userId)
			{
				if (flagPrimerCompra == 0)
				{
					flagPrimerCompra = 1;
					puts("\n\t\t\t\t> LISTADO COMPRAS\n"
							"------------------------------------------------------------------------------------------");
					printf("%-11s %-11s %-27s %-8s %-10s %-14s %-s\n", "ID TRACKING", "ID PRODUCTO", "NOMBRE PRODUCTO", "CANTIDAD", "PRECIO", "ESTADO PROD", "HORA LLEGADA");
				}
				indiceProducto = pro_findById(pro_list, pro_len, tra_list[i].idProducto);
				union_printOne (&tra_list[i], &pro_list [indiceProducto]);
				rtn = 0;
			}
		}
	}

	return rtn;
}


void union_printOne (Tracking* list, Producto* auxProducto)
{
	if (list->isEmpty == TRA_EN_VIAJE || list->isEmpty == TRA_ENTREGADO)
	{
		printf ("%-11d %-11d %-27s %-8d %-10.2f %-14s %-s\n",
				list->idTracking, list->idProducto ,auxProducto->nombreProducto, list->cantidad , list->costo, ESTADO_PRODUCTO [(list->isEmpty)-1], ctime(&list->horaLlegada));
	}
	else
	{
		printf ("%-11d %-11d %-27s %-8d %-10.2f %-14s %-s\n",
				list->idTracking, list->idProducto ,auxProducto->nombreProducto, list->cantidad , list->costo, ESTADO_PRODUCTO [(list->isEmpty)-1], "------");
	}
}

// VENTAS
int union_estadoVentas (Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId)
{
	int rtn = -1;
	int opcion;
	int respuesta;

	if (tra_list != NULL && tra_len > 0 &&
		pro_list != NULL && pro_len > 0 &&
		userId >= 0)
	{
		do
		{

			utn_getIntRange(&opcion, "Desea: 1 - Listado de ventas FINALIZADAS\n"
					 	 	 	 	 "       2 - Ver productos en Venta\n"
									 "       3 - Salir\n"
									"Ingrese su opcion: ", "Ingrese un numero valido.\n", 1, 3);
			switch (opcion)
			{
				case 1:
					if (actualizarEstado (tra_list, tra_len, userId) != 0 || tra_imprimirVentas(tra_list, tra_len, pro_list, pro_len, userId) != 0)
					{
						puts ("No tienes Ventas finalizadas");
					}
					break;
				case 2:
					if (actualizarEstado (tra_list, tra_len, userId) != 0 || pro_imprimirMismoVendedor(pro_list, pro_len, userId) != 0)
					{
						puts ("No tienes ventas para mostrar");
					}
					break;
				case 3:
					respuesta = 1;
					break;

			}
			if (opcion != 3) respuesta = validacionDosCaracteres ("¿Desea elegir otra opcion? (S/N)", 'S', 'N');
		}
		while (respuesta == 1);
		rtn = 0;

	}
	return rtn;
}

int tra_imprimirVentas(Tracking* tra_list, int tra_len, Producto* pro_list, int pro_len, int userId)
{
	int rtn = -1;
	int flagPrimerCompra = 0;
	int indiceProducto;

	if (tra_list != NULL && tra_len > 0 &&
		pro_list != NULL && pro_len > 0 &&
		userId >= 0)
	{
		for (int i = 0; i < tra_len; i++)
		{
			if ((tra_list[i].isEmpty == TRA_ENTREGADO || tra_list[i].isEmpty == TRA_CANCELADO) && tra_list[i].FK_idVendedor == userId)
			{
				if (flagPrimerCompra == 0)
				{
					flagPrimerCompra = 1;
					puts("\n\t\t\t\t> LISTADO VENTAS\n"
						"------------------------------------------------------------------------------------------");
					printf("%-11s %-11s %-27s %-8s %-10s %-14s %-s\n", "ID TRACKING", "ID PRODUCTO", "NOMBRE PRODUCTO", "CANTIDAD", "PRECIO", "ESTADO PROD", "HORA LLEGADA");
				}
				indiceProducto = pro_findById(pro_list, pro_len, tra_list[i].idProducto);
				union_printOne (&tra_list[i], &pro_list [indiceProducto]);
				rtn = 0;
			}
		}
	}

	return rtn;
}




