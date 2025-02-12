#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, ChangeN;
	int* X, * Change;
	int i, Start;

	scanf("%d", &N);

	X = malloc(sizeof(int) * N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &X[i]);
	}

	scanf("%d", &ChangeN);

	Change = malloc(sizeof(int) * ChangeN);

	for (i = 0; i < ChangeN; i++)
	{
		scanf("%d", &Change[i]);
	}

	Start = X[Change[0]];

	for (i = ChangeN - 1; i > 1; i--)
	{
		X[Change[i]] = X[Change[i - 1]];
	}

	X[Change[i]] = Start;

	for (i = 0; i < N; i++)
	{
		printf(" %d", X[i]);
	}

	free(Change);
	free(X);

	return 0;
}