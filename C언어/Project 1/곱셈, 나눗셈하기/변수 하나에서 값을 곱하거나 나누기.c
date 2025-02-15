#include<stdio.h>

int main()
{
	int num1 = 2;
	int num2 = 7;

	num1 = num1 * 3; // num1 *= 3;과 같다.
	num2 = num2 / 2; // num2 /= 2;와 같다.

	printf("%d\n", num1);
	printf("%d\n", num2);

	return 0;
}