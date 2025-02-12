#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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
	int n, *arr;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	inPlaceInsertionSort(arr, n);

	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}

	free(arr);

	return 0;
}