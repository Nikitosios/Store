#include <stdio.h>
#include <string.h>

typedef struct human {
	char *name;
	unsigned char age;
	void (*say) (struct human *, char *);
} human;

static void say (struct human *, char *);
struct human *newHuman (void);
void killHuman (human *);
