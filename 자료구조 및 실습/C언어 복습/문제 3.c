#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	int num[50];
	int N;
	int a, b;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &num[i]);
	}

	scanf("%d %d", &a, &b);

	swap(&num[a], &num[b]);

	for (int i = 0; i < N; i++)
	{
		printf(" %d", num[i]);
	}

	printf("\n");

	return 0;
}