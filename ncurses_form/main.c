#include <ncurses.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define msleep(msec) Sleep(msec)
#else
#include <unistd.h>
#define msleep(msec) usleep(msec*1000)
#endif

int posx = 5, posy = 0;

int show_all (int a, int b);
int send_message (char *msg);
int show_char (char c);

int main (void)
{
	MEVENT event;
	char message[2000], c;

	posy = LINES/3;
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	cbreak();
	curs_set(0);
	/* start */
	init_pair(1, COLOR_RED, COLOR_GREEN);
	show_all(COLOR_BLUE, COLOR_BLUE);
	while (1) {
		switch (c = getch()) {
			case '\n':
				send_message(message);
				break;
			case KEY_MOUSE:
				if (getmouse(&event) == OK)
					if (event.bstate & BUTTON1_CLICKED) {
						if (event.x >= COLS - COLS / 8)
							send_message(message);
						else if (event.x < 4 && event.y < 4) {
							endwin();
							return 0;
						}
					}
				// if (...) ...;
				break;
			default:
				show_char(c);
				break;
		}
	}
	/* end */
	endwin();
	return 0;
}

int show_all (int a, int b)
{
	init_pair(2, a, b);
	init_pair(3, COLOR_RED, COLOR_RED);
	init_pair(4, COLOR_BLACK, COLOR_RED);
	attrset(COLOR_PAIR(3));
	mvaddstr(0, 0, "   ");
	mvaddstr(1, 0, "   ");
	mvaddstr(2, 0, "   ");
	attrset(A_NORMAL);
	mvaddch(1, 1, 'X' | COLOR_PAIR(4) | A_BOLD);
	for (int l = 0; l < LINES; l++)
		for (int c = COLS - COLS / 8 - 1; c < COLS; c++)
			mvaddch(l, c, ' ' | COLOR_PAIR(2));
	refresh();
	return 0;
}

int send_message (char *msg)
{
	show_all(COLOR_RED, COLOR_WHITE);
	msleep(100);
	show_all(COLOR_BLUE, COLOR_BLUE);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	attron(COLOR_PAIR(5));
	mvaddstr(LINES/2, COLS/32, msg);
	attroff(COLOR_PAIR(5));
	refresh();
	return 0;
}

int show_char (char c)
{
	if (posx >= COLS-(COLS/8+1)) {
		posy++;
		posx = 0;
	}
	init_pair(6, COLOR_BLACK, COLOR_BLUE);
	mvaddch(posy, posx, c | COLOR_PAIR(6));
	refresh();
	return 0;
}
