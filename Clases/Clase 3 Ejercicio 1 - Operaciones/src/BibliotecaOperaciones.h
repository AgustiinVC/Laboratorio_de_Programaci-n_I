/*
 * BibliotecaOperaciones.h
 *
 *  Created on: 31 mar. 2022
 *      Author: Agostin
 *
 *  Aca van solo los includes de todas la bibliotecas que vaya a usar
 *  Tambien las definiciones de las funciones.
 *  Los Include se ponen entre el ifndef y el endif
 */

#ifndef BIBLIOTECAOPERACIONES_H_
#define BIBLIOTECAOPERACIONES_H_

#include <stdio.h>
#include <stdlib.h>

//Prototipos

float sumar (float, float);
float restar (float, float);
float multiplicar (float, float);
//No se puede dividir por 0, en ese caso retornar 0
float dividirInt (int, int);
float dividir (float, float);


#endif /* BIBLIOTECAOPERACIONES_H_ */
