#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int count = 0;

	scanf("%d", &count);

	for (int i = 1; i <= count; i++)
	{
		if (i % 2 != 0)
			continue;

		printf("%d\n", i);
	}

	return 0;
}