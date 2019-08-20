#ifndef CGI_PILE_H
#define CGI_PILE_H

 /*  Structure représentant un élément de la pile. */

        typedef struct pileMessage
        {
                char * valeur;
                struct pileMessage *prec;
        } pileMessage ;

#ifdef __cplusplus
extern "C" {
#endif

 /*  Push empile une valeur sur la pile. */

        void PushM(pileMessage **, char*);


 /*  Pop retire la dernière valeur empilée sur la pile. */

        int PopM(pileMessage **);


 /*  Clear vide la pile. */

        void ClearM(pileMessage **);


 /*  Length retourne le nombre d'éléments de la pile. */

        int LengthM(pileMessage *p);


 /*  Affiche la totalité de la pile en commençant par le sommet. */

        void ViewM(pileMessage *);

#ifdef __cplusplus
}
#endif

#endif
