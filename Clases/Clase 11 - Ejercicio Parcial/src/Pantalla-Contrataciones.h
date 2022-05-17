/*
 * Pantalla-Contrataciones.h
 *
 *  Created on: 3 may. 2022
 *      Author: Agostin
 */

#ifndef PANTALLA_CONTRATACIONES_H_
#define PANTALLA_CONTRATACIONES_H_

#include "Pantalla.h"
#include "Contrataciones.h"

int union_AltaDeContratacion (Pantalla* aPantalla, int pant_len, Contrataciones* aContrataciones, int cont_len);
int union_MOdificarContratacion (Pantalla* aPantalla, int pant_len, Contrataciones* aContrataciones, int cont_len);
int union_MostrarTodos(Pantalla* aPantalla, int pant_len, Contrataciones* aContrataciones, int cont_len);

#endif /* PANTALLA_CONTRATACIONES_H_ */
