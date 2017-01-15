#include "header.h"

int msgscroll (void);

int parse_ch (short ch)
{
	if (ch == KEY_BACKSPACE) {
		if (my_msgP == my_msgEP && my_msgP > my_msg) {
			--my_msgEP;
			if (*(--my_msgP) >= 128) {
				--my_msgP;
				--my_msgEP;
			}
		}
		update_screen();
	} else if (ch >= 32) {
		*my_msgP = ch;
		++my_msgP;
		++my_msgEP;
		update_screen();
	} else if (ch == '\n') {
		*my_msgP = '\n';
		++my_msgP;
		++my_msgEP;
		update_screen();
	}
	return 0;
}

int msgscroll (void)
{
	return 0;
}
