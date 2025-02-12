#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s[11];
	
	int length;
	int n;

	scanf("%d %s", &n, s);

	length = strlen(s);

	for (int i = 0; i < length - (n - 1); i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%c", s[i + j]);
		}

		printf("\n");
	}

	return 0;
}