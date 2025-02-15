#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num1;

	scanf("%d", &num1);

	if (num1 == 1)
		goto ONE;
	else if (num1 == 2)
		goto TWO;
	else
		goto EXIT;

ONE:
	printf("1입니다.\n");
	goto EXIT;

TWO:
	printf("2입니다.\n");
	goto EXIT;

EXIT:
	return 0;
}