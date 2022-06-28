/*
 ============================================================================
 Name        : Clase.c
 Author      : Agustín
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	setbuf(stdout, NULL);
	//MALLOC - CALLOC - REALLOC
	int TAM = 10;

	//--------------------- MALLOC
	/*
	int* p = (int*)malloc(sizeof(int) * TAM);
	if(p != NULL){
		for(int i = 0; i<TAM; i++){
			printf("DIR: %p\nVAL: %d\n\n", p+i, *(p+i));
		}
	}
	*/
	//--------------------- CALLOC
	int* p = (int*)calloc(TAM, sizeof(int));

	if(p != NULL){
			for(int i = 0; i<TAM; i++){
			printf("DIR: %p\nVAL: %d\n\n", p+i, *(p+i));
		}
	}

	//--------------------- REALLOC
	int* q = (int*)realloc(p, 1000000000);

	if(q != NULL){
		if(p != q){
			for(int i = 0; i<TAM; i++){
				printf("DIR: %p\nVAL: %d\n\n", p+i, *(p+i));
			}
		}
	}

	/*
	 * CREAR UNA FUNCION CON LA CANTIDAD DE ELEMENTOS QUE EL USUARIO INGRESE
	 * CARGAR TODOS LOS DATOS
	 * PEDIR UN NUEVO TAMAÑO Y REDIMENSIONARLO.
	 */

	return 0;
}
