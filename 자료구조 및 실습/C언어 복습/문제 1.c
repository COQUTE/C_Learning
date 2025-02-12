#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int n)
{
	int total = 0;

	for (int i = 1; i <= n; i++)
	{
		total += i;
	}

	return total;
}

int main()
{
	int X;
	int total = 0;

	scanf("%d", &X);

	for (int i = 1; i <= X; i++)
	{
		total += sum(i);
	}

	printf("%d\n", total);

	return 0;
}