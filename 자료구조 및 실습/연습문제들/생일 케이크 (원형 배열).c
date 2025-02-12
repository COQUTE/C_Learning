#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* buildList(int n)
{
	int* arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		arr[i] = i + 1;

	return arr;
}

int runSimulation1(int* arr, int n, int k, int N) // O(kn)만큼 소요
{
	int Rank = 0, i;

	while (n > 1) // 초의 개수가 1이 될 때까지 반복
	{
		i = 0;

		while (i < k) // 꺼진 초를 제외한 나머지 초들을 세면서 Rank를 증가시키고 k번째 초를 끔
		{
			Rank = (Rank + 1) % N;

			if (arr[Rank] != 0)
				i++;
		}

		arr[Rank] = 0;

		n--;

		while (arr[Rank] == 0)
			Rank = (Rank + 1) % N;
	}

	return arr[Rank];
}

int* Remove(int* arr, int Rank, int n)
{
	int* NewArr;

	if (Rank < 0 || Rank >= n)
		printf("invalid position\n");
	else if (Rank < n / 2)
	{
		for (int i = Rank - 1; i >= 0; i--)
			arr[(i + 1) % n] = arr[i % n];

		NewArr = (int*)malloc(sizeof(int) * (n - 1));

		for (int i = 0; i < n - 1; i++)
			NewArr[i] = arr[i + 1];

		free(arr);

		return NewArr;
	}
	else
	{
		for (int i = Rank + 1; i < n; i++)
			arr[(i - 1) % n] = arr[i % n];

		NewArr = (int*)malloc(sizeof(int) * (n - 1));

		for (int i = 0; i < n - 1; i++)
			NewArr[i] = arr[i];

		free(arr);

		return NewArr;
	}
}

int runSimulation2(int* arr, int n, int k) // O(n*n)만큼 소요
{
	int Rank = 0, result;

	while (n > 1)
	{
		Rank = (Rank + k) % n;
		
		arr = Remove(arr, Rank, n);

		n--;
	}

	result = arr[0];

	free(arr);

	return result;
}

int candle1(int n, int k)
{
	int* arr;
	int N = n;

	arr = buildList(n);

	return runSimulation1(arr, n, k, N);
}

int candle2(int n, int k)
{
	int* arr;

	arr = buildList(n);

	return runSimulation2(arr, n, k);
}

int main()
{
	printf("%d %d %d\n", candle1(10, 3), candle1(11, 4), candle1(12, 5));
	printf("%d %d %d\n", candle2(10, 3), candle2(11, 4), candle2(12, 5));

	return 0;
}