
#ifndef MAIN_H_
#define MAIN_H_

void print_grille(int posx, int posy);
void print_jeton(int posx,int posy,int place,int joueur);
void *thread_affichage(void *arg);

#endif /* MAIN_H_ */
