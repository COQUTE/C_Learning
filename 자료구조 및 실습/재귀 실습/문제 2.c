#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void PrintHighToLow(int num)
{
	if (num < 10)
		printf("%d\n", num);
	else
	{
		PrintHighToLow(num / 10); // 3408 > 340 > 34 > 3 : (print) 3 > 34 % 10 > 340 % 10 > 3408 %10
		printf("%d\n", num % 10);
	}
}

int main()
{
	int num;

	scanf("%d", &num);

	PrintHighToLow(num);

	return 0;
}