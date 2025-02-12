#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[1001];
	int count = 0;
	char* ptr;

	scanf("%[^\n]s", s1);

	ptr = strchr(s1, ' ');

	while (ptr != NULL)
	{
		count++;

		ptr = strchr(ptr + 1, ' ');
	}

	printf("%d\n", count);

	return 0;
}