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

	memset(&p1, 0, sizeof(struct Point2D));

	printf("%d %d\n\n", p1.x, p1.y);

	struct Point2D *p2 = malloc(sizeof(struct Point2D));

	memset(p2, 0, sizeof(struct Point2D));

	printf("%d %d\n", p2->x, p2->y);

	free(p2);
	
	return 0;
}