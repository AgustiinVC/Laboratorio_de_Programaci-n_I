/*
 * Usuario.c
 *
 *  Created on: 14 may. 2022
 *      Author: Agostin
 */

#include "validaciones.h"
#include "Usuario.h"

//ESTADOS A IMPRIMIR DE UN USUARIO
static const char ESTADO_USUARIO [3][12] = {"ACTIVO", "DE BAJA", "BAJA ADMIN"};

/// Inicio de variable ID Usuario
static int Usuario_idUnico = 1;

/// @fn int eUsu_ObtenerID (void)
/// @brief
///  Generador de ID de cada Usuario. Suma 1 a la variable
/// @return devuelve el id de cada Usuario
static int eUsu_ObtenerID (void)
{
	return Usuario_idUnico++;
}


/// @fn int usu_initArray(Usuario*, int)
/// @brief
/// funcion para iniciar la estructura pasajeros al poner en LIBRE el campo isEmpty
/// @param list es la estructura Usuario
/// @param len es el tamaño de la estructura
/// @return devuelve un 0 si esta OK. Devuelve un -1 si hay algun error.
int usu_initArray(Usuario* list, int len)
{
	int rtn = -1;
	int i;
	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			list[i].isEmpty = USU_LIBRE;
			rtn = 0;
		}
	}
	return rtn;
}

/// @fn int usu_indexEmpty(Usuario*, int)
/// @brief
/// funcion para buscar un indice que este vacio
/// @param list es la estructura Usuario
/// @param len es el tamaño de la estructura
/// @return devuelve el indice que se encuentra libre.. Devuelve un -1 si hay algun error.
int usu_indexEmpty (Usuario* list, int len)
{
	int rtn = -1;
	int i;
	if (list != NULL && len >= 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].isEmpty == USU_LIBRE)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

/// @fn int cargaDatosUsuario(Usuario*)
/// @brief
/// carga de datos en un Usuario auxiliar para luego ser cargada en la estructura de Usuario
/// @param auxList un Usuario auxiliar
/// @return devuelve un 0 si esta OK. un -1 si hay algun error
int cargaDatosUsuario (Usuario* auxList)
{
	int rtn = -1;
	if (auxList != NULL)
	{
		if (utn_getEmail(auxList->correo, "\nIngrese su mail: ", "Ingrese un mail valido\n", 4, CORREO_LEN, 3) == 0 &&
			utn_getDescripcion(auxList->direccion, "Ingrese su direccion: ", "Ingrese una direccion valida\n ", TEXT_LEN, 3) == 0 &&
			utn_getIntRange(&auxList->codPostal, "Ingrese el codigo postal: ", "Ingrese un codigo valido\n", 0001,9999) == 0 &&
			utn_getCodigo(auxList->password, "Ingrese una contraseña (Alfanumerico min: 4 caracteres): ", "Ingrese una contraseña valido\n", 4, PASSWORD, 3) == 0)
		{
			auxList->idUsuario = eUsu_ObtenerID();
			auxList->isAdmin = 0;
			auxList->isEmpty = USU_OCUPADO;
			rtn = 0;
		}
	}

	return rtn;
}

/// @fn int usu_altaArray(Usuario*, int)
/// @param list array de usuarios
/// @param len cantidad de usuarios maximo
/// @return un 0 si esta OK y un -1 si hay error.
int usu_altaArray(Usuario* list , int len)
{
	int rtn = -1;
	int indiceLibre;
	int indiceCorreo;
	Usuario auxiliarEstructura;
	//busco un indice libre
	indiceLibre = usu_indexEmpty (list, len);

	if (list != NULL && len > 0 && indiceLibre != -1)
	{
		//pido los datos de un usuario y lo guardo en una estructura auxiliar
		if (cargaDatosUsuario(&auxiliarEstructura) == 0)
		{
			//busco antes si ese correo ya se dio de alta alguna vez
			indiceCorreo = buscarUsuarioPorCorreo(list, len, auxiliarEstructura.correo);
			if ( indiceCorreo != -1)
			{
				//Si un admin lo dio de baja, el usuario no puede darse de alta otra vez
				if (list[indiceCorreo].isEmpty == USU_BAJA_PERMANENTE)
				{
					puts("USUARIO BANEADO PERMANENTE POR ACTOS ILEGALES");
				}
				else
				{
					//si el usuario se dio de baja si puede darse de alta
					puts ("USUARIO YA REGISTRADO");
					if (list[indiceCorreo].isEmpty == USU_BAJA && validacionDosCaracteres ("¿Desea darse de alta otra vez?", 'S', 'N') == 1)
					{
						puts ("USUARIO DADO DE BAJA. SE DIO EL ALTA OTRA VEZ");
						list[indiceCorreo].isEmpty = USU_OCUPADO;
					}
					//Se pregunta si quiere recuperar su contraseña si ingreso anteriormente los datos originales
					if (validacionDosCaracteres ("¿Desea recuperar su contraseña? (S/N) Se comparara la direccion y cod postal ingresados.", 'S', 'N') == 1 &&
						compararCadenas(auxiliarEstructura.direccion, list[indiceCorreo].direccion, TEXT_LEN) == 3 &&
						auxiliarEstructura.codPostal == list[indiceCorreo].codPostal)
					{
						printf("Su contraseña original es: %s\n", list[indiceCorreo].password);
						presionarEnter();
					}
					else
					{
						puts ("Ingrese la direccion y codigo postal originales. Saludos.");
					}
				}
			}
			else
			{
				//si no se dio de alta ese correo en nuestra estructura entonces procedo a copiarlo en el indice libre
				list[indiceLibre] = auxiliarEstructura;
			}
			rtn = 0;
		}
	}
	return rtn;
}

/// @fn int buscarUsuario(Usuario*, int)
/// @brief se busca un usuario para el login. dicho usuario debe estar dado de alta.
/// @param list el array de estructura de usuario
/// @param len la cantidad maxima de usuario
/// @return devuelve el indice del usuario si se encontro o un -1 si no se encontro
int buscarUsuario(Usuario* list , int len)
{
	int rtn = -1;
	char auxEmail [CORREO_LEN];
	char auxPassword [PASSWORD];

	if (list != NULL &&  len > 0)
	{
		if (utn_getEmail(auxEmail, "\nIngrese su mail: ", "Ingrese un mail valido\n", 4, CORREO_LEN, 3) == 0 &&
			utn_getCodigo(auxPassword, "Ingrese una contraseña (Alfanumerico min: 4 caracteres): ", "Ingrese una contraseña valido\n", 4, PASSWORD, 3) == 0)
		{
			for (int i = 0; i < len; i++)
			{
				if ( compararMismoCaracteres(auxEmail, list[i].correo, CORREO_LEN) == 3 &&
					 compararMismoCaracteres(auxPassword, list[i].password, PASSWORD) == 3 &&
					 list[i].isEmpty == USU_OCUPADO)
				{
					rtn = i;
					break;
				}
			}
		}
	}
	return rtn;
}

/// @fn int buscarUsuarioPorCorreo(Usuario*, int, char*)
/// @brief busqueda de usuerio por el correo ingresado
/// @param list el array de estructura de usuario
/// @param len la cantidad maxima de usuario
/// @param correo el correo a comparar
/// @return devuelve el indice del usuario si se encontro o un -1 si no se encontro
int buscarUsuarioPorCorreo(Usuario* list , int len, char* correo)
{
	int rtn = -1;

	if (list != NULL &&  len > 0)
	{
			for (int i = 0; i < len; i++)
			{
				if ( compararMismoCaracteres(correo, list[i].correo, CORREO_LEN) == 3)
				{
					rtn = i;
					break;
				}
			}
	}
	return rtn;
}

/// @fn int usu_altaForzadaArray(Usuario*, int, char*, char*, char*, int, int)
/// @brief alta forzada de un usuario
/// @param list el array de estructura de usuario
/// @param len la cantidad maxima de usuario
/// @param correo el correo a comparar
/// @param password su contraseña
/// @param direccion de su casa
/// @param codPostal donde se encuentra
/// @param isAdmin si es admin o no
/// @return devuelve un 0 si esta ok
int usu_altaForzadaArray(Usuario* list , int len, char* correo, char* password, char* direccion , int codPostal, int isAdmin)
{
	int rtn = -1;
	int indiceLibre;
	Usuario auxiliarEstructura;

	indiceLibre = usu_indexEmpty (list, len);

	if (list != NULL && len > 0 && indiceLibre != -1)
	{
		strncpy (auxiliarEstructura.correo,correo, CORREO_LEN);
		strncpy (auxiliarEstructura.password,password, PASSWORD);
		strncpy (auxiliarEstructura.direccion,direccion, TEXT_LEN);
		auxiliarEstructura.codPostal = codPostal;
		auxiliarEstructura.isAdmin = isAdmin;
		auxiliarEstructura.isEmpty = USU_OCUPADO;
		auxiliarEstructura.idUsuario = eUsu_ObtenerID();
		list[indiceLibre] = auxiliarEstructura;
		rtn = 0;
	}
	return rtn;
}

/// @fn int usu_findById(Usuario*, int, int)
/// @brief
/// busca el id en todos los Usuario dados de alta.
/// @param list es la estructura Usuario
/// @param len es la cantidad maxima de Usuario
/// @param id del Usuario a buscar
/// @return devuelve el indice del ID buscado si se encontro y no esta dado de baja. un -1 si hay algun error
int usu_findById(Usuario* list, int len,int id)
{
	int rtn = -1;
	int i;

	if (list != NULL && len > 0)
	{
		for (i = 0; i < len; i++)
		{
			if (list[i].idUsuario == id && list[i].isEmpty == USU_OCUPADO)
			{
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}


/// @fn int removePassenger(Passenger*, int, int)
/// @brief
/// funcion para dar de baja a un pasajero que se haya dado de alta.
/// @param list es la estructura pasajero
/// @param len es la cantidad maxima de pasajeros
/// @param id del pasajero a dar de baja
/// @return devuelve un 0 si esta OK. Un -1 si hay algun error
int usu_remover(Usuario* list, int len, int id)
{
	int rtn = -1;

	if (list != NULL && len >= 0 && id < len && id >= 0 && list[id].isEmpty == USU_OCUPADO)
	{
		list[id].isEmpty = USU_BAJA;
		rtn = 0;
	}
	return rtn;
}

/// @fn int usu_Baja(Usuario*, int)
/// @brief funcion para dar de baja un Usuario. se imprime la lista de Usuario si hay dados de alta. Luego se pide ingresar
/// un id que se quiere dar de baja. si se ingreso un id que se encuentra dado de alta, se preocede a dar de baja en la funcion usu_remover.
/// @param list es la estructura Usuario
/// @param len es la cantidad maxima de Usuario
/// @return devuelve un 0 si esta OK. Un -1 si hay algun error
int usu_Baja (Usuario* list, int len)
{
	int rtn = -1;
	int idIngresado;
	int index;
	int flagAlta = 0;
	if (usu_imprimir(list, len) == 0)
	{
		flagAlta = 1;
	}

	if (flagAlta)
	{
		if( utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n") == 0)
		{
			while (usu_findById(list, len, idIngresado) == -1)
			{
				puts("NO EXISTE ID.");
				utn_getIntAlone (&idIngresado ,"\nIngrese un ID: ", "Error. Ingrese un numero.\n");
			}

			index = usu_findById(list, len, idIngresado);
			if (validacionDosCaracteres ("¿Esta seguro de querer borrar el usuario? (S/N)", 'S', 'N') == 1)
			{
				if (usu_remover(list, len, index) == 0)
				{
					rtn = 0;
				}
			}
		}
	}

	return rtn;
}


/// @fn int usu_imprimir(Usuario*, int)
/// @brief
/// funcion para imprimir los Usuario dados de alta
/// @param list es la estructura Usuario
/// @param length es la cantidad maxima de Usuario
/// @return devuelve un 0 si esta ok. un -1 si hay un error.
int usu_imprimir(Usuario* list, int length)
{
	int rtn = -1;
	int flagPrimerUsuario = 0;

	if (list != NULL && length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i].isEmpty == USU_OCUPADO && list[i].isAdmin == 0)
			{
				if (flagPrimerUsuario == 0)
				{
					flagPrimerUsuario = 1;
					puts("\n\t\t\t\t\t\t> LISTADO USUARIOS\n"
							"--------------------------------------------------------"
							"--------------------------------------------------------");
					printf("%-6s %-27s %-12s %-50s %-13s\n", "ID", "CORREO", "PASSWORD", "DIRECCION", "CODIGO POSTAL");
				}

				usu_printOne (&list[i]);
				rtn = 0;
			}
		}
	}

	return rtn;
}

/// @fn void pro_printOne(Usuario*)
/// @brief
/// impresion de un solo Usuario
/// @param list es el Usuario que se va a imprimir
void usu_printOne (Usuario* list)
{
	printf ("%-6d %-27s %-12s %-50s %-13d\n",
		list->idUsuario, list->correo, list->password, list->direccion, list->codPostal);
}


/// @fn int usu_imprimir(Usuario*, int)
/// @brief
/// funcion para imprimir los Usuario dados de alta
/// @param list es la estructura Usuario
/// @param length es la cantidad maxima de Usuario
/// @return devuelve un 0 si esta ok. un -1 si hay un error.
int usu_imprimirEstado(Usuario* list, int length)
{
	int rtn = -1;
	int flagPrimerUsuario = 0;

	if (list != NULL && length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			if (list[i].isEmpty != USU_LIBRE && list[i].isAdmin == 0)
			{
				if (flagPrimerUsuario == 0)
				{
					flagPrimerUsuario = 1;
					puts("\n\t> LISTADO ESTADO USUARIOS\n"
							"------------------------------------------");
					printf("%-6s %-27s %-s\n", "ID", "CORREO", "ESTADO");
				}

				usu_printOneEstado (&list[i]);
				rtn = 0;
			}
		}
	}

	return rtn;
}


/// @fn void pro_printOne(Usuario*)
/// @brief
/// impresion de un solo Usuario
/// @param list es el Usuario que se va a imprimir
void usu_printOneEstado (Usuario* list)
{
	printf ("%-6d %-27s %-10s\n",
		list->idUsuario, list->correo, ESTADO_USUARIO[(list->isEmpty)-1]);
}

int usu_modificarDatos (Usuario* list, int len, int userId)
{
	int rtn = -1;
	int respuesta;
	int opcion;
	Usuario auxiliarUsuario = list[userId];

	if (list != NULL && len > 0)
	{
		puts ("---Datos del usuario---");
		printf("%-6s %-27s %-12s %-50s %-13s\n", "ID", "CORREO", "PASSWORD", "DIRECCION", "CODIGO POSTAL");
		usu_printOne (&list[userId]);
		do
		{
			fflush(stdin);
			utn_getIntRange (&opcion ,"\nIngrese la opcion a modificar:\n "
										"1 - Correo\n "
										"2 - Password\n "
										"3 - Direccion\n "
										"4 - Codigo Postal\n "
										"5 - Darse de baja\nOpcion: ",
										"Error. Ingrese una opcion correcta\n\n", 1, 5);

			switch (opcion)
			{
				case 1:
					if( utn_getEmail(auxiliarUsuario.correo, "\nIngrese su mail: ", "Ingrese un mail valido\n", 4, CORREO_LEN, 3) == 0)
					{
						puts ("Cambio de correo correcta\n");
					}
					else
					{
						puts("No se pudo cambiar el correo\n");
					}
					break;

				case 2:
					if(utn_getCodigo(auxiliarUsuario.password, "Ingrese una contraseña (Alfanumerico min: 4 caracteres): ", "Ingrese una contraseña valido\n", 4, PASSWORD, 3))
					{
						puts ("Cambio de contraseña correcta\n");
					}
					else
					{
						puts ("No se pudo cambiar la contraseña");
					}
					break;

				case 3:
					if(utn_getDescripcion(auxiliarUsuario.direccion, "Ingrese su direccion: ", "Ingrese una direccion valida\n ", TEXT_LEN, 3) == 0)
					{
						puts ("Cambio de direccion correcta\n");
					}
					else
					{
						puts ("No se pudo cambiar la direccion");
					}
					break;

				case 4:
					if(utn_getIntRange(&auxiliarUsuario.codPostal, "Ingrese el codigo postal: ", "Ingrese un codigo valido\n", 0001,9999))
					{
						puts ("Cambio de codigo postal correcta\n");
					}
					else
					{
						puts ("No se pudo cambiar el codigo postal");
					}
					break;

				case 5:
					if( validacionDosCaracteres ("¿Esta seguro de darse de baja? (S/N)", 'S', 'N') == 1)
					{
						auxiliarUsuario.isEmpty = USU_BAJA;
						puts ("Usuario dado de baja. Adios!\n");
						respuesta = 1;
					}
					else
					{
						puts("No se pudo dar de baja el usuario.");
					}
					break;
			}
			if (opcion != 5)
			{
				respuesta = validacionDosCaracteres ("¿Desea modificar otro campo? (S/N)", 'S', 'N');
			}
		}
		while (respuesta != 1);
		rtn = 0;
		list[userId] = auxiliarUsuario;
		usu_printOne(&list[userId]);
		puts (" ");
		usu_printOneEstado(&list[userId]);
	}
	return rtn;
}
