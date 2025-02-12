#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char text[100] = "this is c language";
	char* tokens[30] = { NULL, };
	int count = 0;

	char* ptr = strtok(text, " ");

	while (ptr != NULL)
	{
		tokens[count] = ptr;

		count++;

		ptr = strtok(NULL, " ");
	}

	for (int i = 0; i < count - 1; i++)
	{
		printf("%s %s\n", tokens[i], tokens[i + 1]);
	}

	return 0;
}