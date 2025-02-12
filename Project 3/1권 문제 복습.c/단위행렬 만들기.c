#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int** metrix;
	int size;

	scanf("%d", &size);

	metrix = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		metrix[i] = malloc(sizeof(int) * size);
		memset(metrix[i], 0, sizeof(int) * size);

		for (int j = 0; j < size; j++)
		{
			if (i == j)
				metrix[i][j]++;

			printf("%d ", metrix[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < size; i++)
	{
		free(metrix[i]);
	}

	free(metrix);

	return 0;
}