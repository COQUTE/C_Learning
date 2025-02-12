#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char* ptr = malloc(sizeof(char) * 61);

	scanf("%s", ptr);

	ptr = strtok(ptr, ".");

	while (ptr != NULL)
	{
		printf("%s\n", ptr);

		ptr = strtok(NULL, ".");
	}
	
	free(ptr);

	return 0;
}