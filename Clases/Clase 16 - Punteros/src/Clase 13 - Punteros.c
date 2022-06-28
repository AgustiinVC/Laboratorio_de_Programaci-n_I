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

int main(void) {

	setbuf(stdout, NULL);

	int array[5] = {1, 2, 3, 4, 5};

	printf("%d\n", *(array));
	printf("%d\n", *(array+1));
	printf("%d\n", *(array+2));
	printf("%d\n", *(array+3));

	int* a = array;
	printf("%d\n", *(a));
	printf("%d\n", *(a+1));
	printf("%d\n", *(a+2));
	printf("%d\n", *(a+3));

	for(int i = 0; i<5; i++){
		printf("%d - ", *(a + i));
	}

	printf("\n\n%p\n", a);
	printf("%p\n", array);

	printf("ANTES %d", array[2]);
	int* b = a;
	*(b + 2) = 100;
	printf("\nDESPUES %d", array[2]);

	return 0;
}
