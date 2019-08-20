/*
 *  Affichage
 */

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <mqueue.h>
#include <string.h>
#include <sys/types.h>

#include "main.h"

#define POSX 4
#define POSY 25

void print_grille(void)
{
    int lignes=0;

    mvprintw(POSX+lignes, POSY, "| | | | | | | |");
    mvprintw(POSX+lignes+1, POSY, "               ");

    while(lignes+2 < 8)
    {
        mvprintw(POSX+lignes+2, POSY, "| | | | | | | |");
        lignes++;
    }
}


void print_jeton_ds_grille(char ligne, char col,int joueur)
{
    if (joueur == 1)
    mvprintw(POSX+(ligne-1),POSY+(col*2-1), "X");
    if (joueur == 2)
    mvprintw(POSX+(ligne-1),POSY+(col*2-1), "O");
}


void *thread_affichage(void *arg)
{
    char buffer[MAX_SIZE + 1];
    ssize_t bytes_read;


    initscr(); /* init de ncurses */
    clear();
    noecho();   /* pour masquer l'affichage du buffer stdin dans la console */
    cbreak();    /* Line buffering disabled. pass on everything */
    mvprintw(0, 0, "Commencez à jouer !! F1 :start");
//    refresh();

    print_grille();
    sleep(0.1);
    while(1)
    {
        memset(buffer, 0x00, sizeof(buffer));
        bytes_read = mq_receive(mq_aff, buffer, MAX_SIZE, NULL);

        if(bytes_read >= 0)
        {
            if(buffer[0] == CMD_AFFICHAGE)
            {
                if(buffer[1] == A_AFF_JETON)
                {
                     mvprintw(POSX,POSY, "| | | | | | | |");
                    print_jeton_ds_grille(8-buffer[4],buffer[3],buffer[2]);
                }
            }
         }
        mvprintw(1, 0,"KEY %d",Key);
        refresh();
     }
}
