#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int* num;
	int N;
	int c;

	scanf("%d", &N);

	num = malloc(sizeof(int) * N);
	memset(num, 0, sizeof(int) * N);
	
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &c);

		num[i] += c;
	}

	for (int i = N - 1; i >= 0; i--)
	{
		scanf("%d", &c);

		num[i] += c;
	}

	for (int i = 0; i < N; i++)
	{
		printf(" %d", num[i]);
	}

	printf("\n");

	free(num);

	return 0;
}