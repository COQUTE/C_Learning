#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 8

double det(double (*A)[N], int n);

int main() {
	int i = 0, j = 0;
	int n = 8;
	double A[N][N] = { 0, };

	// 행렬 값 입력
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%lf", &A[i][j]);
		}
	}

	printf("%.3f\n", det(A, n));

	return 0;
}

double det(double (*A)[N], int n) {
	int i, j, k, y;
	double det_a = 0;
	double temp[N][N];

	if (n != 1) {
		for (i = 0; i < n; i++) {
			for (j = 1; j < n; j++) {
				y = 0;

				for (k = 0; k < n; k++) {
					if (k != i) {
						temp[j - 1][y++] = *(A[0] + j * N + k);
					}
				}
			}
			det_a += *(A[0] + i) * (pow(-1, i)) * det(temp, n - 1);
		}
		return det_a;
	}
	else {
		return *A[0];
	}
}