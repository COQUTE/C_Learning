#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** arr;
	int Row = 0, Col = -1;
	int RowN, ColN, RowLimit, ColLimit;
	int Num = 1, Direction = 1;

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
		for (int i = 0; i < ColLimit; i++)
		{
			Col += Direction;
			
			arr[Row][Col] = Num;

			Num++;
		}

		ColLimit--;

		for (int i = 0; i < RowLimit; i++)
		{
			Row += Direction;

			arr[Row][Col] = Num;

			Num++;
		}

		RowLimit--;

		Direction = -Direction;
	}

	for (Row = 0; Row < RowN; Row++)
	{
		for (Col = 0; Col < ColN; Col++)
		{
			printf(" %d", arr[Row][Col]);
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