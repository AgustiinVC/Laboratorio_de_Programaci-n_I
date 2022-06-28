/*
 * ControllerSalon.h
 *
 *  Created on: 28 jun. 2022
 *      Author: Agostin
 */

#ifndef CONTROLLERSALON_H_
#define CONTROLLERSALON_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "Juegos.h"
#include "Salones.h"
#include "parser.h"
#include "validaciones.h"

int controllerSalon_loadSalonFromText(char* path , LinkedList* pArrayListSalon);

int controllerSalon_saveSalonAsText(char* path , LinkedList* pArrayListSalones);

int controllerSalon_addSalon(LinkedList* pArrayListSalon);
int controllerSalon_removeSalon(LinkedList* pArrayListSalon, LinkedList* pArrayArcade);
int controllerSalon_listSalon(LinkedList* pArrayListSalon);

int controllerSalon_getIndexSalonById(LinkedList* pArrayList, int id);

#endif /* CONTROLLERSALON_H_ */
