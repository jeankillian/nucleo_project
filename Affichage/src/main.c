#include<stdio.h>
#include<unistd.h>
#include"main.h"
/*
 *Récupère et modifie l'affichage de la position du jeton en fonction des boutons déplacements
 *En modifie la couleur selon le joueur (1 ou 2)
 */
int main(void)
{
	int pos_du_jeton = 3;
	int jeu_en_cours = 1;

	joueur = 1;
	init_matrice();
	init_jeton_de_colonne();

	while (jeu_en_cours)
	{
		sleep(0.25);
		affichage_grille(pos_du_jeton, joueur, action);
		if (is_winner(joueur,pos_du_jeton))
			jeu_en_cours = 0;
		joueur = change_de_joueur(joueur, action);
		pos_du_jeton = deplacement(pos_du_jeton, jeu_en_cours);
	}
	return 0;
}
