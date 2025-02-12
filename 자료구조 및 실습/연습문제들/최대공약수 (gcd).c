#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd1(int a, int b)
{
	if (b == 0)
		return a;
	else
		return gcd1(b, a % b);
}

int gcd2(int a, int b)
{
	if (a == b)
		return a;
	else if (a > b)
		return gcd2(a - b, b);
	else if (a < b)
		return gcd2(a, b - a);
}

int main()
{
	printf("%d %d %d\n", gcd1(48, 16), gcd1(78, 104), gcd1(368, 138));
	printf("%d %d %d\n", gcd2(48, 16), gcd2(78, 104), gcd2(368, 138));

	return 0;
}