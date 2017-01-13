#include <ncurses.h>
#include "header.h"

int main (void)
{	
	alarming = true;

	/* Initialize curses */
	setlocale(LC_ALL, "");
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
