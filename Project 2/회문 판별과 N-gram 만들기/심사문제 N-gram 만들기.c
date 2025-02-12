#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	char s[11];

	scanf("%d %s", &n, s);
	
	if (strlen(s) < n)
		printf("wrong\n");
	else
	{
		for (int i = 0; i < strlen(s) - (n - 1); i++)
		{
			for (int j = 0; j < n; j++)
				printf("%c", s[i + j]);

			printf("\n");
		}
	}

	return 0;
}