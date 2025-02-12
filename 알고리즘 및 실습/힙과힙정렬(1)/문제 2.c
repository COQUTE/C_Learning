#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0;

void downHeap(int i) {
	int bigger, tmp;

	if (n == 1)
		return;

	bigger = i * 2;

	if (n > i * 2 && H[(i * 2) + 1] > H[bigger])
		bigger = (i * 2) + 1;

	if (H[i] >= H[bigger])
		return;

	tmp = H[i];
	H[i] = H[bigger];
	H[bigger] = tmp;

	downHeap(bigger);
}

void buildHeap() {
	for (int i = n / 2; i > 0; i--)
		downHeap(i);
}

void printHeap() {
	if (n < 1)
		return;

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

	buildHeap();

	printHeap();

	return 0;
}