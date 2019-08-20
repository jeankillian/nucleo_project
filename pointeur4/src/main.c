#include<stdio.h>
#include<stdlib.h>

int main(void){

	int* pointeur_nombre = NULL;
	int nombre = 6;
	int compteur_nb_sup_egal_10 = 0;

	pointeur_nombre = malloc(nombre * sizeof(int));	// On alloue la mémoire
	if (pointeur_nombre == NULL)
	{
		exit(0);
	}
	//------------------
	for (int i = 0; i<nombre; i++)
	{
		printf("Nombre n°%d: \n", i);
		scanf("%d", &pointeur_nombre[i]);
	}

	for (int i = 0; i<nombre; i++)
	{
		if (pointeur_nombre[i] >= 10)
		{
			compteur_nb_sup_egal_10 ++;
		}
	}
	printf("Il y a %d nombre supérieur ou égal à 10: \n", compteur_nb_sup_egal_10);
	//------------------
	free(pointeur_nombre);	//On a plus besoin de la mémoire

	return 0;
}
