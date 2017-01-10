#include <ncurses.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define msleep(msec) Sleep(msec)
#else
#include <unistd.h>
#define msleep(msec) usleep(msec*1000)
#endif

int show_all (int a, int b);
int send_message (char *msg);
int show_char (char c);
int msgbox_refresh (void);

typedef struct object {
	int w, h, x, y;
} object;

struct object create_object(int x, int y, int w, int h)
{
	struct object obj;

	obj.x = x;
	obj.y = y;
	obj.w = w;
	obj.h = h;
	return obj;
}

int posx = 0, posy = 0;
struct object msgbox;
struct object msgsend;
struct object sendfile;
struct object button_exit;

int main (void)
{
	MEVENT event;
	char message[2000], c;

	posy = LINES/3*2;
	initscr();
	noecho();
	start_color();
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	cbreak();
	/* start */
	init_pair(1, COLOR_RED, COLOR_GREEN);
	show_all(COLOR_BLUE, COLOR_BLUE);
	move(posy+1+LINES/4*3, posx+6);
	while (1) {
		switch (c = getch()) {
			case '\n':
				posx = 0;
				posy++;
				break;
			case KEY_BACKSPACE:
				init_pair(7, COLOR_BLACK, COLOR_WHITE);
				if(posx - 1 >= 0) {
					mvaddch(posy + msgbox.y, posx + msgbox.x, ' ' | COLOR_PAIR(7));
					posx--;
					move(posy + 1 + msgbox.y, posx + 1 + msgbox.x);
				} else if(posy - 1 >= 0) {
					mvaddch(posy - 1 + msgbox.y, posx + msgbox.x, ' ' | COLOR_PAIR(7));
					posx = 0;
					posy--;
					move(posy + 1 + msgbox.y, posx + 1 + msgbox.x);
				}
				break;
			case KEY_MOUSE:
				if (getmouse(&event) == OK)
					if (event.bstate & BUTTON1_CLICKED) {
						if (event.x >= msgsend.x && event.x <= msgsend.x + msgsend.w && event.y >= msgsend.y && event.y <= msgsend.h + msgsend.y)
							send_message(message);
						else if (event.x >= msgbox.x && event.x <= msgbox.w + msgbox.x && event.y >= msgbox.y && event.y <= msgbox.y + msgbox.h) {
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
	init_pair(9, COLOR_BLACK, COLOR_BLUE);
	init_pair(11, COLOR_BLACK, COLOR_WHITE);
	init_pair(12, COLOR_WHITE, COLOR_BLUE);
	attrset(COLOR_PAIR(3));
	button_exit = create_object(COLS/8*7-5, 0, 5, 3);
	for (int i = button_exit.y; i < button_exit.h + button_exit.y; i++)
		for (int it = button_exit.x; it < button_exit.w + button_exit.x; it++)
			mvaddch(i, it, ' ');
	attrset(A_NORMAL);
	mvaddch(button_exit.y + button_exit.h/2, button_exit.x + button_exit.w/2, 'X' | COLOR_PAIR(4) | A_BOLD);
	msgsend = create_object(COLS/8*7, 0, COLS/8, LINES);
	init_pair(8, COLOR_BLUE, COLOR_BLUE);
	for (int i = msgsend.x; i <= msgsend.x + msgsend.w; i++)
		for (int it = msgsend.y; it <= msgsend.y + msgsend.h; it++)
			mvaddch(it, i, ' ' | COLOR_PAIR(8));
	msgbox = create_object(5, LINES/4*3, COLS-6-COLS/8, LINES/4+1);
	init_pair(7, COLOR_BLACK, COLOR_WHITE);
	for (int i = msgbox.x; i < msgbox.x + msgbox.w; i++)
		for (int it = msgbox.y; it < msgbox.y + msgbox.h; it++)
			mvaddch(it, i, ' ' | COLOR_PAIR(7));
	init_pair(7, COLOR_BLACK, COLOR_WHITE);
	for (int i = msgbox.y; i < msgbox.h + msgbox.y; i++)
		mvaddch(i, msgbox.x, '|' | A_BOLD | COLOR_PAIR(7));
	for (int i = msgbox.y; i < msgbox.y + msgbox.h; i++)
		mvaddch(i, msgbox.x + msgbox.w, '|' | A_BOLD | COLOR_PAIR(7));
	sendfile = create_object(0, msgbox.y, 5, LINES - msgbox.y);
	for (int i = sendfile.x; i < sendfile.x + sendfile.w; i++)
		for (int it = sendfile.y; it <= sendfile.y + sendfile.h; it++)
			mvaddch(it, i, ' ' | A_BOLD | COLOR_PAIR(12));
	mvaddch(sendfile.y+sendfile.h/2, sendfile.w/2+sendfile.x, '#' | COLOR_PAIR(9) | A_BOLD);
	for (int i = 0; i < msgsend.x; i++)
		mvaddch(msgbox.y, i, '-' | COLOR_PAIR(11) | A_BOLD);
	for (int i = 0; i < msgsend.x; i++)
		mvaddch(LINES-1, i, '-' | COLOR_PAIR(11) | A_BOLD);
	mvaddch(msgbox.y, msgbox.x, 192 | COLOR_PAIR(11) | A_BOLD);
	mvaddch(LINES-1, msgbox.x, 218 | COLOR_PAIR(11) | A_BOLD);
	move (LINES/2, COLS/2);
	addch(218 | A_NORMAL);
	for (int i = 0; i < msgbox.x; i++) {
		mvaddch(msgbox.y, i, '-' | COLOR_PAIR(12));
		mvaddch(LINES-1, i, '-' | COLOR_PAIR(12));
	}
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
	if (posx+2+msgbox.x >= COLS-(COLS/8+1)) {
		posy++;
		posx = 0;
	}
	init_pair(10, COLOR_BLACK, COLOR_WHITE);
	mvaddch(posy+msgbox.y+1, posx+msgbox.x+1, c | COLOR_PAIR(10));
	posx++;
	move(posy + msgbox.y + 1, posx + 1 + msgbox.x);
	refresh();
	return 0;
}
