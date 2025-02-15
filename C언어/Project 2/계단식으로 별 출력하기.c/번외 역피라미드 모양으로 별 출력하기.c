#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int height = 0;

	scanf("%d", &height);

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");
		}

		for (int j = height; j > 0; j--)
		{
			if (j > i)
				printf("*");
		}

		for (int j = height - 1; j > i; j--)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}