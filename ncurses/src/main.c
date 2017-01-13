#include <ncurses.h>
#include "header.h"

int parse_mouse (MEVENT event, struct object button);

int main (void)
{	
	short c;
	alarming = true;
	MEVENT event;
	char my_msg[MSG_SIZE];
	char *my_msgP = my_msg;

	/* Initialize curses */
	setlocale(LC_ALL, "");
	initscr();
	cbreak();
	noecho();
	halfdelay(1);
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	start_color();
	refresh();
	
	update_screen();
	short ch[2];
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
			case 31 ... 255:
				ch[0] = c;
				ch[1] = '\0';
				attron(COLOR_PAIR(2));
				addstr(ch);
				attroff(COLOR_PAIR(2));
				break;
		}
	}
	
	getch();
	endwin();
	return 0;
}

int send_message (char *msg)
{
	return 0;
}

int parse_mouse (MEVENT event, struct object button)
{
	if (event.x <= button.ex && event.x >= button.x && event.y <= button.ey && event.y >= button.y)
		return 1;
	return 0;
}

char *msgformat (char *msg)
{
	return 0;
}
