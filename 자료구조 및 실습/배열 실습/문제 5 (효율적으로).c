#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** arr;
	int RowN, ColN;
	int Col, Row, Dig, Num = 1;

	scanf("%d %d", &RowN, &ColN);

	arr = malloc(sizeof(int*) * RowN);

	for (int i = 0; i < RowN; i++)
	{
		arr[i] = malloc(sizeof(int) * ColN);
	}

	for (Col = 0; Col < RowN + ColN - 1; Col++)
	{
		for (Row = 0; Row < RowN; Row++)
		{
			Dig = Col - Row;

			if (Dig >= 0 && Dig < ColN)
			{
				arr[Row][Dig] = Num++;
			}
		}
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