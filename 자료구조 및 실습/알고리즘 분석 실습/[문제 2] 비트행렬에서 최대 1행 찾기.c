#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int mostOnes(int** A, int n)
{
	int i = 0, j = 0;
	int onemax = 0;

	while (i < n && j < n)
	{
		if (A[i][j] == 0)
			i++;
		else
		{
			onemax = i;
			j++;
		}
	}

	return onemax;
}

int main()
{
	int** A;
	int n;
	
	scanf("%d", &n);

	A = malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++)
	{
		A[i] = malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	printf("%d\n", mostOnes(A, n));

	for (int i = 0; i < n; i++)
	{
		free(A[i]);
	}

	free(A);

	return 0;
}