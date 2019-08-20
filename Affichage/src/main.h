/*
 * main.h
 *
 *  Created on: 16 avr. 2019
 *      Author: killian
 */

#ifndef MAIN_H_
#define MAIN_H_

#define NOMBRE_COLONNE 7
#define NOMBRE_LIGNE 6
#define NB_A_ALIGNER 4
#define PLEIN NOMBRE_LIGNE
#define GRILLE_PLEINE NOMBRE_COLONNE
#define WIN 1
#define DRAW 1
//#define DIAG_GAUCHE
//#define DIAG_DROITE

void affichage_grille(int pos_jeton_bandeau, int jeton_player, char action_fun);
int change_de_joueur(int player, char action_fun);
void init_jeton_de_colonne();
void init_matrice();
int deplacement(int pos_jeton_bandeau, int jeu_en_cours);
int is_winner_horizontal(int player, int pos_jeton_bandeau);
int is_winner_vertical(int player, int pos_jeton_bandeau);
void which_diag(int pos_jeton_bandeau);
int is_winner_diagonal(int player, int pos_jeton_bandeau);
int is_draw();
int is_winner(int player, int pos_jeton_bandeau);

int grille_matrice[NOMBRE_LIGNE][NOMBRE_COLONNE];
int joueur;
int jeton_de_colonne[NOMBRE_COLONNE];
char action;
int diag_gauche;
int diag_droite;

#endif /* MAIN_H_ */
