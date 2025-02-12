#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** arr;
	int RowN, ColN;
	int Row = 0, Col = -1, Num = 1;
	int RowLimit, ColLimit, Direction = 1;

	scanf("%d %d", &RowN, &ColN);

	arr = malloc(sizeof(int*) * RowN);

	for (int i = 0; i < RowN; i++)
	{
		arr[i] = malloc(sizeof(int) * ColN);
	}

	RowLimit = RowN - 1;
	ColLimit = ColN;

	while (RowLimit != 0 && ColLimit != 0)
	{
		for (int p = 0; p < ColLimit; p++)
		{
			Col = Col + Direction;

			arr[Row][Col] = Num;

			Num++;
		}

		ColLimit--;

		for (int p = 0; p < RowLimit; p++)
		{
			Row = Row + Direction;

			arr[Row][Col] = Num;

			Num++;
		}

		RowLimit--;

		Direction = -Direction;
	}

	for (int i = 0; i < RowN; i++)
	{
		for (int j = 0; j < ColN; j++)
		{
			printf(" %d", arr[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < RowN; i++)
	{
		free(arr[i]);
	}

	free(arr);

	return 0;
}