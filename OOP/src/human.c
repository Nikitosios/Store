#include "human.h"

static void say (struct human *this, char *msg)
{
	printf("%s: %s\n", this->name, msg);
}

struct human *newHuman (void)
{
	struct human *hum;
	char *defaultName = "Вася";
	
	hum = malloc(sizeof(struct human));
	hum->say = (void *) &say;
	hum->age = 20;
	hum->name = malloc(20);
	for (int i = 0; i < strlen(defaultName); ++i)
		hum->name[i] = defaultName[i];
	printf("%s родился!\n", hum->name);
	return hum;
}

void killHuman (human *hum)
{
	char *name = malloc(strlen(hum->name));
	for (int i = 0; i < strlen(hum->name); ++i)
		name[i] = hum->name[i];
	free(hum->name);
	free(hum);
	printf("%s убит...\n", name);
}
