#include <ncurses.h>
#include <locale.h>

int main (void)
{
	setlocale(LC_ALL, "");
	initscr();
	char msg[] = "[♪] так вот";
	printw("%s", msg);
	getch();
	endwin();
	return 0;
}
