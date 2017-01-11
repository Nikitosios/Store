#include <ncurses.h>
#include <locale.h>

int update_screen (void);

int main (void)
{
	setlocale(LC_ALL, "");
	initscr();
	mousemask(ALL_MOUSE_EVENTS, NULL);
	keypad(stdscr, TRUE);
	cbreak();
	start_color();
	getch();
	update_screen();
	getch();
	endwin();
	return 0;
}
