/*
 * Controller.h
 *
 *  Created on: 26 jun. 2022
 *      Author: Agostin
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

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
#include "ControllerJuego.h"


int controller_getLastId(void);
int controller_setLastId();

int controller_informes (LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);

int controller_informeA(LinkedList* pArrayListSalon);
int controller_informeB(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controller_informeC(LinkedList* pArrayListSalon);
int controller_informeD(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controller_informeE(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controller_informeF(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controller_informeG(LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);

#endif /* CONTROLLER_H_ */
