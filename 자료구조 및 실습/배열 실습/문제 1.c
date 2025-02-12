#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, ReverseN;
	int* X, * Reverse;
	int i, StartIndex, EndIndex, tmp;

	scanf("%d", &N);
	
	X = malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &X[i]);
	}

	scanf("%d", &ReverseN);

	Reverse = malloc(sizeof(int) * ReverseN * 2);

	for (i = 0; i < ReverseN * 2; i++)
	{
		scanf("%d", &Reverse[i]);
	}

	for (i = 0; i < ReverseN * 2; i = i + 2)
	{
		StartIndex = Reverse[i];
		EndIndex = Reverse[i + 1];

		while (StartIndex < EndIndex)
		{
			tmp = X[StartIndex];
			X[StartIndex] = X[EndIndex];
			X[EndIndex] = tmp;

			StartIndex++;
			EndIndex--;
		}
	}

	for (i = 0; i < N; i++)
	{
		printf(" %d", X[i]);
	}

	free(X);
	free(Reverse);

	return 0;
}