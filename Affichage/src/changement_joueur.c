#include<stdio.h>
#include<unistd.h>
#include"main.h"

int change_de_joueur(int player, char action_fun)
{
	if (action_fun == 'v')
	{

		if(player == 1)
		{
			player = 2;
		}
		else if(player == 2)
		{
			player = 1;
		}
	}

	return player;
}
