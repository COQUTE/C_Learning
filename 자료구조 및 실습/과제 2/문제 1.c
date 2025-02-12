#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int sum(int N)
{
	if (N < 10)
		return N;
	else
		return sum(N / 10) + (N % 10);
}

int main()
{
	int N;

	scanf("%d", &N);

	printf("%d\n", sum(N));

	return 0;
}