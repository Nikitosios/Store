#include <form.h>
#include <locale.h>
#include <string.h>

int main (void)
{
	FIELD *field[2];
	FORM *form;
	char buff[256], ch;

	setlocale(LC_ALL, "");
	initscr();
	start_color();
	echo();
	keypad(stdscr, TRUE);
	mousemask(ALL_MOUSE_EVENTS, NULL);
	cbreak();

	field[0] = new_field(LINES/4, COLS/2, LINES-LINES/4, COLS/4, 0, 0);
	field[1] = NULL;

	form = new_form(field);
	post_form(form);
	refresh();

	form_driver(form, REQ_VALIDATION);
	int y, x;
	while ((ch = getch()) != '#') {
		switch (ch) {
			case '\n':
				getyx(stdscr, y, x);
				move(y+1, COLS/4);
				break;
			case '\b':
				getyx(stdscr, y, x);
				mvaddch(y, x-1, ' ');
				move(y, x-1);
				break;
			default:
				form_driver(form, ch);
				form_driver(form, REQ_VALIDATION);
				strcpy(buff, field_buffer(field[0], 0));
				break;
		}
	}
	unpost_form(form);
	free_field(field[0]);
	clear();
	refresh();
	for (int i = 0; i < strlen(buff); i++)
		addch(buff[i]);

	getch();
	endwin();
	return 0;
}
