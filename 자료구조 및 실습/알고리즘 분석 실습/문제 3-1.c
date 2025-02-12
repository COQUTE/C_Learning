#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* prefixAverages1(int* X,int n)
{
	int* A = malloc(sizeof(int) * n);
	int sum;

	for (int i = 0; i < n; i++)
	{
		sum = 0;
		
		for (int j = 0; j <= i; j++)
			sum += X[j];

		A[i] = (int)((float)sum / (i + 1) + 0.5);
	}

	return A;
}

int* prefixAverages2(int* X,int n)
{
	int* A = malloc(sizeof(int) * n);
	int sum = 0;

	for (int i = 0; i < n; i++)
	{
		sum += X[i];
		A[i] = (int)((float)sum / (i + 1) + 0.5);
	}

	return A;
}

int main()
{
	int* A;
	int* X;
	int n;

	scanf("%d", &n);

	X = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &X[i]);
	}

	A = prefixAverages1(X, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d", A[i]);

		if (i != n - 1)
			printf(" ");
	}

	printf("\n");

	free(A);

	A = prefixAverages2(X, n);

	for (int i = 0; i < n; i++)
	{
		printf("%d", A[i]);

		if (i != n - 1)
			printf(" ");
	}

	printf("\n");

	free(A);

	return 0;
}