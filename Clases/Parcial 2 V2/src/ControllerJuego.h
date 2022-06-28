/*
 * ControllerJuego.h
 *
 *  Created on: 28 jun. 2022
 *      Author: Agostin
 */

#ifndef CONTROLLERJUEGO_H_
#define CONTROLLERJUEGO_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "Juegos.h"
#include "Salones.h"
#include "parser.h"
#include "validaciones.h"
#include "ControllerArcade.h"
#include "ControllerSalon.h"

int controllerJuego_loadJuegoFromText(char* path , LinkedList* pArrayListJuego);

int controllerJuego_saveJuegoAsText(char* path , LinkedList* pArrayListJuegos);

int controllerJuego_addJuego(LinkedList* pArrayListJuegos);
int controllerJuego_listJuego(LinkedList* pArrayListJuegos);

int controllerJuego_getIndexJuegoById(LinkedList* pArrayList, int id);

#endif /* CONTROLLERJUEGO_H_ */
