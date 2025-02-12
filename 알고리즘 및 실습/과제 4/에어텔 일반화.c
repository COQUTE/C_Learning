#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <Windows.h>

int MAX = 25; // 너무 느려서 절반값으로 측정

int rAirtel(int s, int d, int A[], int H[]) {
	int mincost = 99999, cost;

	if (s == d)
		return 0;
	for (int k = s; k < d; k++) {
		cost = rAirtel(s, k, A, H) + A[d - k];
		if (k != s)
			cost += H[k];
		mincost = min(mincost, cost);
	}
	// 최소비용경로상 모든 항공편의 요금 + 최소비용경로상 모든 경유도시들의 호텔비 계산
	return mincost;
}
int airtelDC(int n, int s, int d, int A[], int H[]) {
	// 최종 도착도시의 호텔비 계산
	return rAirtel(s, d, A, H) + H[d];
}

int airtelDP(int n, int s, int d, int A[], int H[]) {
	int* m = (int*)malloc(sizeof(int) * n);
	int mincost, cost;

	m[s] = 0;
	for (int i = s + 1; i <= d; i++) {
		m[i] = 99999;
		for (int k = s; k < i; k++) {
			cost = m[k] + A[i - k];
			if (k != s)
				cost += H[k];
			m[i] = min(m[i], cost);
		}
	}
	// 최소비용경로상 모든 항공편의 요금 + 최소비용경로상 모든 경유도시들의 호텔비 계산
	mincost = m[d];

	free(m);

	// 최종 도착도시의 호텔비 계산
	return mincost + H[d];
}

int main() {
	int A[25], H[25];
	int n, s, d;
	int mincost;

	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;

	QueryPerformanceFrequency(&ticksPerSec);

	A[0] = 0; A[1] = 1;
	for (int i = 2; i < MAX; i++)
		A[i] = A[i - 1] + (A[i - 1] % 5) + 3;
	H[0] = 0; H[1] = 5;
	for (int i = 2; i < MAX; i++)
		H[i] = (H[i - 1] + i) % 9 + 1;

	n = 6;
	for (int i = 0; i <= 2; i++) {
		switch(i) {
		case 0:
			s = 0; d = 4;
			break;
		case 1:
			s = 2; d = 5;
			break;
		case 2:
			s = 2; d = 4;
			break;
		}
		
		QueryPerformanceCounter(&start);
		mincost = airtelDC(n, s, d, A, H);
		QueryPerformanceCounter(&end);
		diff.QuadPart = end.QuadPart - start.QuadPart;
		printf("%-4d %-4d %-4d %-4d DC %14.8f\n", n, s, d, mincost, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

		QueryPerformanceCounter(&start);
		mincost = airtelDP(n, s, d, A, H);
		QueryPerformanceCounter(&end);
		diff.QuadPart = end.QuadPart - start.QuadPart;
		printf("%-4d %-4d %-4d %-4d DP %14.8f\n", n, s, d, mincost, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);
	}

	n = MAX;
	s = 1; d = n - 2;
	
	QueryPerformanceCounter(&start);
	mincost = airtelDC(n, s, d, A, H);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%-4d %-4d %-4d %-4d DC %14.8f\n", n, s, d, mincost, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	QueryPerformanceCounter(&start);
	mincost = airtelDP(n, s, d, A, H);
	QueryPerformanceCounter(&end);
	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%-4d %-4d %-4d %-4d DP %14.8f\n", n, s, d, mincost, ((double)diff.QuadPart / (double)ticksPerSec.QuadPart) * 1000);

	return 0;
}