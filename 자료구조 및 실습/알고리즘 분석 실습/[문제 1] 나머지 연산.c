#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int modulo(int a, int b)
{
	while (a >= b) // O(a/b) ½Ã°£
	{
		a -= b;
	}

	return a;
}

int main()
{
	int a, b;

	scanf("%d %d", &a, &b);

	printf("%d\n", modulo(a, b));

	return 0;
}