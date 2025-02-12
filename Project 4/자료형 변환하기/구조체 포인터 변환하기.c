#include <stdio.h>
#include <stdlib.h>

struct Data {
	char c1;
	int num1;
};

int main()
{
	struct Data* d1 = malloc(sizeof(struct Data));
	void* ptr;

	d1->c1 = 'a';
	d1->num1 = 10;

	ptr = d1;

	printf("%c\n", ((struct Data*)ptr)->c1);
	printf("%d\n", ((struct Data*)ptr)->num1);

	free(d1);

	return 0;
}