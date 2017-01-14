#include <ncurses.h>
#include "header.h"

#define GO_UP 1
#define GO_DOWN 2
#define GO_LEFT 3
#define GO_RIGHT 4

int parse_mouse (MEVENT event, struct object button);
int msggo (char where);

int main (void)
{	
	short c;
	MEVENT event;

	/* Initialize curses */
	my_msgP = my_msg;
	alarming = true;
	setlocale(LC_ALL, "");
	initscr();
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
				msggo(GO_UP);
				break;
			case KEY_DOWN:
				msggo(GO_DOWN);
				break;
			case KEY_LEFT:
				msggo(GO_LEFT);
				break;
			case KEY_RIGHT:
				msggo(GO_RIGHT);
				break;
			default:
				parse_ch(c);
				break;
		}
	}
	
	getch();
	endwin();
	return 0;
}

int send_message (short *msg)
{
	return 0;
}

int parse_mouse (MEVENT event, struct object button)
{
	if (event.x <= button.ex && event.x >= button.x && event.y <= button.ey && event.y >= button.y)
		return 1;
	return 0;
}

char *msgformat (short *msg)
{
	return 0;
}

int msggo (char where)
{
	char *my_msgPB;

	getyx(stdscr, curY, curX);
/*	
	while (my_msgPB != my_msgP) {
		if 
	}
*/
	return 0;
}
