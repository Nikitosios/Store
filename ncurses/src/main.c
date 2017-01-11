#include <ncurses.h>
#include "header.h"

int update_screen (void);

int main (void)
{	
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	
	update_screen();
	
	getch();
	endwin();
	return 0;
}
