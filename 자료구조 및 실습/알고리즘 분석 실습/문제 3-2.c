#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int* prefixAverages1(int* X, int n)
{
	int* A = malloc(sizeof(int) * n);				//{ASS 1}
	int sum;										//{ASS 1}

	for (int i = 0; i < n; i++)						//{ASS, EXP 1+n}
	{
		sum = 0;									//{ASS, n}

		for (int j = 0; j <= i; j++)				//{ASS, EXP n+(1+2+3+...+n)}
			sum += X[j];							//{IND, ASS n(2)}

		A[i] = (int)((float)sum / (i + 1) + 0.5);	//{ASS, IND n(2)}
	}

	return A;										//{RET 1}
}													//{Total (1/2)n*n + (15/2)n + 4}

int* prefixAverages2(int* X, int n)
{
	int* A = malloc(sizeof(int) * n);				//{ASS, 1}
	int sum = 0;									//{ASS, 1}

	for (int i = 0; i < n; i++)						//{ASS, EXP 1+n}
	{
		sum += X[i];								//{IND, ASS n(2)}
		A[i] = (int)((float)sum / (i + 1) + 0.5);	//{ASS, IND n(2)}
	}

	return A;										//{RET 1}
}													//{Total 5n + 4}

int main()
{
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	int* A;
	int* X;
	int n;

	scanf("%d", &n);

	X = malloc(sizeof(int) * n);

	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		X[i] = rand() % 10000 + 1; // 1 ~ 10000 사이의 정수 배열 X이기 때문에
	}

	QueryPerformanceFrequency(&ticksPerSec);
	
	QueryPerformanceCounter(&start);

	A = prefixAverages1(X, n);

	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fms\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000; // ms 단위로 출력하기 위해 1000을 곱해줌

	free(A);

	QueryPerformanceCounter(&start);

	A = prefixAverages2(X, n);

	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%.9fms\n", (double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000; //ms 단위로 출력하기 위해 1000을 곱해줌

	free(A);

	free(X);

	return 0;
}