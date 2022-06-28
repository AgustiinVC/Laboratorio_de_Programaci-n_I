/*
 * parser.h
 *
 *  Created on: 6 jun. 2022
 *      Author: Agostin
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcades.h"
#include "Salones.h"
#include "Juegos.h"
#include "validaciones.h"

int parser_SalonesFromText(FILE* pFile , LinkedList* pArrayListSalones);
int parser_SalonLastIdFromText(FILE* pFile);

int parser_ArcadesFromText(FILE* pFile , LinkedList* pArrayListArcades);
int parser_ArcadeLastIdFromText(FILE* pFile);

int parser_JuegoFromText(FILE* pFile , LinkedList* pArrayListJuegos);
int parser_JuegoLastIdFromText(FILE* pFile);

int parser_LastIdFromText(FILE* pFile);


#endif /* PARSER_H_ */
