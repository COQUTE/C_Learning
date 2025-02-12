#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ArrayLowToHigh(int* arr, int N)
{
	int Min = arr[0];

	for (int i = 1; i < N; i++)
	{
		if (Min > arr[i])
			Min = arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		arr[i] = Min;

		Min++;
	}
}

/* 연속적인 정수이기 때문에 첫번째 for문에서 배열 중 가장 작은 정수를
   찾았고, 두번째 for문에서 배열의 값을 가장 작은 정수를 기준으로 1씩
   증가시키며 집어넣었다.
   
   최악의 실행시간은 가장 작은 정수가 배열의 마지막 부분에 있을 경우이고
   그 때, 실행시간은 (N의 계수 2와 나머지 상수를 제외) O(N)이 된다.*/

int main()
{
	int N;
	int* SerialNumbers;

	scanf("%d", &N);

	SerialNumbers = malloc(sizeof(int) * N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &SerialNumbers[i]);
	}

	ArrayLowToHigh(SerialNumbers, N);

	for (int i = 0; i < N; i++)
	{
		printf(" %d", SerialNumbers[i]);
	}

	free(SerialNumbers);

	return 0;
}