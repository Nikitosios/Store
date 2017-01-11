#include <form.h>
#include <panel.h>

struct object create_object(int y, int x, int h, int w, unsigned int flags);

typedef struct object {
	WINDOW *win;
	PANEL *panel;
} object;

struct object msgsend;
