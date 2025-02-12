#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s[1001];
	char* ptr;
	int count = 0;

	scanf("%[^\n]s", s);

	ptr = strtok(s, " ,.");

	while (ptr != NULL)
	{
		if (strcmp(ptr, "the") == 0)
			count++;

		ptr = strtok(NULL, " ,.");
	}

	printf("%d\n", count);

	return 0;
}