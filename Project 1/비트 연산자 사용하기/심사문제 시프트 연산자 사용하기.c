#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	unsigned long long num;

	scanf("%llu", &num);

	printf("%llu\n", num << 20 >> 4);

	return 0;
}