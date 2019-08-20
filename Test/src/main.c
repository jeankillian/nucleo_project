#include<stdio.h>
#include<iostream>

#define choix1 45
#define choix2 22

int main(void){

#ifdef choix1
	printf("Hello World!\n");
#ifdef choix2
	printf("Goodbye World!\n");

	return 0;
}
