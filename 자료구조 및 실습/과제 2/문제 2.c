#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int pibonacci(int N)
{
	if (N <= 2)
		return 1;
	else
		return pibonacci(N - 2) + pibonacci(N - 1);
}

int main()
{
	int N;

	scanf("%d", &N);

	printf("%d\n", pibonacci(N));

	return 0;
}