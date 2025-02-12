#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c1 = 0;

	scanf("%c", &c1);

	if (c1 == 'a')
		printf("a입니다.\n");
	else
		printf("a가 아닙니다.\n");

	return 0;
}