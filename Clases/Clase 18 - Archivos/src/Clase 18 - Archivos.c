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
#include <unistd.h>

#define PATH_ARCHIVO_CSV "archivo.txt"

typedef struct{
	int id;
	float sueldo;
	char nombre[30];
}Pasajero;

int main(void) {
	setbuf(stdout, NULL);
	//ABRIR
	/* MODOS
	 * "r" : Abre archivo para lectura. Debe existir.
	 * "w" : Abre archivo para escritura, crea uno nuevo si no existe o pisa si ya exista previamente uno
	 * "un": Abre archivo para escritura. Apendea. De no existir archivo lo crea.
	 * "r+": Abre archivo para escritura/lectura. Debe existir.
	 * "w+": Abre archivo lectura/escritura. Si no existe lo crea.
	 * "a+": Apendea.
	 */

	/*
	//----------------------------- ESCRITURA TEXTO
	FILE* pArchivo;
	pArchivo = fopen(PATH_ARCHIVO_CSV, "w");

	if(pArchivo != NULL){
		fprintf(pArchivo, "%d,%f\n", 1, 1500.00);
		fprintf(pArchivo, "%d,%f\n", 2, 4500.00);
		fprintf(pArchivo, "%d,%f\n", 3, 300.00);

		fclose(pArchivo);
		puts("Escribi en archivo.txt...");
	}

	//----------------------------- ESCRITURA DE UN BINARIO
	FILE* pArchivoBin;
	pArchivoBin = fopen("archivoBin.bin", "wb");

	Pasajero p;
	p.id = 10;
	p.sueldo = 1000;
	strcpy(p.nombre, "Juan");

	if(pArchivoBin != NULL){
		fwrite(&p, sizeof(Pasajero), 1, pArchivoBin);

		fclose(pArchivoBin);
		puts("Escribi en archivo.bin...");
	}
	*/

	FILE* pArchivo;
	FILE* pArchivoBin;

	Pasajero p;
	//----------------------------- LECTURA DE UN TEXTO
	pArchivo = fopen("archivo.txt", "r");
	if(pArchivo != NULL){

		do{
			fscanf(pArchivo, "%d,%f\n", &p.id, &p.sueldo);
			printf("ID: %d - SUELDO: %.2f\n",p.id, p.sueldo);

		}while(feof(pArchivo) == 0);

		puts("Final de archivo archivo.txt");
		fclose(pArchivo);
	}

	//----------------------------- LECTURA DE UN BINARIO
	pArchivoBin = fopen("archivoBin.bin", "rb");

	Pasajero aux;
	if(pArchivoBin != NULL){
		do{
			if(fread(&aux, sizeof(Pasajero), 1, pArchivoBin) == 1){
				printf("\nID: %d - SUELDO: %.2f - NOMBRE: %s\n", aux.id, aux.sueldo, aux.nombre);
			}
		}while(!feof(pArchivoBin));

		puts("Final de archivo.bin");
		fclose(pArchivoBin);
	}

	return 0;
}


