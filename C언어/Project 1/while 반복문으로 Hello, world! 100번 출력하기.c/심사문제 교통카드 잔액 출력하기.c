#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int money = 0, pay = 1200;

	scanf("%d", &money);

	while (money - pay >= 0)
	{
		money -= pay;

		printf("%d\n", money);
	}

	return 0;
}