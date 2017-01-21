typedef struct point2D {
	void *prvtPoint2D;
	int (*getX) (struct point2D*);
	void (*setX)(struct point2D*, int);
} point2D;
point2D* newPoint2D (void);
void deletePoint2D (point2D*);
