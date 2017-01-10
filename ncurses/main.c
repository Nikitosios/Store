#include <ncurses.h>
#include <string.h>
#include <locale.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#define msleep(msec) Sleep(msec)
#else
#include <unistd.h>
#define msleep(msec) usleep(msec*1000)
#endif

const int arr[6] = { A_NORMAL, A_STANDOUT, A_UNDERLINE, A_BLINK, A_DIM, A_BOLD };
const char items[4][9] = {
	"Continue",
	"Dance",
	"Clear",
	"Exit"
};

void dance (void);

int main (void)
{
	char c, o = 0;
	int y, x;

	setlocale(LC_ALL, "");
	initscr();
	raw();
	noecho();
	while (1) {
		printw("To exit, press Q.\n");
		refresh();
		c = getch();
		if (c == 'Q')
			break;
	}
	halfdelay(50);
	printw("Wait 5 seconds or press any key...\n");
	refresh();
	getch();
	for (int i = 65; i < 90; i++) { addch(i | arr[(int) o]);
		refresh();
		if (o++ == 6)
			o = 0;
	}
	addch('\n');
	refresh();
	halfdelay(200);
	getch();
	curs_set(0);
	const int ch = '+' | A_BOLD | A_BLINK | A_STANDOUT;
	const char *mesg = "Press any key...";
	x = 40;             /* A_NORMAL       - обычный режим */
	y = 3;              /* A_STANDOUT     - самое яркое выделение из всех возможных */
	mvaddch(y, x, ch);  /* A_UNDERLINE    - подчёркивание */
	x = 60;             /* A_BLINK        - мигание */
	mvaddch(y, x, ch);  /* A_DIM          - тусклый символ */
	y = 13;             /* A_BOLD         - выделение жирным шрифтом */
	mvaddch(y, x, ch);  /* A_REVERSE      - обратное изображение */
	x = 40;             /* A_ALTCHARSET   - ильпользовать альтернативную таблицу символов */
	move(y, x);         /* A_INVIS        - невидимый режим */
	waddch(stdscr, ch); /* A_PROTECT      - режим защиты */
	refresh();          /* A_CHARTEXT     - маска для действующих символов */
	getch();            /* A_COLOR        - маска для цвета */
	int row, col;       /* COLOR_PAIR(n)  - установка цветовой палитры n */
	halfdelay(3);       /* PAIR_NUMBER(a) - получение цветовой палитры, лежащей в атрибуте a */
	while (1) {
		clear();
		row = LINES;
		col = COLS;
		mvwprintw(stdscr, row / 2, (col - strlen(mesg)) / 2, "%s", mesg);
		mvwprintw(stdscr, row - 1, 0, "The number of rows - %d and columns - %d\n", row, col);
		refresh();
		if (getch() != ERR)
			break;
	}
	unsigned char choice = 0;
	keypad(stdscr, 1);
	while (1) {
		clear();
		for (int i = 0; i < 4; i++) {
			if (i == choice)
				addch('>');
			else
				addch(' ');
			printw("%s\n", items[i]);
		}
		switch (getch()) {
			case KEY_UP:
				if (choice)
					choice--;
				break;
			case KEY_DOWN:
				if (choice != 3)
					choice++;
				break;
			case '\n':
				mvprintw(LINES/2, COLS/2-3, "chosen");
				msleep(1000);
				switch (choice) {
					case 3:
						return 0;
						break;
					case 2:
						clear();
						mvprintw(LINES / 2, COLS / 2 - 2, "Чисто");
						refresh();
						msleep(2000);
						clear();
						break;
					case 1:
						dance();
						break;
					case 0:
						break;
				}
				break;
		}
	}
	clear();
	mvprintw(row/2, col/2-11, "Press any key to exit.");
	refresh();
	halfdelay(200);
	getch();
	endwin();
	return 0;
}

void dance (void)
{
	signed char f = 0, l = 0;
	const char *msg = "Ты коченный даун )00))0)))00)))";

	clear();
	setlocale(LC_ALL, "");
	halfdelay(5);
	while (1) {
		for (int i = 0; i < strlen(msg); i++) {
			if (getch() == '\n')
				return;
			mvprintw(LINES/2-1, COLS/8-1, "   ");
			mvprintw(LINES/2-1, COLS - COLS/8 - 2, "      ");
			move(LINES/2, COLS/2 - strlen(msg) / 2 + i);
			if (f == 0) {
				addch(msg[i]);
				f = 1;
			} else {
				addch(msg[i]);
				f = 0;
			}
			if (l == 0) {
				mvaddch(LINES/2-1, COLS/8 - 1, '\\' | A_BOLD);
				mvaddch(LINES/2-1, COLS/8, '\\' | A_BOLD);
				mvaddch(LINES/2, COLS/8, '|' | A_BOLD);
				mvaddch(LINES/2+1, COLS/8 - 1, '/' | A_BOLD);
				mvaddch(LINES/2+1, COLS/8 + 1, '\\' | A_BOLD);
				mvaddch(LINES/2-1, COLS - COLS/8 - 1, '\\' | A_BOLD);
				mvaddch(LINES/2-1, COLS - COLS/8, '\\' | A_BOLD);
				mvaddch(LINES/2, COLS - COLS/8, '|' | A_BOLD);
				mvaddch(LINES/2+1, COLS - COLS/8 - 1, '/' | A_BOLD);
				mvaddch(LINES/2+1, COLS - COLS/8 + 1, '\\' | A_BOLD);
				l = 1;
			} else {
				mvaddch(LINES/2-1, COLS/8, '/' | A_BOLD);
				mvaddch(LINES/2-1, COLS/8 + 1, '/' | A_BOLD);
				mvaddch(LINES/2, COLS/8, '|' | A_BOLD);
				mvaddch(LINES/2+1, COLS/8 - 1, '/' | A_BOLD);
				mvaddch(LINES/2+1, COLS/8 + 1, '\\' | A_BOLD);
				mvaddch(LINES/2-1, COLS - COLS/8, '/' | A_BOLD);
				mvaddch(LINES/2-1, COLS - COLS/8 + 1, '/' | A_BOLD);
				mvaddch(LINES/2, COLS - COLS/8, '|' | A_BOLD);
				mvaddch(LINES/2+1, COLS - COLS/8 - 1, '/' | A_BOLD);
				mvaddch(LINES/2+1, COLS - COLS/8 + 1, '\\' | A_BOLD);
				l = 0;
			}
			refresh();
		}
	}
	getch();
	return;
}
