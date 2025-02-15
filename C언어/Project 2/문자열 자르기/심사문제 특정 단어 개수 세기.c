#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char* ptr = malloc(sizeof(char) * 1001);
	int count = 0;

	scanf("%[^\n]s", ptr);

	ptr = strtok(ptr, " ,.");

	while (ptr != NULL)
	{
		if (strcmp(ptr, "the") == 0)
			count++;

		ptr = strtok(NULL, " ,.");
	}

	printf("%d\n", count);

	free(ptr);

	return 0;
}