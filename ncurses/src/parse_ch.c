#include "header.h"

int msgscroll (void);

int parse_ch (int ch)
{
	if (ch >= 32) {
		*my_msgP = ch;
		++my_msgP;
	} else if (ch == 263)
		--my_msgP;
	else if (ch == '\n') {
		*my_msgP = '\n';
		++my_msgP;
	}
	update_screen();
	return 0;
}

int msgscroll (void)
{
	return 0;
}
