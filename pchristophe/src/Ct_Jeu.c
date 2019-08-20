/*
 *    sequenceur de jeu
 */
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <mqueue.h>
#include <string.h>
#include <sys/types.h>

#include "main.h"

char Puissance4[6][7];

void *thread_CJeu(void *arg)
{
    char buffer[MAX_SIZE + 1];
    ssize_t bytes_read;
    mqd_t mq;
    bool JeuStarted;
    char TourJoueur;


    /* open the mail queue */
    mq = mq_open(QUEUE_AFF, O_WRONLY);
    JeuStarted = false;

    while(1)
    {
        sleep(0.1);
        memset(buffer, 0x00, sizeof(buffer));
        bytes_read = mq_receive(mq_jeu, buffer, MAX_SIZE, NULL);


    }
}
