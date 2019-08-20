#include<stdio.h>
#include<unistd.h>
#include"main.h"

//-----------------------------------------

// fonctions de vérification de victoire horizontale, verticale et diagonal et reourne le résultat

int is_winner_horizontal(int player, int pos_jeton_bandeau) {
	int resultat = 0;
	int jeton_aligne;
	int alignement_possible = NOMBRE_COLONNE - NB_A_ALIGNER + 1;
	int line = (NOMBRE_LIGNE) - jeton_de_colonne[NOMBRE_COLONNE];

	for (int y = 0; y < alignement_possible; y++) {
		jeton_aligne = 0;
		if (grille_matrice[line][y] == player) {
			jeton_aligne++;
			for (int j = 1; j < NB_A_ALIGNER; j++) {
				if (grille_matrice[line][y + j] == player) {
					jeton_aligne++;
				}
			}
		}
		if (jeton_aligne == NB_A_ALIGNER) {
			printf("Player %d horizontal win !\n", player);
			resultat = WIN;
		}
	}

	return resultat;
}
//-----------------------------------------
int is_winner_vertical(int player, int pos_jeton_bandeau) {
	int resultat = 0;
	int jeton_aligne;
	int alignement_possible = NOMBRE_LIGNE - NB_A_ALIGNER + 1;

	for (int y = 0; y < alignement_possible; y++) {
		jeton_aligne = 0;
		if (grille_matrice[y][pos_jeton_bandeau] == player) {
			jeton_aligne++;
			for (int j = 1; j < NB_A_ALIGNER; j++) {
				if (grille_matrice[y + j][pos_jeton_bandeau] == player) {
					jeton_aligne++;
				}
			}
		}
		if (jeton_aligne == NB_A_ALIGNER) {
			printf("Player %d vertical win !\n", player);
			resultat = WIN;
			;
		}
	}

	return resultat;
}
//-----------------------------------------
int is_winner_diagonal(int player, int pos_jeton_bandeau)
{
	int resultat = 0;
	int jeton_aligne;

	for (int i = 0; i < NOMBRE_LIGNE; i++)
	{
		for (int y = 0; y < NOMBRE_COLONNE; y++)
		{
			jeton_aligne = 0;
			if(grille_matrice[i][y] == player)
			{
				jeton_aligne ++;
				for(int j = 1; j < NB_A_ALIGNER; j++)
				{
					if (grille_matrice[i+j][y+j] == player)
					{
						jeton_aligne ++;
					}
				}
			}
			if(jeton_aligne == NB_A_ALIGNER)
			{
				printf("Player %d diagonal win !\n", player);
				resultat = WIN;
			}
		}
	}
	for (int i = 0; i < NOMBRE_LIGNE; i++)
	{
		for (int y = NOMBRE_COLONNE; y > 0; y--)
		{
			jeton_aligne = 0;
			if(grille_matrice[i][y] == player)
			{
				jeton_aligne ++;
				for(int j = 1; j < NB_A_ALIGNER; j++)
				{
					if (grille_matrice[i+j][y-j] == player)
					{
						jeton_aligne ++;
					}
				}
			}
			if(jeton_aligne == NB_A_ALIGNER)
			{
				printf("Player %d diagonal win !\n", player);
				resultat = WIN;
			}
		}
	}
	return resultat;
}
//-----------------------------------------
int is_draw() {
	int result = 0;
	int colonne_pleine;
	colonne_pleine = 0;
	for (int i = 0; i < NOMBRE_COLONNE; i++) {
		if (jeton_de_colonne[i] == PLEIN) {
			colonne_pleine++;
		}
	}
	if (colonne_pleine == GRILLE_PLEINE) {
		printf("DRAW !\n");
		result = 1;
	}
	return result;
}
//-----------------------------------------
int is_winner(int player, int pos_jeton_bandeau) {
	int resultat = 0;
	if (is_winner_horizontal(player, pos_jeton_bandeau)) {
		resultat = WIN;
	}
	if (is_winner_vertical(player, pos_jeton_bandeau)) {
		resultat = WIN;
	}
	if (is_winner_diagonal(player, pos_jeton_bandeau)) {
		resultat = WIN;
	}
	if (is_draw())
		resultat = DRAW;
	return resultat;
}
