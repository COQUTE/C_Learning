#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int Sum(int num)
{
	if (num == 1)
		return 1;

	return num + Sum(num - 1);
}

int main()
{
	int num;

	scanf("%d", &num);

	printf("%d\n", Sum(num));

	return 0;
}