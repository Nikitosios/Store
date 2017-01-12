#include <form.h>
#include <panel.h>
#include "header.h"

int update_screen (void)
{
	int maxy, maxx;

	init_pair(1, COLOR_BLACK, COLOR_BLUE);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	getmaxyx(stdscr, maxy, maxx);
	msgsend = create_object(0, maxx/8*7, maxy, maxx/8, COLOR_PAIR(1) | A_BOLD);
	msgbox = create_object(maxy/4*3, maxx/8+1, maxy, maxx-maxx/8, COLOR_PAIR(2));
	textbox[0] = new_field(msgbox.y+1, msgbox.x+1, msgbox.h-2, msgbox.w-2, 0, 0);
	refresh();
	return 0;
}

struct object create_object(int y, int x, int h, int w, unsigned int flags)
{
	struct object obj;

	obj.win = newwin(h, w, y, x);
	box(obj.win, 0, 0);
	obj.panel = new_panel(obj.win);
	update_panels();
	doupdate();
	for (int yi = y+1; yi < y+h-1; yi++)
		for (int xi = x+1; xi < x+w-1; xi++)
			mvaddch(yi, xi, ' ' | flags);
	refresh();
	return obj;
}
