#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Point2D {
	int x;
	int y;
};

int main()
{
	struct Point2D p1;
	struct Point2D p2;

	p1.x = 10;
	p1.y = 20;

	memcpy(&p2, &p1, sizeof(struct Point2D));

	printf("%d %d\n\n", p2.x, p2.y);

	struct Point2D* p3 = malloc(sizeof(struct Point2D));
	struct Point2D* p4 = malloc(sizeof(struct Point2D));

	p3->x = 10;
	p3->y = 20;

	memcpy(p4, p3, sizeof(struct Point2D));

	printf("%d %d\n", p4->x, p4->y);

	free(p3);
	free(p4);

	return 0;
}