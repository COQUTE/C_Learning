#include <stdio.h>

int main()
{
	unsigned char num1 = 1;
	unsigned char num2 = 3;

	printf("%d\n", num1 & num2);
	printf("%d\n", num1 | num2);
	printf("%d\n", num1 ^ num2);

	return 0;
}