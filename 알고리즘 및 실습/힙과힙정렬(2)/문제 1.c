#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;

void downHeap(int i, int last) {
	int left = i * 2, right = i * 2 + 1;
	int bigger, tmp;

	if (left > last)
		return;

	bigger = left;

	if (right <= last)
		if (H[right] > H[bigger])
			bigger = right;

	if (H[i] >= H[bigger])
		return;

	tmp = H[i];
	H[i] = H[bigger];
	H[bigger] = tmp;

	downHeap(bigger, last);
}

void inPlaceHeapSort() {
	int tmp;

	for (int i = n / 2; i > 0; i--)
		downHeap(i, n);

	for (int i = n; i >= 2; i--) {
		tmp = H[1];
		H[1] = H[i];
		H[i] = tmp;

		downHeap(1, i - 1);
	}
}

void printArray() {
	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);

	printf("\n");
}

int main() {
	int num;

	scanf("%d", &num);

	for (int i = 1; i <= num; i++) {
		scanf("%d", &H[i]);
		n++;
	}

	inPlaceHeapSort();

	printArray();

	return 0;
}