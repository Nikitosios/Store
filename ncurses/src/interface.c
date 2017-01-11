#include <ncurses.h>

int update_screen (void)
{
	init_pair(1, COLOR_BLACK, COLOR_RED);
	bkgd(COLOR_PAIR(1));
	clear();
	addch(' ' | COLOR_PAIR(1));
	refresh();
	return 0;
}
