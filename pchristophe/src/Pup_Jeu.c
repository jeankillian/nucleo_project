/*
 *    Pupitre
 */

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <mqueue.h>
#include <string.h>
#include <sys/types.h>

#include "main.h"

void *thread_pupitre(void *arg)
{
    mqd_t mq;

    /* open the mail queue */
    mq = mq_open(QUEUE_JEU, O_WRONLY);

    scrollok(WINDOW, TRUE);
    nodelay(WINDOW, TRUE);
    keypad(WINDOW, TRUE);

    while(1)
    {    Key = wgetch(WINDOW);
        fflush(stdin);


        sleep(0.05);
        refresh();
        switch(Key)
        {
            case 80://F1
                Send_Queue(mq,CMD_PUPITRE,P_START1J1,0,0,0);
                break;
            case 81://F2
                Send_Queue(mq,CMD_PUPITRE,P_STOPJ1,0,0,0);
                break;
            case 65://fleche haut
                Send_Queue(mq,CMD_PUPITRE,P_FLECHEH1,0,0,0);
                break;
            case 66://fleche bas
                Send_Queue(mq,CMD_PUPITRE,P_FLECHEB1,0,0,0);
                break;
            case 67:
                Send_Queue(mq,CMD_PUPITRE,P_FLECHED1,0,0,0);
                break;
            case 68:
                Send_Queue(mq,CMD_PUPITRE,P_FLECHEG1,0,0,0);
                break;

            case 119://W
                Send_Queue(mq,CMD_PUPITRE,P_START1J2,0,0,0);
                break;
            case 99: //C
                Send_Queue(mq,CMD_PUPITRE,P_STOPJ2,0,0,0);
                break;
            case 101: //E
                Send_Queue(mq,CMD_PUPITRE,P_FLECHEH2,0,0,0);
                break;
            case 120: //X

                Send_Queue(mq,CMD_PUPITRE,P_FLECHEB2,0,0,0);
                break;
            case 115: //S
                Send_Queue(mq,CMD_PUPITRE,P_FLECHEG2,0,0,0);
                break;
            case 102: //F
                Send_Queue(mq,CMD_PUPITRE,P_FLECHED2,0,0,0);
                break;

            default:

                break;
        }
    }
}
