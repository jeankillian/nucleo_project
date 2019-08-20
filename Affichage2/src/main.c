#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <pthread.h>
#include "main.h"

#define WINDOW stdscr

static int jetonPos;
static int Joueur;
static int c;
static int cpt=0;


int main()
{
	pthread_t thread1;


    jetonPos = 4;
    Joueur =1;

    pthread_create (&thread1, NULL, thread_affichage, (void*)NULL);

	scrollok(WINDOW, TRUE);
    nodelay(WINDOW, TRUE);
    while(1)
    {
    	c = wgetch(WINDOW);
        //cpt++;
       // sleep(0.5);
        fflush(stdin);

        switch(c)
        {    case KEY_UP:
                break;
            case KEY_DOWN:
                break;
            case KEY_ENTER:   //enter
                break;
            case 68:
                if(jetonPos>1)jetonPos--;
                else jetonPos = 7;
                break;
            case 67:
                if(jetonPos<7)jetonPos++;
                else jetonPos = 1;

                break;
            default:
                mvprintw(24, 0, "Character pressed is = %3d Hopefully it can be printed as '%c'", c, c);
                refresh();
                break;
        }
    }
    pthread_join (thread1, NULL);
    clrtoeol();
    refresh();    endwin();

    return 0;
}

void *thread_affichage(void *arg)
{
	initscr(); /* init de ncurses */
	clear();
	noecho();   /* pour masquer l'affichage du buffer stdin dans la console */
	cbreak();    /* Line buffering disabled. pass on everything */
	sleep(0.5);

	int ljetonPos;
	int clign =0;

	print_grille(4, 25);
	print_jeton(4,25,jetonPos,Joueur);
	mvprintw(0, 0, "commencez à jouer !!");
	refresh();
	while(1){
		cpt++;
		if(jetonPos>=1 && jetonPos<=7){
			ljetonPos = jetonPos;
		}
		else
		{
			ljetonPos=1;
		}
		mvprintw(14, 2, "la valeur est %d",c);
		mvprintw(15, 2, " %d",cpt);

		if (Joueur == 1){
			if (clign ==1)
			{
				mvprintw(4, 25+(ljetonPos*2-1), "X");
			}
			if (clign ==0)
			{
				mvprintw(4, 25, "- - - - - - - -");
			}
		}
	 	else{
	 		mvprintw(4, 25+(ljetonPos*2-1), "O");
	 		sleep(1);
	 		mvprintw(4, 25+(ljetonPos*2-1), " ");
	 	}
		refresh();
		sleep(1);
		if(clign==0)clign=1;
		else clign =0;
	}
    pthread_exit(NULL);
}
