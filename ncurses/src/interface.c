#include "header.h"
#include "interface.h"

int update_screen (void)
{
	init_pair(1, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_BLACK, COLOR_BLUE);
	init_pair(4, COLOR_BLACK, COLOR_RED);
	bkgd(COLOR_PAIR(1));
	clear();
	refresh();
	msgbox = create_object(LINES/4, (COLS-BORD_WIDTH)/8*7+1, LINES - LINES/4, BORD_WIDTH,
			COLOR_PAIR(2), true);
	msgsend = create_object(msgbox.h, COLS - msgbox.w - BORD_WIDTH, msgbox.y, msgbox.ex+1,
			COLOR_PAIR(3), false);
	attron(COLOR_PAIR(3));
	mvaddstr(msgsend.cy, msgsend.cx-1, ">>>");
	attroff(COLOR_PAIR(3));
	filesend = create_object(msgbox.h, BORD_WIDTH, msgbox.y, 0, COLOR_PAIR(3), false);
	mvaddch(filesend.cy, filesend.cx, '#' | COLOR_PAIR(3));
#define A 5
	exit_b = create_object(A-A/2, A, 0, COLS-A, COLOR_PAIR(4), false);
#undef A
	mvaddch(exit_b.cy, exit_b.cx, 'X' | COLOR_PAIR(4));
	refresh();
	move(msgbox.y+1, msgbox.x+1);
	return 0;
}

struct object create_object (int h, int w, int y, int x, unsigned int flags, bool form)
{
	struct object obj;

	obj.h = h;
	obj.w = w;
	obj.y = y;
	obj.x = x;
	obj.ey = obj.y + obj.h - 1;
	obj.ex = obj.x + obj.w - 1;
	obj.cy = obj.h/2 + obj.y;
	obj.cx = obj.w/2 + obj.x;
	obj.win = create_newwin(obj.h, obj.w, obj.y, obj.x, flags);
	for (int yi = obj.y+1; yi < obj.ey; yi++)
		for (int xi = obj.x+1; xi < obj.ex; xi++)
			mvaddch(yi, xi, ' ' | flags);
	return obj;
}

WINDOW *create_newwin (int h, int w, int y, int x, unsigned int cp)
{
	WINDOW *win;

	win = newwin(h, w, y, x);
	wborder(win, '|' | cp, '|' | cp, '-' | cp, '-' | cp, '+' | cp, '+' | cp, '+' | cp, '+' | cp);
	refresh();
	wrefresh(win);
	return win;
}

void destroy_win (WINDOW *win, unsigned int cp)
{
	wborder(win, ' ' | cp, ' ' | cp, ' ' | cp, ' ' | cp, ' ' | cp, ' ' | cp, ' ' | cp, ' ' | cp);
	wrefresh(win);
	delwin(win);
	return;
}
