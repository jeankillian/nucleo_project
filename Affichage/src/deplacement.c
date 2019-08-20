#include<stdio.h>
#include<unistd.h>
#include"main.h"

int deplacement(int pos_jeton_bandeau, int jeu_en_cours)
{
	action = ' ';
	while(jeton_de_colonne[pos_jeton_bandeau] == PLEIN && jeu_en_cours == 1)
	{
		if(jeton_de_colonne[pos_jeton_bandeau] == PLEIN)
		{
			pos_jeton_bandeau ++;
		}
		if (pos_jeton_bandeau >= NOMBRE_COLONNE-1)
		{
			pos_jeton_bandeau = 0;
		}
	}
	sleep(0.25);
	printf("\n");
	printf("q(gauche), d(droite), v(valider): \n");
	scanf("%c", &action);

	if (action == 'q')
	{
		if (pos_jeton_bandeau == 0)
		{
			pos_jeton_bandeau = NOMBRE_COLONNE-1;
		}
		else
			pos_jeton_bandeau--;
		while(jeton_de_colonne[pos_jeton_bandeau] == PLEIN)
			{
				if(jeton_de_colonne[pos_jeton_bandeau] == PLEIN)
				{
					pos_jeton_bandeau --;
				}
			}
	}
	if (action == 'd')
	{
		if (pos_jeton_bandeau >= NOMBRE_COLONNE-1)
		{
			pos_jeton_bandeau = 0;
		}
		else
			pos_jeton_bandeau++;
		while(jeton_de_colonne[pos_jeton_bandeau] == PLEIN)
			{
				if(jeton_de_colonne[pos_jeton_bandeau] == PLEIN)
				{
					pos_jeton_bandeau ++;
				}
			}
	}
	return pos_jeton_bandeau;
}
