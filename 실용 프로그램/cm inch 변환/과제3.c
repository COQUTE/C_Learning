#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct _MATRIX {
	double** m_data;
	int m_size;
} MATRIX;

void initMatrix(MATRIX* A, int n);					// 동적배열 생성
void deleteMatrix(MATRIX* A);						// 동적배열 해제
void inputMatrix(MATRIX* A);						// 행렬 값 입력
void printMatrix(MATRIX matrix);					// 행렬 값 출력
double determinant(MATRIX matrix);					// 행렬식 계산
MATRIX transpose(MATRIX matrix);					// 전치행렬 계산
MATRIX minorMatrix(MATRIX matrix, int col, int row);// 소행렬식 계산
MATRIX cofactorMatrix(MATRIX matrix);				// 여인자행렬 계산
MATRIX adjoint(MATRIX matrix);						// 수반행렬 계산
MATRIX inverseMatrix(MATRIX matrix);				// 역행렬 계산

int main() {
	MATRIX matrix;
	MATRIX inverse;

	int n = 8;
	double det = 0;

	initMatrix(&matrix, n);
	initMatrix(&inverse, n);

	inputMatrix(&matrix);

	det = determinant(matrix);

	inverse = inverseMatrix(matrix);

	printMatrix(inverse);
	printf("\n");

	deleteMatrix(&matrix);
	deleteMatrix(&inverse);

	return 0;
}

void initMatrix(MATRIX* A, int n) {
	int i = 0;

	A->m_data = (double**)malloc(sizeof(double*) * n);

	for (i = 0; i < n; i++) {
		A->m_data[i] = (double*)malloc(sizeof(double) * n);
	}

	A->m_size = n;
}

void deleteMatrix(MATRIX* A) {
	int i = 0;

	for (i = 0; i < A->m_size; i++) {
		free(A->m_data[i]);
	}
	free(A->m_data);
}

void inputMatrix(MATRIX* A) {
	int i = 0, j = 0;
	double input = 0;

	for (i = 0; i < A->m_size; i++) {
		for (j = 0; j < A->m_size; j++) {
			fflush(stdin);
			scanf("%lf", &input);
			A->m_data[i][j] = input;
		}
	}
}

void printMatrix(MATRIX matrix) {
	int i = 0, j = 0;

	for (i = 0; i < matrix.m_size; i++) {
		for (j = 0; j < matrix.m_size; j++) {
			printf("\t%.3f", matrix.m_data[i][j]);
		}
		printf("\n");
	}
}

double determinant(MATRIX matrix) {
	int i = 0;
	double det = 0;
	int sign = 1;

	if (matrix.m_size == 2) {
		det = matrix.m_data[0][0] * matrix.m_data[1][1] - matrix.m_data[1][0] * matrix.m_data[0][1];
		
		return det;
	}

	for (i = 0; i < matrix.m_size; i++) {
		MATRIX minor;
		initMatrix(&minor, matrix.m_size);

		minor = minorMatrix(matrix, 0, i);
		det = det + sign * matrix.m_data[i][0] * determinant(minor);
		sign = sign * -1;
	}

	return det;
}

MATRIX transpose(MATRIX matrix) {
	MATRIX Result;
	int i, j;

	initMatrix(&Result, matrix.m_size);

	for (i = 0; i < matrix.m_size; i++) {
		for (j = 0; j < matrix.m_size; j++) {
			Result.m_data[i][j] = matrix.m_data[j][i];
		}
	}

	return Result;
}

MATRIX minorMatrix(MATRIX matrix, int col, int row) {
	MATRIX Result;
	int i, j;
	int rowIndex = 0;
	int colIndex = 0;

	initMatrix(&Result, matrix.m_size - 1);

	for (i = 0; i < matrix.m_size; i++) {
		for (j = 0; j < matrix.m_size; j++) {
			if (i != row && j != col) {
				Result.m_data[rowIndex][colIndex] = matrix.m_data[i][j];
				colIndex++;
			}
		}

		if (i != row && j != col) {
			colIndex = 0;
			rowIndex++;
		}
	}

	return Result;
}

MATRIX cofactorMatrix(MATRIX matrix) {
	MATRIX Result;
	int i, j;

	initMatrix(&Result, matrix.m_size);

	for (i = 0; i < matrix.m_size; i++) {
		for (j = 0; j < matrix.m_size; j++) {
			Result.m_data[j][i] = determinant(minorMatrix(matrix, i, j));
		}
	}

	return Result;
}

MATRIX adjoint(MATRIX matrix) {
	MATRIX Result;
	MATRIX confactor;
	MATRIX transposed;
	int i, j;
	double ipow = 1;

	initMatrix(&Result, matrix.m_size);
	initMatrix(&confactor, matrix.m_size);
	initMatrix(&transposed, matrix.m_size);

	confactor = cofactorMatrix(matrix);
	transposed = transpose(confactor);

	for (i = 0; i < matrix.m_size; i++) {
		for (j = 0; j < matrix.m_size; j++) {
			ipow = pow(-1, (i + j));
			Result.m_data[i][j] = ipow * transposed.m_data[i][j];
		}
	}
	deleteMatrix(&confactor);
	deleteMatrix(&transposed);

	return Result;
}

MATRIX inverseMatrix(MATRIX matrix) {
	MATRIX Result;
	MATRIX temp;
	double det;
	int i, j;

	det = determinant(matrix);

	initMatrix(&temp, matrix.m_size);
	initMatrix(&Result, matrix.m_size);

	if (matrix.m_size == 2) {
		temp.m_data[0][0] = matrix.m_data[1][1];
		temp.m_data[1][1] = matrix.m_data[0][0];
		temp.m_data[0][1] = -(matrix.m_data[0][1]);
		temp.m_data[1][0] = -(matrix.m_data[1][0]);

		for (i = 0; i < matrix.m_size; i++) {
			for (j = 0; j < matrix.m_size; j++) {
				Result.m_data[i][j] = (double)((double)1 / det) * temp.m_data[i][j];
			}	
		}
		deleteMatrix(&temp);

		return Result;
	}

	temp = adjoint(matrix);

	for (i = 0; i < matrix.m_size; i++) {
		for (j = 0; j < matrix.m_size; j++) {
			Result.m_data[i][j] = (double)((double)1 / det) * temp.m_data[i][j];
		}
	}
	deleteMatrix(&temp);

	return Result;
}