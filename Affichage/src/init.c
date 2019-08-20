#include<stdio.h>
#include<unistd.h>
#include"main.h"
//-----------------------------------------

//initialisation de la matrice et des colonne de jeton à 0

void init_jeton_de_colonne()
{
	for (int i = 0; i < NOMBRE_COLONNE; i++)
	{
		jeton_de_colonne[i] = 0;
	}
}
//-----------------------------------------

void init_matrice()
{
	for (int i = 0; i < NOMBRE_LIGNE; i++)
	{
		for (int y = 0; y < NOMBRE_COLONNE; y++)
		{
			grille_matrice[i][y] = 0;
		}
	}
}

