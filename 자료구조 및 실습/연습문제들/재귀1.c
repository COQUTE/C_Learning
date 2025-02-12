#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int N)
{
	if (N == 1)
		return 1;
	else
		return N + sum(N - 1);
}

int product(int a, int b)
{
	if (b == 1)
		return a;
	else
		return a + product(a, b - 1);
}

int quotient(int a, int b)
{
	if (a < b)
		return 0;
	else
		return 1 + quotient(a - b, b);
}

int main()
{
	printf("sum(5)의 값: %d\n", sum(5));
	printf("product(6, 8)의 값: %d\n", product(6, 8));
	printf("quotient(29, 3)의 값: %d\n", quotient(29, 3));

	return 0;
}