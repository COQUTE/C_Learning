#include <stdio.h>

struct Calc {
	int (*fp)(int, int);
};

int add(int a, int b)
{
	return a + b;
}

int main()
{
	struct Calc c;

	c.fp = add;

	printf("%d\n", c.fp(10, 20));

	return 0;
}