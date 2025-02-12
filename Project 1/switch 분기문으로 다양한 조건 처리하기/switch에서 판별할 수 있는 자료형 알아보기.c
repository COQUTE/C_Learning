#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char c1;

	scanf("%c", &c1);

	switch(c1)
	{
		case 'a':
			printf("a입니다.\n");
			break;
		case 'b':
			printf("b입니다.\n");
		default:
			printf("default\n");
			break;
	}

	return 0;
}