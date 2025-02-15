#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int count = 0;

	scanf("%d", &count);

	int i = 0;

	do
	{
		printf("Hello, world! %d\n", i);
		i++;
	} while (i < count);
	
	return 0;
}