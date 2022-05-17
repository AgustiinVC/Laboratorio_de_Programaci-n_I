/*
 * Contrataciones.h
 *
 *  Created on: 3 may. 2022
 *      Author: Agostin
 */

#ifndef CONTRATACIONES_H_
#define CONTRATACIONES_H_

#include <stdio.h>
#include <stdlib.h>

#define LIBRE 0
#define OCUPADO 1
#define BAJA 2

#define NOMBRE_LEN 50

typedef struct
{
	int cuitCLiente;
	int cantDias;
	char nombreArchivo [NOMBRE_LEN];
	int isEmpty;
	int id;
	int FK_idPantalla;

}Contrataciones;

int cont_generarIdUnico (void);
int cont_initArray (Contrataciones* list , int len);
int cont_indexEmpty (Contrataciones* list , int len);
int cont__altaArray(Contrataciones* list , int len);
int cont_modificarEstructura (Contrataciones* list, int len);
Contrataciones cont_ModificarUno(Contrataciones list);
int cont_buscarporID (Contrataciones* list, int len, int id);
int cont_removeID(Contrataciones* list, int len, int id);
int cont_Baja (Contrataciones* list, int len);
int cont_imprimirEstructura (Contrataciones* list, int len);
int cont_imprimirUnElemento (Contrataciones* list);


#endif /* CONTRATACIONES_H_ */
