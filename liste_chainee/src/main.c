#include <stdlib.h>   /* Pour la fonction system. */
#include <stdio.h>
#include "Pile.h"

int main()
{

        pileMessage *MaPile = NULL;   /* Impératif de l'initialiser à NULL */

        PushM(&MaPile, "et on ne connait pas à l’avance quelle est la taille des messages à stocker");
        PushM(&MaPile, "les messages sont de tailles variables");
        PushM(&MaPile, "ceci est une pile texte");
//        PushM(&MaPile, 12);      /* Empile 4 valeurs. */

        puts("Affichage de la pile :");
        ViewM(MaPile);       /* Affiche la totalité de la pile. */
        puts("------");

        printf("Nb d'elements : %d\n",LengthM(MaPile));
        puts("------");

        puts("Deux valeurs soutirees de la pile :");
        printf("%s\n",PopM(&MaPile));   /* Affiche deux valeurs */
        printf("%s\n",PopM(&MaPile));   /* soutirées de la pile. */
        puts("------");

        puts("Affichage de la pile :");
        ViewM(MaPile);       /* Affiche la totalité de la pile. */
        puts("------");

        ClearM(&MaPile);        /* Vide la pile. */

        PushM(&MaPile, "hello!");      /* Empile une valeur. */

        puts("Affichage de la pile apres vidage et ajout d'une valeur :");
        ViewM(MaPile);       /* Affiche la totalité de la pile. */
        puts("------\n");

        ClearM(&MaPile);    /* Vider la pile avant de quitter. */

#ifdef _WIN32
        system("PAUSE");  /* Pour la console Windows. */
#endif
        return 0;
}
