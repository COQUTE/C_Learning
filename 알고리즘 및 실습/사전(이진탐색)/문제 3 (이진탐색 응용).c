#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int FindElement(int a, int b, int n);

int main() {
	int a, b, n;
	int result;

	scanf("%d %d %d", &a, &b, &n);
	getchar();

	result = FindElement(a, b, n);
	printf("%d\n", result);

	return 0;
}

int FindElement(int a, int b, int n) {
	int mid;
	char type;

	for (int i = 0; i < n; i++) {
		mid = (a + b) / 2;

		scanf("%c", &type);

		if (type == 'Y')
			a = mid + 1;
		else if (type == 'N')
			b = mid;
	}

	return b;
}