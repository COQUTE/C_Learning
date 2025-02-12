#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c1 = 0;

	scanf("%c", &c1);

	if (c1 != 'k')
		printf("Âü\n");
	else if (c1 == 'k')
		printf("°ÅÁþ\n");

	if (c1 > 'h')
		printf("Âü\n");
	else
		printf("°ÅÁþ\n");

	if (c1 <= 'o')
		printf("Âü\n");
	else
		printf("°ÅÁþ\n");

	return 0;
}