/* 함수의 인자로 들어온 arr와 똑같은 크기의 tmp를 만든다. 그 이후 arr의 요소 중 최솟값을 찾아서 Min에 대입한다.
   그러고나서 for문을 돌리는데 입력이 연속적인 숫자이기 때문에 규칙이 존재한다.
   어떤 값이 오름차순으로 정렬된 후 있어야할 위치는 (자기자신 - Min)이라는 것이다. 예를 들자면
   arr = {10, 8, 7, 6, 9}, Min = 6 : 오름차순으로 정렬했을 때 10이 있어야할 위치(= 10 - 6 = 4), 8이 있어야할 위치(= 8 - 6 = 2).....
   이 규칙을 이용해서 tmp[arr[i] - Min] = arr[i]를 해준다.
   마지막으로는 tmp에 있는 정렬된 값들을 arr에 복사해주고 tmp의 메모리를 해제해준다.
   이렇게 되면 (N의 계수 3과 상수를 제외) 실행시간은 O(N)이 된다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void ArrayLowToHigh(int* arr, int N)
{
	int* tmp = malloc(sizeof(int) * N); 
	int Min = arr[0];
	int i;

	for (i = 1; i < N; i++) 
	{
		if (Min > arr[i])
			Min = arr[i];
	}

	for (i = 0; i < N; i++)
	{
		tmp[arr[i] - Min] = arr[i];
	}								

	for (i = 0; i < N; i++)
	{
		arr[i] = tmp[i];
	}

	free(tmp);
}

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