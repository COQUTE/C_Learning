#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int size = 0;

	scanf("%d", &size);

	int** matrix;

	matrix = malloc(sizeof(int*) * size);

	for (int i = 0; i < size; i++)
	{
		matrix[i] = malloc(sizeof(int) * size);

		memset(matrix[i], 0, sizeof(int) * size);

		for (int j = 0; j < size; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 1;
			}
		
			printf("%d ", matrix[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < size; i++)
	{
		free(matrix[i]);
	}

	free(matrix);

	return 0;
}