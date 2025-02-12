#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int CompareTwoNumbers(int First, int Second)
{
	if (First >= Second)
		return First;
	else
		return Second;
}

int FindMax(int arr[], int Size)
{
	if (Size == 1)
		return arr[0];
	else
		return CompareTwoNumbers(arr[Size - 1], FindMax(arr, Size - 1));
}

int main()
{
	int arr[21] = { 0, };
	int N;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("%d\n", FindMax(arr, N));

	return 0;
}