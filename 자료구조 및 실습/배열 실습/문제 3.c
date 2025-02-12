#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** arr;
	int N, i;
	int Row = 0, Col = 0, Num = 1;

	scanf("%d", &N);

	arr = malloc(sizeof(int*) * N);

	for (i = 0; i < N; i++)
	{
		arr[i] = malloc(sizeof(int) * N);
	}

	while (Num <= N * N)
	{
		for (Col = 0; Col < N; Col++)
		{
			arr[Row][Col] = Num;

			Num++;
		}

		Row++;

		if (Row == N)
			break;

		for (Col = N - 1; Col >= 0; Col--)
		{
			arr[Row][Col] = Num;

			Num++;
		}

		Row++;
	}

	for (i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf(" %d", arr[i][j]);
		}

		printf("\n");
	}

	for (i = 0; i < N; i++)
	{
		free(arr[i]);
	}

	free(arr);

	return 0;
}