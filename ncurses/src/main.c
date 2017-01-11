#include <ncurses.h>
#include <form.h>

int update_screen (void);
FIELD *field[3];

int main (void)
{	
	/* Initialize curses */
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	
	/* Initialize the fields */
	field[0] = new_field(1, 10, 4, 18, 0, 0);
	field[1] = new_field(1, 10, 6, 18, 0, 0);
	field[2] = NULL;

	update_screen();
	
	endwin();
	return 0;
}
