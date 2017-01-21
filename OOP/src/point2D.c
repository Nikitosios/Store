#include <stdlib.h>
#include <stdio.h>
#include "point2D.h"
typedef struct private {
	int x;
	int y;
} private;

static int getx(struct point2D*p) {
	return ((struct private*)(p->prvtPoint2D))->x;
}
static void setx(struct point2D *p, int val) {
	((struct private*)(p->prvtPoint2D))->x = val;
}

point2D* newPoint2D()  {
	point2D* ptr;
	ptr = (point2D*) malloc(sizeof(point2D));
	ptr -> prvtPoint2D = malloc(sizeof(private));
	ptr -> getX = &getx;
	ptr -> setX = &setx;
	return ptr;
}

void deletePoint2D (point2D * p)
{
	free(p->prvtPoint2D);
	free(p);
}

int main (void)
{
	point2D *point = newPoint2D();
	int p = point->getX(point);
	point->setX(point, 42);
	p = point->getX(point);
	printf("p = %d\n", p);
	deletePoint2D(point);
	return 0;
}
