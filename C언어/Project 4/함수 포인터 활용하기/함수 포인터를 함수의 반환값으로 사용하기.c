#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

int (*getAdd())(int, int)
{
	return add;
}

int main()
{
	printf("%d\n", getAdd()(10, 20));

	return 0;
}