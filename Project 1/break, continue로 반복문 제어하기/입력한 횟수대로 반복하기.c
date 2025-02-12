#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int count = 0;

	scanf("%d", &count);

	int i = 1;

	while (1)
	{
		printf("%d\n", i);
		
		if (i == count)
			break;

		i++;
	}

	return 0;
}