/*
 * Pantalla-Contrataciones.c
 *
 *  Created on: 3 may. 2022
 *      Author: Agostin
 */
#include "validaciones.h"
#include "Pantalla-Contrataciones.h"

int union_AltaDeContratacion (Pantalla* aPantalla, int pant_len, Contrataciones* aContrataciones, int cont_len)
{
	int rtn = -1;
	int idBuscar;
	int indexPantalla;
	int indexContratacionesVacio;
	Contrataciones aux_Contra;

	if (aPantalla != NULL)
	{
		if (aContrataciones != NULL)
		{
			if (pant_len > 0 || cont_len > 0)
			{
				indexContratacionesVacio = cont_indexEmpty(aContrataciones, cont_len);
				if (indexContratacionesVacio != -1)
				{
					//Listar Pantalla
					if (pant_imprimirEstructura(aPantalla,pant_len) == 0)
					{
						//Obterner ID - Index Array
						utn_getIntRange (&idBuscar, "Ingrese el ID de pantalla: ","Ingrese un ID Correcto", 0, pant_len);
						indexPantalla = pant_buscarporID (aPantalla,pant_len, idBuscar);
						if (indexPantalla != -1)
						{
							cont__altaArray(&aux_Contra, cont_len);
							aux_Contra.FK_idPantalla = aPantalla[indexPantalla].id;
							aux_Contra.isEmpty = OCUPADO;
							aux_Contra.id = cont_generarIdUnico();
							aContrataciones[indexContratacionesVacio] = aux_Contra;
							rtn = 0;
						}
						else
						{
							rtn = -6; //No existe ese ID
						}
					}
					else
					{
						rtn = -5; //No hay pantallas cargadas
					}
				}
				else
				{
					rtn = -4; //No hay mas lugar para contrataciones
				}
			}
			else
			{
				rtn = -3; //Tamaños igual a 0
			}
		}
		else
		{
			rtn = -2; //Contrataciones NULL
		}
	}

	return rtn;
}

int union_ModificarContratacion (Pantalla* aPantalla, int pant_len, Contrataciones* aContrataciones, int cont_len)
{
	int rtn = -1;
	int idBuscar;
	int cuitIngresado;
	int indexPantalla;
	int indexContratacionesVacio;
	Contrataciones aux_Contra;

	if (aPantalla != NULL)
	{
		if (aContrataciones != NULL)
		{
			if (pant_len > 0 || cont_len > 0)
			{
				utn_getIntPositivo(&cuitIngresado, "Ingrese su CUIT (solo numeros): ","Ingrese solo numeros.");
				//Listar Pantalla
				if (pant_imprimirEstructura(aPantalla,pant_len) == 0)
				{
					//Obterner ID - Index Array
					utn_getIntRange (&idBuscar, "Ingrese el ID de pantalla: ","Ingrese un ID Correcto", 0, pant_len);
					indexPantalla = pant_buscarporID (aPantalla,pant_len, idBuscar);
					if (indexPantalla != -1)
					{
						cont__altaArray(&aux_Contra, cont_len);
						aux_Contra.FK_idPantalla = aPantalla[indexPantalla].id;
						aux_Contra.isEmpty = OCUPADO;
						aux_Contra.id = cont_generarIdUnico();
						aContrataciones[indexContratacionesVacio] = aux_Contra;
						rtn = 0;
					}
					else
					{
						rtn = -6; //No existe ese ID
					}
				}
				else
				{
					rtn = -5; //No hay pantallas cargadas
				}
			}
			else
			{
				rtn = -3; //Tamaños igual a 0
			}
		}
		else
		{
			rtn = -2; //Contrataciones NULL
		}
	}

	return rtn;
}



int union_imprimirEstructura (Pantalla* aPantalla, int pant_len, Contrataciones* aContrataciones, int cont_len)
{
	int rtn = -1;
	int flagPrimerEntrada = 0;

	if (aPantalla != NULL && len > 0)
	{
		for (int i = 0; i < pant_len; i++)
		{
			if (aPantalla[i].isEmpty == OCUPADO)
			{
				if (flagPrimerEntrada == 0)
				{
					flagPrimerEntrada = 1;
					puts("\n\t\t\t\t> LISTADO PANTALLAS");
					printf("%-6s %-52s %-52s %-15s %-16s %-16s %-13s %-52s\n", "ID", "NOMBRE", "DIRECCION", "PRECIO", "TIPO DE PANTALLA", "CANTIDAD DIAS", "ID CONTRATO" "NOMBRE ARCHIVO");
				}

				union_imprimirUnElemento (&list[i]);
				rtn = 0;
			}
		}
	}

	return rtn;
}

int union_imprimirUnElemento (Pantalla* list)
{
	int rtn = -1;

	if (list->isEmpty == LIBRE || list->isEmpty == BAJA)
	{
		puts ("No hay nada en ese indice.");
		rtn = -2;
	}
	else
	{
		printf ("%-6d %-52s %-52s %-15.2f %-16s\n",
				list->id, list->nombre, list->direccion, list->precio, TXT_TIPOS[ (list->tipoDePantalla) - 1] );

		rtn = 0;
	}
	return rtn;
}
