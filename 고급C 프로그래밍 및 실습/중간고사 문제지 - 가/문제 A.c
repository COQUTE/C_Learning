#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int add_to_k(int* ptr1, int* ptr2)
{
	int num;
	int sum = 0;

	for (int* i = ptr1; i <= ptr2; i++)
	{
		sum += *i;
	}

	return sum;
}

int main()
{
	int d[100];
	int N, total = 0;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &d[i]);
	}

	for (int i = 0; i < N; i++)
	{
		total += add_to_k(&d[0], &d[i]);
	}

	printf("%d\n", total);

	return 0;
}