/*
 * ControllerArcade.h
 *
 *  Created on: 28 jun. 2022
 *      Author: Agostin
 */

#ifndef CONTROLLERARCADE_H_
#define CONTROLLERARCADE_H_
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "Juegos.h"
#include "Salones.h"
#include "parser.h"
#include "validaciones.h"
#include "ControllerJuego.h"
#include "ControllerSalon.h"

int controllerArcade_loadArcadeFromText(char* path , LinkedList* pArrayListArcade);

int controllerArcade_saveArcadeAsText(char* path , LinkedList* pArrayListArcades);

int controllerArcade_addArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controllerArcade_editArcade (LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controllerArcade_removeArcade (LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controllerArcade_listArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);

int controllerArcade_getIndexArcadeById(LinkedList* pArrayList, int id);


#endif /* CONTROLLERARCADE_H_ */
