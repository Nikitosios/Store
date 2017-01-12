#include <form.h>
#include <panel.h>
#include "header.h"

int update_screen (void)
{
	int maxy, maxx;

	init_pair(1, COLOR_BLACK, COLOR_BLUE);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_RED);
	getmaxyx(stdscr, maxy, maxx);
	clear();
	msgbox = create_object(maxy/4*3, maxx/8+1, maxy/4+1, maxx-maxx/8*2-3, COLOR_PAIR(2));
	msgsend = create_object(msgbox.y, maxx/8*7, msgbox.h, maxx/8, COLOR_PAIR(1));
	mvaddch(msgsend.cy, msgsend.cx, '>' | COLOR_PAIR(1));
	filesend = create_object(msgbox.y, 0, msgbox.h, maxx/8+1, COLOR_PAIR(1));
	mvaddch(filesend.cy, filesend.cx, '#' | COLOR_PAIR(1));
#define A 10
	exit_b = create_object(0, maxx-A, A-A/2, A, COLOR_PAIR(3));
	mvaddch(exit_b.cy, exit_b.cx, 'X' | COLOR_PAIR(3));
#undef A
	textbox[0] = new_field(msgbox.y+1, msgbox.x+1, msgbox.h-2, msgbox.w-2, 0, 0);
	refresh();
	move(msgbox.y+1, msgbox.x+1);
	return 0;
}

struct object create_object(int y, int x, int h, int w, unsigned int flags)
{
	struct object obj;

	obj.win = newwin(h, w, y, x);
	obj.y = y;
	obj.x = x;
	obj.h = h;
	obj.w = w;
	obj.ey = y+h-1;
	obj.ex = x+w-1;
	obj.cy = y+h/2;
	obj.cx = x+w/2;
	box(obj.win, 0, 0);
	obj.panel = new_panel(obj.win);
	update_panels();
	doupdate();
	for (int yi = y+1; yi < y+h-1; yi++)
		for (int xi = x+1; xi < x+w-1; xi++)
			mvaddch(yi, xi, ' ' | flags);
	wrefresh(obj.win);
	refresh();
	return obj;
}
