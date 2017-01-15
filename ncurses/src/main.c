#define _DEBUG

#include <ncurses.h>
#include "header.h"

#define GO_UP 1
#define GO_DOWN 2
#define GO_LEFT 3
#define GO_RIGHT 4

int parse_mouse (MEVENT event, struct object button);

int main (void)
{	
	int c;
	MEVENT event;

	/* Initialize curses */
	my_msgEP = my_msgP = my_msg;
	alarming = true;
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	start_color();
	refresh();
	
	update_screen();
	move(msgbox.y+1, msgbox.x+1);
	while (1) {
		switch (c = getch()) {
			case KEY_MOUSE:
				if (getmouse(&event) == OK)
					if (event.bstate & 
							(BUTTON1_CLICKED | BUTTON2_CLICKED | BUTTON3_CLICKED | BUTTON4_CLICKED)) {
						if (parse_mouse(event, alarm_b)) {
							alarming = alarming ? false : true;
							update_screen();
						}
						if (parse_mouse(event, msgsend)) {
							show_message(my_msg, true);
							update_screen();
						}
					}
				break;
			case KEY_UP:
				/* сделать перемещение вверх-вниз и подредактировать файл */
				break;
			case KEY_DOWN:
				/* parse_ch.c, чтобы корректно вставлялись и удалялись символы */
				break;
			case KEY_LEFT:
				if (my_msgP > my_msg)
					--my_msgP;
				update_screen();
				break;
			case KEY_RIGHT:
				if (my_msgP < my_msgEP)
					++my_msgP;
				update_screen();
				break;
			default:
				if (c != ERR)
					parse_ch(c);
				break;
		}
	}

	getch();
	endwin();
	return 0;
}

int send_message (unsigned char *msg)
{
	return 0;
}

char *msgformat (unsigned char *msg)
{
	return 0;
}

int parse_mouse (MEVENT event, struct object button)
{
	if (event.x <= button.ex && event.x >= button.x && event.y <= button.ey && event.y >= button.y)
		return 1;
	return 0;
}

