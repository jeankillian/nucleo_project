/*
 * main.h
 *
 *  Created on: 15 mai 2019
 *      Author: killian
 */

#ifndef MAIN_H_
#define MAIN_H_

#define WINDOW stdscr
#define QUEUE_JEU  "/queuejeu"
#define QUEUE_PUP  "/queuepup"
#define QUEUE_AFF  "/queueaff"
#define MAX_SIZE    1024
#define MSG_STOP "exit"

int JetonPosCol,JetonPosLig;
int Joueur;

//-------------------------------------------------
//               COMMANDES DE PUPITRE
//-------------------------------------------------
#define CMD_PUPITRE   0x10
#define P_FLECHEG1    0x10
#define P_FLECHED1    0x11
#define P_FLECHEH1    0x12
#define P_FLECHEB1    0x13
#define P_START1J1    0x14
#define P_STOPJ1      0x15

#define P_FLECHEG2    0x16
#define P_FLECHED2    0x17
#define P_FLECHEH2    0x18
#define P_FLECHEB2    0x19
#define P_START1J2    0x20
#define P_STOPJ2      0x21

#define CMD_JEU       0x20

#define CMD_AFFICHAGE 0x30
#define A_DPL_JETON_G 0x10
#define A_DPL_JETON_D 0x11
#define A_AFF_JETON   0x12



pthread_t threadPup;
pthread_t threadAff;
pthread_t threadJeu;

void *thread_pupitre(void *arg);
void *thread_affichage(void *arg);
void *thread_CJeu(void *arg);

mqd_t mq_jeu,mq_aff,mq_pup;
int Key;



#endif /* MAIN_H_ */
