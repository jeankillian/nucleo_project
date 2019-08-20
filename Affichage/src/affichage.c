#include<stdio.h>
#include<unistd.h>
#include"main.h"

// Affiche le bandeau de selection de colonne et la matrice de jeu (applique aussi le jeton dans celle-ci)
void affichage_grille(int pos_jeton_bandeau, int jeton_player, char action_fun)
{
	char grille = ' ';

	printf("|");
	for (int y = 0; y < NOMBRE_COLONNE; y++) {
		if (y == pos_jeton_bandeau) {
			printf("%d|", jeton_player);
		} else {
			printf("%c|", grille);
		}
	}
	printf("\n");

	for (int i = 0; i < NOMBRE_LIGNE; i++) {
		for (int y = 0; y < NOMBRE_COLONNE; y++) {
			if (action_fun == 'v' && i == (5 - jeton_de_colonne[pos_jeton_bandeau]) && y == pos_jeton_bandeau)
			{
				jeton_de_colonne[pos_jeton_bandeau]++;
				grille_matrice[i][y] = jeton_player;
				break;
			}
		}
	}
	printf("\n");
	for (int i = 0; i < NOMBRE_LIGNE; i++)
	{
		printf("|");
		for (int y = 0; y < NOMBRE_COLONNE; y++)
		{
			printf("%d|", grille_matrice[i][y]);
		}
		printf("\n");
	}
	printf("+++++++++++++++\n");

}
