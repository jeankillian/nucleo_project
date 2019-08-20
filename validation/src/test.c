#include<stdio.h>
#include"main.h"

extern int nombre;

void fonction(void){
	nombre = 25;
	printf("valeur %d\n", nombre);
}


