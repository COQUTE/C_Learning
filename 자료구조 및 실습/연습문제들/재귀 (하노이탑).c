#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void Hanoi(int N, char from, char aux, char to)
{
	if (N == 1)
	{
		printf("%c %c\n", from, to);

		return;
	}
	else
	{
		Hanoi(N - 1, from, to, aux);

		printf("%c %c\n", from, to);

		Hanoi(N - 1, aux, from, to);

		return;
	}
}

int main()
{
	int N;

	scanf("%d", &N);
	Hanoi(N, 'A', 'B', 'C');

	return 0;
}