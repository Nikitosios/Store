#include <ncurses.h>
#include "header.h"

int main (void)
{	
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	refresh();
	
	update_screen();
	
	getch();
	endwin();
	return 0;
}
