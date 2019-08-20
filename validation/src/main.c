#include<stdio.h>
#include"main.h"

int nombre;

int incrementation(int val1){
	val1 ++;
	return val1;
}

int main(void){
	int i;

	fonction();
	nombre = 10;
	printf("Avant incrémentation --> %d\n", nombre);
	for(i = 0; i<4; i++){
		nombre = incrementation(nombre);
	}
	printf("Après incrémentation --> %d\n", nombre);

	return 0;
}
