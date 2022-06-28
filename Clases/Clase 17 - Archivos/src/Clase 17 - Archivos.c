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

	//----------------------------- ESCRITURA TEXTO
	FILE* pArchivo;
	pArchivo = fopen("archivo.txt", "w+");

	if(pArchivo != NULL){
		fprintf(pArchivo, "%d,%f\n", 1, 1500.00);
		fprintf(pArchivo, "%d,%f\n", 2, 4500.00);
		fprintf(pArchivo, "%d,%f\n", 3, 300.00);

		fclose(pArchivo);
		puts("Escribi...");
	}
	puts("");
	puts("");
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
		puts("Escribi...");
	}
	puts("");
	puts("");
	//----------------------------- LECTURA DE UN TEXTO
	pArchivo = fopen("archivo.txt", "r");
	if(pArchivo != NULL){

		do{
			fscanf(pArchivo, "%d,%f\n", &p.id, &p.sueldo);
			printf("ID: %d - SUELDO: %.2f\n",p.id, p.sueldo);

		}while(feof(pArchivo) == 0);

		fclose(pArchivo);
	}

	puts("");
	puts("");
	//----------------------------- LECTURA DE UN BINARIO
	pArchivoBin = fopen("archivoBin.bin", "rb");

	Pasajero aux;
	if(pArchivoBin != NULL){
		do{
			fread(&aux, sizeof(Pasajero), 1, pArchivoBin);
			printf("\nID: %d - SUELDO: %.2f - NOMBRE: %s", aux.id, aux.sueldo, aux.nombre);
		}while(feof(pArchivoBin) == 0);

		fclose(pArchivoBin);
	}

	return 0;
}
