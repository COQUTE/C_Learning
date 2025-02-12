#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {

	int A[10][10] = { 0, };
	int B[10][10] = { 0, };
	int cnt = 0;
	int sop = 0;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &A[i][j]);
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &B[i][j]);
		}
	}

	for (int i = 0; i < 10; i++) {
		cnt = 0;

		while (cnt != 10) {
			sop = 0;

			for (int j = 0; j < 10; j++)
				sop += A[i][j] * B[j][cnt];

			printf("%d ", sop);
			cnt++;
		}

		printf("\n");
	}

	for (int i = 0; i < 10; i++) {
		cnt = 0;

		while (cnt != 10) {
			sop = 0;

			for (int j = 0; j < 10; j++)
				sop += B[i][j] * A[j][cnt];

			printf("%d ", sop);
			cnt++;
		}

		printf("\n");
	}

	return 0;
}