#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s[1001];
	char* ptr;
	int count = 0;

	scanf("%[^\n]s", s);

	ptr = strchr(s, ' ');

	while (ptr != NULL)
	{
		count++;

		ptr = strchr(ptr + 1, ' ');
	}

	printf("%d\n", count);

	return 0;
}