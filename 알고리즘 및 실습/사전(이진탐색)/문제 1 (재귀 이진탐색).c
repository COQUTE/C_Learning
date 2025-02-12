#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int FindElement(int* arr, int k, int l, int r);

int main() {
	int n, k, result;
	int* arr;

	scanf("%d %d", &n, &k);
	arr = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	result = FindElement(arr, k, 0, n - 1);
	printf(" %d\n", result);

	free(arr);

	return 0;
}

int FindElement(int* arr, int k, int l, int r) {
	int mid;

	if (l > r)
		return l - 1;

	mid = (l + r) / 2;

	if (arr[mid] == k)
		return mid;
	else if (arr[mid] < k)
		return FindElement(arr, k, mid + 1, r);
	else
		return FindElement(arr, k, l, mid - 1);
}