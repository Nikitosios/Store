#include <form.h>

#define BORD_WIDTH 7

struct object create_object (int y, int x, int h, int w, unsigned int flags, bool form);
int update_screen (void);

typedef struct object {
	int y, x, h, w, ey, ex, cy, cx;
	WINDOW *win;
} object;

struct object msgsend;
struct object msgbox;
struct object filesend;
struct object exit_b;
FORM *textform;
FIELD *textbox[2];
