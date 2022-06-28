/*
 ============================================================================
 Name        : Parcial.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Parcial 2 - ¡Estamos en el año 1990!
 ============================================================================
 */

#include "Controller.h"

int main()
{
	setbuf (stdout,NULL);
    int opcion = 0; // Opcion que ingresemos

    LinkedList* listaSalones = ll_newLinkedList();
    LinkedList* listaArcades = ll_newLinkedList();
    LinkedList* listaJuegos = ll_newLinkedList();

    controller_getLastId(); // Tomo el ultimo id ya sea de un archivo aparte o del archivo csv

    controller_loadSalonFromText("dataSalones.csv", listaSalones);
    controller_loadArcadeFromText("dataArcades.csv", listaArcades);
    controller_loadJuegoFromText("dataJuegos.csv", listaJuegos);

    do
    	{
    		menu();
    		utn_getIntRange (&opcion ,"\nIngrese una Opcion: ", "Error. Ingrese una opcion correcta.\n",1,11);
    		fflush (stdin);
    		switch (opcion)
    		{
    			case 1: //ALTA SALON
    				if (controller_addSalon(listaSalones) == 0)
					{
						puts ("\n~~ALTA de SALON realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar el ALTA del SALON~~\n");
					}
					break;

    			case 2: //BAJA SALON
					if (controller_removeSalon(listaSalones, listaArcades) == 0)
					{
						puts ("\n~~BAJA de SALON realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar la BAJA del SALON~~\n");
					}
					break;

    			case 3: //LISTAR SALON
					if (controller_listSalon(listaSalones) == 0)
					{
						puts ("\n~~LISTA de SALON realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar la LISTA del SALON~~\n");
					}
					break;

				case 4: //ALTA ARCADE
					if (controller_addArcade(listaSalones, listaArcades, listaJuegos) == 0)
					{
						puts ("\n~~ALTA de ARCADE realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar el ALTA del ARCADE~~\n");
					}
					break;
				case 5: //MODIFICAR ARCADE
					if (controller_editArcade(listaSalones, listaArcades, listaJuegos) == 0)
					{
						puts ("\n~~MODIFICACION de ARCADE realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar la MODIFICACION del ARCADE~~\n");
					}
					break;

				case 6: //BAJA ARCADE
					if (controller_removeArcade(listaSalones, listaArcades, listaJuegos) == 0)
					{
						puts ("\n~~BAJA de ARCADE realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar la BAJA del ARCADE~~\n");
					}
					break;

				case 7: //LISTAR ARCADE
					if (controller_listArcade(listaSalones, listaArcades, listaJuegos) == 0)
					{
						puts ("\n~~LISTA de ARCADE realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar la LISTA del ARCADE~~\n");
					}
					break;

				case 8: //ALTA JUEGO
					if (controller_addJuego(listaJuegos) == 0)
					{
						puts ("\n~~ALTA de JUEGO realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar el ALTA del JUEGO~~\n");
					}
					break;

				case 9: //LISTAR JUEGO
					if (controller_listJuego(listaJuegos) == 0)
					{
						puts ("\n~~LISTA de JUEGO realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar la LISTA del JUEGO~~\n");
					}
					break;
				case 10: //INFORMES
					if (controller_informes(listaSalones, listaArcades, listaJuegos) == 0)
					{
						puts ("\n~~LISTA de INFORMES realizada~~\n");
					}
					else
					{
						puts ("\n~~No se pudo realizar la LISTA de INFORMES~~\n");
					}
					break;
    		}
    	}
    	while (opcion != 11);

		controller_saveSalonAsText("dataSalones.csv", listaSalones);
		controller_saveArcadeAsText("dataArcades.csv", listaArcades);
		controller_saveJuegoAsText("dataJuegos.csv", listaJuegos);
		controller_setLastId();

    	puts ("Salida");
}

