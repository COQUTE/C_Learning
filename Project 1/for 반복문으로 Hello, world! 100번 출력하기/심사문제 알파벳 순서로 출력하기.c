#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c = 0;

	scanf("%c", &c);

	for (; c <= 'z'; c++)
	{
		printf("%c", c);
	}

	return 0;
}