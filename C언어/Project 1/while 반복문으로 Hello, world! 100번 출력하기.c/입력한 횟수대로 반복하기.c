#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int count;

	scanf("%d", &count);

	int i = 0;

	while (i < count)
	{
		printf("Hello, world! %d\n", i);
		i++;
	}

	return 0;
}