#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

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

int main() {
	int n, *arr;

	scanf("%d", &n);

	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	inPlaceSelectionSort(arr, n);

	for (int i = 0; i < n; i++) {
		printf(" %d", arr[i]);
	}

	free(arr);

	return 0;
}