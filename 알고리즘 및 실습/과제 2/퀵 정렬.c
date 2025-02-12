#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int n = 100000;
int Limits[4] = { 1, 100, 500, 1000 };

int* createArray();
void quickSort(int* A, int n, int index, char mode);
void rQuickSort(int* A, int l, int r, int index, char mode);
void inPlacePartition(int* A, int l, int r, int k, int* a, int* b);
int findPivot(int* A, int l, int r, char mode);
int findIndexOfMedianOfThree(int a, int b, int c);
int* insertionSort(int* A, int n);

int main() {
	int* A = createArray();
	int* A_copy = (int*)malloc(sizeof(int) * n);
	char mode[4] = { 'a', 'b', 'c', 'd' };

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);

	for (int i = 0; i < 4; i++) {
		printf("%-9d", Limits[i]);

		for (int j = 0; j < 4; j++) {
			memcpy(A_copy, A, sizeof(int) * n);
			
			QueryPerformanceCounter(&start);
			quickSort(A_copy, n, i, mode[j]);
			QueryPerformanceCounter(&end);

			diff.QuadPart = end.QuadPart - start.QuadPart;

			printf(" %-15.8f", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
		}

		printf("\n");
	}

	free(A);
	free(A_copy);

	return 0;
}

int* createArray() {
	int* A = (int*)malloc(sizeof(int) * n);

	srand(time(NULL));

	for (int i = 0; i < n; i++)
		A[i] = rand() % n + 1;

	return A;
}

void quickSort(int* A, int n, int index, char mode) {
	
	rQuickSort(A, 0, n - 1, index, mode);

	if (Limits[index] > 1)
		insertionSort(A, n);
}
void rQuickSort(int* A, int l, int r, int index, char mode) {
	int k;
	int a, b;

	if (r - l >= Limits[index]) {
		k = findPivot(A, l, r, mode);
		inPlacePartition(A, l, r, k, &a, &b);
		rQuickSort(A, l, a - 1, index, mode);
		rQuickSort(A, b + 1, r, index, mode);
	}
}
void inPlacePartition(int* A, int l, int r, int k, int* a, int* b) {
	int pivot = A[k];
	int tmp, i, j;

	tmp = A[k];
	A[k] = A[r];
	A[r] = tmp;

	i = l;
	j = r - 1;

	while (i <= j) {
		// A[i]가 pivot과 같으면 i가 증가하지 않게 설정
		while (i <= j && A[i] < pivot)
			i++;
		// A[j]는 pivot과 같아도 j가 감소
		while (j >= i && A[j] >= pivot)
			j--;
		if (i < j) {
			tmp = A[i];
			A[i] = A[j];
			A[j] = tmp;
		}
	}

	tmp = A[i];
	A[i] = A[r];
	A[r] = tmp;

	*a = i;

	// a부터 시작해서 pivot과 중복된 값을 가진 마지막 인덱스까지 이동
	while (A[i + 1] == pivot)
		i++;

	*b = i;
}
int findPivot(int* A, int l, int r, char mode) {
	int a, b, c;

	srand(time(NULL));

	if (mode == 'a')
		return r;
	if (mode == 'c')
		return rand() % (r - l + 1) + l;
	if (r - l == 1)
		return l;
	if (mode == 'b') {
		a = l;
		b = (l + r) / 2;
		c = r;
		
		return findIndexOfMedianOfThree(A, a, b, c);
	}
	if (mode == 'd') {
		a = rand() % (r - l + 1) + l;
		b = rand() % (r - l + 1) + l;
		c = rand() % (r - l + 1) + l;

		return findIndexOfMedianOfThree(A, a, b, c);
	}
}

int findIndexOfMedianOfThree(int* A, int a, int b, int c) {
	// 값이 같은 경우
	if (A[a] == A[b] || A[a] == A[c])
		return a;
	else if (A[b] == A[c])
		return b;
	// 값이 모두 다른 경우
	if ((A[a] < A[b] && A[b] < A[c]) || (A[c] < A[b] && A[b] < A[a]))
		return b;
	else if ((A[b] < A[a] && A[a] < A[c]) || (A[c] < A[a] && A[a] < A[b]))
		return a;
	else if ((A[a] < A[c] && A[c] < A[b]) || (A[b] < A[c] && A[c] < A[a]))
		return c;
}

int* insertionSort(int* A, int n) {
	int index, j, data;

	for (index = 1; index < n; index++) {
		data = A[index];
		j = index - 1;
		while ((j >= 0) & (A[j] > data)) {
			A[j + 1] = A[j];
			j--;
		}
		A[j + 1] = data;
	}
}