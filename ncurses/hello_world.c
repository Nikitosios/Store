#include <ncurses.h>

int main (void)
{
	initscr();                 /* Переход в curses режим */
	printw("Hello, world!\n"); /* Отображение приветствия в буфер */
	refresh();                 /* Вывод приветствия на настроящий экран */
	getch();                   /* Ожидание нажатия любой клавиши */
	endwin();                  /* Выход из curses режима (обязательно) */
	return 0;
}
