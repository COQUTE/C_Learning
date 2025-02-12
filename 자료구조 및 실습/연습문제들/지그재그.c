#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** arr;
	int Row = 0, Col;
	int RowN, ColN, Num = 1;

	scanf("%d %d", &RowN, &ColN);

	arr = malloc(sizeof(int*) * RowN);

	for (int i = 0; i < RowN; i++)
	{
		arr[i] = malloc(sizeof(int) * ColN);
	}

	while (Row < RowN)
	{
		for (Col = 0; Col < ColN; Col++)
		{
			arr[Row][Col] = Num;

			Num++;
		}

		Row++;

		if (Row == RowN)
			break;

		for (Col = ColN - 1; Col >= 0; Col--)
		{
			arr[Row][Col] = Num;

			Num++;
		}

		Row++;
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