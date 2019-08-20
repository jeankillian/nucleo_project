/*
*****************************************************************************

  File        : main.cpp

  The MIT License (MIT)
  Copyright (c) 2019 STMicroelectronics

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*****************************************************************************
:**/

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include <mqueue.h>
#include <string.h>
#include <sys/types.h>

#include "main.h"



int main()
{
    struct mq_attr attr;

    /* initialize the queue attributes */
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_SIZE;
    attr.mq_curmsgs = 0;

    /* create the message queue */
     mq_jeu = mq_open(QUEUE_JEU, O_CREAT | O_RDONLY | O_NONBLOCK, 0644, &attr);
     mq_aff = mq_open(QUEUE_AFF, O_CREAT | O_RDONLY | O_NONBLOCK, 0644, &attr);
     mq_pup = mq_open(QUEUE_PUP, O_CREAT | O_RDONLY | O_NONBLOCK, 0644, &attr);

     (void)(pthread_create(&threadJeu, NULL, thread_CJeu, NULL));
     (void)(pthread_create(&threadPup, NULL, thread_pupitre, NULL));
     (void)(pthread_create(&threadAff, NULL, thread_affichage, NULL));

     while(1)
         {
         sleep(1);

        // cpt++;
        // mvprintw(14, 2, "la valeur est %d",cpt);
        // refresh();
         }
    clrtoeol();
//    refresh();
//    endwin();
    return 0;
}

void Send_Queue(mqd_t Queue,char Command,char Param1,char Param2,char
Param3,char Param4)
{
    char buffer[MAX_SIZE + 1];

    buffer[0]=Command;
    buffer[1]=Param1;
    buffer[2]=Param2;
    buffer[3]=Param3;
    buffer[4]=Param4;
    mq_send(Queue, buffer, MAX_SIZE, 0);
}
