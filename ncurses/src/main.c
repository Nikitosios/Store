#include <ncurses.h>
#include <locale.h>
#include <form.h>

int update_screen (void);

int main (void)
{
	int maxy, maxx;

	/* initialize all */
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	start_color();
	mousemask(ALL_MOUSE_EVENTS, NULL);
	/* main code */
	update_screen();
	/* end program */
	clear();
	getmaxyx(stdscr, maxy, maxx);
	mvprintw(maxy/2, maxx/2-8, "Press any key...");
	getch();
	endwin();
	return 0;
}
