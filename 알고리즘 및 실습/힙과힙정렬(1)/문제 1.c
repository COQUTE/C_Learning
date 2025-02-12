#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int H[100];
int n = 0; //ÈüÀÇ Å©±â

void upHeap(int i) {
	int tmp;
	
	if (i == 1)
		return;

	if (H[i / 2] >= H[i])
		return;

	tmp = H[i / 2];
	H[i / 2] = H[i];
	H[i] = tmp;

	upHeap(i / 2);
}

void downHeap(int i) {
	int bigger, tmp;

	if (i * 2 > n)
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

void insertItem(int key) {
	n = n + 1;

	H[n] = key;

	upHeap(n);
}

int removeMax() {
	int key = H[1];
	
	H[1] = H[n];
	n = n - 1;

	downHeap(1);

	return key;
}

void printHeap() {
	if (n < 1)
		return;

	for (int i = 1; i <= n; i++)
		printf(" %d", H[i]);

	printf("\n");
}

int main() {
	char order;
	int key;

	while (1) {
		scanf("%c", &order);

		switch (order) {
		
		case 'i':
			scanf("%d", &key);
			insertItem(key);
			printf("0\n");

			break;

		case 'd':
			printf("%d\n", removeMax());

			break;

		case 'p':
			printHeap();

			break;
		}

		if (order == 'q')
			break;
	}

	return 0;
}