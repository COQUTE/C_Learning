#include <stdio.h>

int add(int a, int b)
{
	return a + b;
}

void executer(int (*fp)(int, int))
{
	printf("%d\n", fp(10, 20));
}

int main()
{
	executer(add);

	return 0;
}