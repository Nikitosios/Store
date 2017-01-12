#include <form.h>
#include <panel.h>

struct object create_object(int y, int x, int h, int w, unsigned int flags);

typedef struct object {
	WINDOW *win;
	PANEL *panel;
} object;

struct object msgsend;
struct object msgbox;
struct object filesend;
struct object exit_b;
FORM *textform;
FIELD *textbox[2];
