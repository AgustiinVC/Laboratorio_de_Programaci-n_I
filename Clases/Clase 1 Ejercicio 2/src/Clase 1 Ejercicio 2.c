/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define NROSMAX 5

//Ingreso 5 números, los sumo y hallo el promedio
int main(void) {
	setbuf (stdout,NULL);
	//Pedir dos números al usuario
	//sumarlos y mostrar la suma

	int nroIngresado;
	int sumaTotal = 0;
	float promedio;

	for (int i = 0; i < NROSMAX; i++)
	{
		printf("Ingrese un número: ");
		fflush (stdin);
		scanf ("%d", &nroIngresado);
		sumaTotal += nroIngresado;
	}


	promedio = (float)sumaTotal / 5;
	printf ("El promedio es: %.3f \n",promedio);


	return EXIT_SUCCESS;
}
