#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int findPivot(int l, int r);
void inPlacePartition(int L[], int l, int r, int k, int* a, int* b);
int* inPlaceQuickSort(int L[], int l, int r);
void print(int L[], int n);

int main() {
	int* L;
	int n;

	scanf("%d", &n);

	L = (int*)malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++)
		scanf("%d", &L[i]);

	inPlaceQuickSort(L, 0, n - 1);

	print(L, n);

	free(L);

	return 0;
}

int findPivot(int l, int r) {
	srand(time(NULL));

	return rand() % (r - l + 1) + l;
}

void inPlacePartition(int L[], int l, int r, int k, int* a, int* b) {
	int pivot = L[k];
	int tmp, i, j;

	tmp = L[k];
	L[k] = L[r];
	L[r] = tmp;
	
	i = l;
	j = r - 1;

	while (i <= j) {
		// L[i]가 pivot과 같으면 i가 증가하지 않게 설정
		while (L[i] < pivot)
			i++;
		// L[j]는 pivot과 같아도 j가 감소
		while (L[j] >= pivot)
			j--;
		if (i < j) {
			tmp = L[i];
			L[i] = L[j];
			L[j] = tmp;
		}
	}

	tmp = L[i];
	L[i] = L[r];
	L[r] = tmp;

	*a = i;

	// a부터 시작해서 pivot과 중복된 값을 가진 마지막 인덱스까지 이동
	while (L[i + 1] == pivot)
		i++;

	*b = i;
}

int* inPlaceQuickSort(int L[], int l, int r) {
	int k;
	int a, b;

	if (l >= r)
		return;
	
	k = findPivot(l, r);
	inPlacePartition(L, l, r, k, &a, &b);
	inPlaceQuickSort(L, l, a - 1);
	inPlaceQuickSort(L, b + 1, r);
}

void print(int L[], int n) {
	for (int i = 0; i < n; i++)
		printf(" %d", L[i]);

	printf("\n");
}