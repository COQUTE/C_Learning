#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	unsigned int num1 = 0, num2 = 0;

	scanf("%d %d", &num1, &num2);

	printf("%u\n", num1 ^ num2);
	printf("%u\n", num1 | num2);
	printf("%u\n", num1 & num2);
	printf("%u\n", ~num1);

	return 0;
}