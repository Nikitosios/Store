#include <ncurses.h>
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>

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
#define MSGEND 1
#define STREND 0

struct object create_object (int y, int x, int h, int w, unsigned int flags, bool form);
int update_screen (void);
int update_msgbox (void);
int send_message (unsigned char *msg);
int show_messages (void);
char *msgformat (unsigned char *msg);
int parse_ch (short ch);
int msggetstrn (unsigned char *pointer);
int msggetsymn (void);
int msggo (int y, int x);

typedef struct object {
	int y, x, h, w, ey, ex, cy, cx;
	WINDOW *win;
} object;

struct object msgsend;
struct object msgbox;
struct object filesend;
struct object alarm_b;
struct object my_msgs;
struct object his_msgs;

bool alarming;
unsigned char my_msg[MSG_SIZE];
unsigned char *my_msgP;
unsigned char *my_msgEP;
int msgoffset;
int curY, curX;
FILE *history;
