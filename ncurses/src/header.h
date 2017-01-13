#include <form.h>
#include <locale.h>

#define BORD_WIDTH 7
#define MSG_SIZE 2022

#if defined(_WIN32) || defined(_WIN64)
#include <window.h>
#define msleep(msec) Sleep(msec)
#else
#include <unistd.h>
#define msleep(msec) usleep(msec*1000)
#endif

struct object create_object (int y, int x, int h, int w, unsigned int flags, bool form);
int update_screen (void);
int send_message (char *msg);
int show_message (char *msg, bool who);
char *msgformat (char *msg);

typedef struct object {
	int y, x, h, w, ey, ex, cy, cx;
	WINDOW *win;
} object;

struct object msgsend;
struct object msgbox;
struct object filesend;
struct object alarm_b;
FORM *textform;
FIELD *textbox[2];

bool alarming;
