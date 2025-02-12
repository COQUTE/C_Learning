#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int num1, int num2)
{
	if (num2 == 0)
		return num1;
	else
		return gcd(num2, num1 % num2);
}

int main()
{
	int num1, num2;

	scanf("%d %d", &num1, &num2);

	printf("%d\n", gcd(num1, num2));

	return 0;
}