#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** arr;
	int RowN, ColN;
	int Row = 0, Col = 0, Num = 1;
	int RowMove = 0, ColMove = 0;

	scanf("%d %d", &RowN, &ColN);

	arr = malloc(sizeof(int*) * RowN);

	for (int i = 0; i < RowN; i++)
	{
		arr[i] = malloc(sizeof(int) * ColN);
	}

	while (1)
	{
		arr[Row][Col] = Num;
		Num++;

		if (Num > RowN * ColN)
			break;

		Row++;
		Col--;

		if (ColMove != ColN - 1 && (Row == RowN || Col < 0))
		{
			ColMove++;
			Col = ColMove;
				
			Row = 0;
		}
		else if (RowMove != RowN && (Row == RowN || Col < 0))
		{
			RowMove++;
			Row = RowMove;

			Col = ColN - 1;
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