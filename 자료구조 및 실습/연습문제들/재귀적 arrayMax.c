#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int arrMax(int* arr, int N)
{
	if (N == 1)
		return arr[0];
	else
		return max(arrMax(arr, N - 1), arr[N - 1]);
}

int main()
{
	int* arr;
	int N;

	scanf("%d", &N);

	arr = malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d\n", arrMax(arr, N));

	free(arr);

	return 0;
}