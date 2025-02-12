#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** arr;
	int RowN, ColN, Row = 0, Col = 0, Num = 1;

	scanf("%d %d", &RowN, &ColN);

	int DownIndex[2] = { 0, ColN - 1 },
		LeftIndex[2] = { RowN - 1, ColN - 1 },
		UpIndex[2] = { RowN - 1, 0 },
		RightIndex[2] = { 1, 0 };

	arr = malloc(sizeof(int*) * RowN);

	for (int i = 0; i < RowN; i++)
	{
		arr[i] = malloc(sizeof(int) * ColN);
	}

	while (1)
	{
		while (1)
		{
			arr[Row][Col] = Num;
			
			Col++;
			Num++;

			if (Row == DownIndex[0] && Col == DownIndex[1])
				break;
		}
		if (Num == RowN * ColN)
			break;

		DownIndex[0]++;
		DownIndex[1]--;

		while (1)
		{
			arr[Row][Col] = Num;

			Row++;
			Num++;

			if (Row == LeftIndex[0] && Col == LeftIndex[1])
				break;
		}
		if (Num == RowN * ColN)
			break;

		LeftIndex[0]--;
		LeftIndex[1]--;

		while (1)
		{
			arr[Row][Col] = Num;
			
			Col--;
			Num++;

			if (Row == UpIndex[0] && Col == UpIndex[1])
				break;
		}
		if (Num == RowN * ColN)
			break;

		UpIndex[0]--;
		UpIndex[1]++;

		while (1)
		{
			arr[Row][Col] = Num;

			Row--;
			Num++;

			if (Row == RightIndex[0] && Col == RightIndex[1])
				break;
		}
		if (Num == RowN * ColN)
			break;

		RightIndex[0]++;
		RightIndex[1]++;
	}

	arr[Row][Col] = Num;

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