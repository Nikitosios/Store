#include <ncurses.h>
WINDOW *create_newwin (int h, int w, int y, int x, unsigned int cp);
void destroy_win (WINDOW *win, unsigned int cp);
