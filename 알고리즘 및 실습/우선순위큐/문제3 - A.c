#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void inPlaceSelectionSort(int* arr, int n) {
	int index, maxLoc;
	int temp;

	for (index = n - 1; index > 0; index--) {
		maxLoc = index;
		for (int j = index - 1; j >= 0; j--) {
			if (arr[j] > arr[maxLoc])
				maxLoc = j;
		}
		temp = arr[index];
		arr[index] = arr[maxLoc];
		arr[maxLoc] = temp;
	}
}

void inPlaceInsertionSort(int* arr, int n) {
	int index, j, data;

	for (index = 1; index < n; index++) {
		data = arr[index];
		j = index - 1;
		while ((j >= 0) & (arr[j] > data)) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = data;
	}
}

int main() {
	int n, *arr_A, *arr_B;
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	
	scanf("%d", &n);

	srand(time(NULL));

	arr_A = (int*)malloc(sizeof(int) * n);
	arr_B = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		arr_A[i] = arr_B[i] = rand() % 1001;
	}

	QueryPerformanceFrequency(&ticksPerSec);

	QueryPerformanceCounter(&start);
	inPlaceSelectionSort(arr_A, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;

	printf("%.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	QueryPerformanceCounter(&start);
	inPlaceInsertionSort(arr_B, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;

	printf("%.12fms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	free(arr_A);
	free(arr_B);

	return 0;
}