#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Hanoi(int n, char from, char aux, char to)
{
	if (n == 1)
	{
		printf("%c %c\n", from, to);
		return;
	}
	
	Hanoi(n - 1, from, to, aux); // 맨 아래 원반을 제외한 n - 1개의 원반을 출발 말뚝 -> 보조 말뚝
	
	printf("%c %c\n", from, to); // 출발 말뚝 -> 목표 말뚝
	
	Hanoi(n - 1, aux, from, to); // n - 1개의 원반을 보조 말뚝 -> 목표 말뚝

	return;
}

int main()
{
	int N;

	scanf("%d", &N);

	Hanoi(N, 'A', 'B', 'C');

	return 0;
}