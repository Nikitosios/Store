#include <ncurses.h>
#include <locale.h>
#include <stdlib.h>

#define BORD_WIDTH 7
#define MSG_SIZE 2022

#if defined(_WIN32) || defined(_WIN64)
#include <window.h>
#define msleep(msec) Sleep(msec)
#else
#include <unistd.h>
#define msleep(msec) usleep(msec*1000)
#endif

#define true 1
#define false 0

struct object create_object (int y, int x, int h, int w, unsigned int flags, bool form);
int update_screen (void);
int send_message (short *msg);
int show_message (short *msg, bool who);
char *msgformat (short *msg);
int parse_ch (short ch);

typedef struct object {
	int y, x, h, w, ey, ex, cy, cx;
	WINDOW *win;
} object;

struct object msgsend;
struct object msgbox;
struct object filesend;
struct object alarm_b;

bool alarming;
short my_msg[MSG_SIZE];
short *my_msgP;
int curY, curX;