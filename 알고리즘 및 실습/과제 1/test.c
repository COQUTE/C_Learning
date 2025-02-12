#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>

void downHeap(int* L, int i, int last) {
	int left = i * 2, right = i * 2 + 1;
	int smaller, tmp;

	if (left > last)
		return;

	smaller = left;

	if (right <= last)
		if (L[right] < L[smaller])
			smaller = right;

	if (L[i] <= L[smaller])
		return;

	tmp = L[i];
	L[i] = L[smaller];
	L[smaller] = tmp;

	downHeap(L, smaller, last);
}

int findKthSmallest(int* L, int n, int k) {
	int tmp;

	// 1기 비재귀적 상향식 힙생성 O(n)
	for (int i = n / 2; i > 0; i--)
		downHeap(L, i, n);

	// 2기 O(klogn) - 필요한 k 번만 정렬을 실행
	for (int i = n; i > n - k; i--) {
		tmp = L[1];
		L[1] = L[i];
		L[i] = tmp;

		downHeap(L, 1, i - 1);
	}

	return L[n - k + 1];
}

int* buildList(int n, int min, int max) {
	int* L = (int*)malloc(sizeof(int) * (n + 1));

	srand(time(NULL));

	for (int i = 1; i <= n; i++)
		L[i] = (((long)rand() << 15) | rand()) % (max - min + 1) + min;

	return L;
}

void writeList(int* L, int n) {
	for (int i = 1; i <= n; i++) {
		printf("%d ", L[i]);
	}

	printf("\n");
}

int main() {
	int* L, * L_copy;
	int output[4], karray[4] = { 1, 100, 99900, 99999 };
	int e;
	float t;

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	L = buildList(10, 1, 100);
	L_copy = (int*)malloc(sizeof(int) * 11);
	memcpy(L_copy, L, sizeof(int) * 11);

	writeList(L, 10);

	QueryPerformanceFrequency(&ticksPerSec);

	for (int k = 1; k <= 3; k++) {
		QueryPerformanceCounter(&start);

		output[k] = findKthSmallest(L, 10, k);

		QueryPerformanceCounter(&end);

		diff.QuadPart = end.QuadPart - start.QuadPart;

		t = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000;

		printf("%.9fms\n", t);

		memcpy(L, L_copy, sizeof(int) * 11);
	}

	printf("%d %d %d\n", output[1], output[2], output[3]);

	free(L);
	free(L_copy);

	L = buildList(100000, 1, 1000000);
	L_copy = (int*)malloc(sizeof(int) * 100000);
	memcpy(L_copy, L, sizeof(int) * 100000);

	for (int k = 0; k < 4; k++) {
		QueryPerformanceCounter(&start);

		e = findKthSmallest(L, 100000, karray[k]);

		QueryPerformanceCounter(&end);

		diff.QuadPart = end.QuadPart - start.QuadPart;

		t = ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000;

		printf("%-9d%.9fms\n", e, t);

		memcpy(L, L_copy, 100000);
	}

	free(L);
	free(L_copy);

	return 0;
}