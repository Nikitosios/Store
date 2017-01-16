#include "header.h"

int msgscroll (void);

int parse_ch (short ch)
{
	if (ch == KEY_BACKSPACE) {
		if (my_msgP == my_msgEP && my_msgP > my_msg) {
			--my_msgEP;
			--my_msgP;
			if (*my_msgP >= 128) {
				--my_msgP;
				--my_msgEP;
			}
		} else if (my_msgP < my_msgEP && my_msgP > my_msg) {
			for (unsigned char *i = my_msgP; i < my_msgEP; ++i) {
				if (*i >= 128) {
					if (*(i + 2) >= 128) {
						*i = *(i + 2);
						*(i + 1) = *(i + 3);
						++i;
					} else *i = *(i + 2);
				} else *i = *(i + 1);
			}
			--my_msgP;
			--my_msgEP;
			if (*my_msgP >= 128) {
				--my_msgP;
				--my_msgEP;
			}
		}
		update_msgbox();
	} else if (ch >= 32) {
		if (my_msgP == my_msgEP) {
			*my_msgP = ch;
			++my_msgP;
			++my_msgEP;
		} else {
			for (unsigned char *i = my_msgEP; i > my_msgP; --i)
				*i = *(i - 1);
			*my_msgP = ch;
			++my_msgP;
			++my_msgEP;
		}
		update_msgbox();
	} else if (ch == '\n') {
		if (my_msgP == my_msgEP) {
			*my_msgP = ch;
			++my_msgP;
			++my_msgEP;
		} else {
			for (unsigned char *i = my_msgEP; i > my_msgP; --i)
				*i = *(i - 1);
			*my_msgP = ch;
			++my_msgP;
			++my_msgEP;
		}
		update_msgbox();
	}
	return 0;
}

int msgscroll (void)
{
	return 0;
}
