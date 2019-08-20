#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Pile.h"

/*************************************************************************/

void PushM(pileMessage **p, char * Val)
{
		char* Texte;
		Texte = (char *) malloc(strlen(Val)+1);
		strcpy(Texte, Val);
        pileMessage *element = malloc(sizeof(pileMessage));

        if(!element) exit(EXIT_FAILURE);     /* Si l'allocation a échoué. */
        element->valeur = Val;
        element->prec = *p;
        *p = element;       /* Le pointeur pointe sur le dernier élément. */
}
/*************************************************************************/

int PopM(pileMessage **p)
{
        char * Val;
        pileMessage *tmp;
        if(!*p) return -1;     /* Retourne -1 si la pile est vide. */
        tmp = (*p)->prec;
        Val = (*p)->valeur;
//        free(*Val);
        free(*p);
        *p = tmp;       /* Le pointeur pointe sur le dernier élément. */
        return *Val;     /* Retourne la valeur soutirée de la pile. */
}

/*************************************************************************/

void ClearM(pileMessage **p)
{
        pileMessage *tmp;
        while(*p)
          {
             tmp = (*p)->prec;
             free(*p);
             *p = tmp;
          }
}
/*************************************************************************/

int LengthM(pileMessage *p)
{
        int n=0;
        while(p)
          {
              n++;
              p = p->prec;
          }
        return n;
}

/*************************************************************************/

void ViewM(pileMessage *p)
{
        while(p)
          {
             printf("%s\n",p->valeur);
             p = p->prec;
          }
}
