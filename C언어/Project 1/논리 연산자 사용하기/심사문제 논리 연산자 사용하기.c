#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num1 = 0, num2 = 0;

	scanf("%d %d", &num1, &num2);

	if (num1 && num2)
		printf("Âü\n");
	else
		printf("°ÅÁş\n");

	if (num1 || num2)
		printf("Âü\n");
	else
		printf("°ÅÁş\n");

	if (!num1)
		printf("Âü\n");
	else
		printf("°ÅÁş\n");

	return 0;
}