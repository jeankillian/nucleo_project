void print_grille(int posx, int posy)
{
    int lignes=0;
    mvprintw(posx+lignes, posy, "| | | | | | | |");
    mvprintw(posx+lignes+1, posy, "               ");
    while(lignes+2 < 8)
    {
        mvprintw(posx+lignes+2, posy, "| | | | | | | |");
        lignes++;
    }
}

void print_jeton(int posx,int posy,int place,int joueur)
{
    mvprintw(posx, posy, "- - - - - - - -");
    if (joueur == 1){
		mvprintw(4, 25+(place*2-1), "X");
	}
	else{
		mvprintw(4, 25+(place*2-1), "O");
	}
}
