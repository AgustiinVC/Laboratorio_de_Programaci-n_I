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

int controller_loadSalonFromText(char* path , LinkedList* pArrayListSalon);
int controller_loadArcadeFromText(char* path , LinkedList* pArrayListArcade);
int controller_loadJuegoFromText(char* path , LinkedList* pArrayListJuego);

int controller_saveSalonAsText(char* path , LinkedList* pArrayListSalones);
int controller_saveArcadeAsText(char* path , LinkedList* pArrayListArcades);
int controller_saveJuegoAsText(char* path , LinkedList* pArrayListJuegos);

int controller_addSalon(LinkedList* pArrayListSalon);
int controller_removeSalon(LinkedList* pArrayListSalon, LinkedList* pArrayArcade);
int controller_listSalon(LinkedList* pArrayListSalon);

int controller_addArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controller_editArcade (LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controller_removeArcade (LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);
int controller_listArcade(LinkedList* pArrayListSalon, LinkedList* pArrayListArcade, LinkedList* pArrayListJuego);

int controller_addJuego(LinkedList* pArrayListJuegos);
int controller_listJuego(LinkedList* pArrayListJuegos);

int controller_getIndexSalonById(LinkedList* pArrayList, int id);
int controller_getIndexArcadeById(LinkedList* pArrayList, int id);
int controller_getIndexJuegoById(LinkedList* pArrayList, int id);

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
