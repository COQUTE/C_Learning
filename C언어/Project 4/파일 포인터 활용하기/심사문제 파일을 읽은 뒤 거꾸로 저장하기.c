#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* fp = fopen("words.txt", "r");
	char* buffer;
	int size;

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);

	rewind(fp);

	buffer = malloc(size + 1);
	memset(buffer, 0, size + 1);

	fread(buffer, size, 1, fp);

	for (int i = size - 1; i >= 0; i--)
	{
		fwrite(&buffer[i], sizeof(char), 1, stdout);
	}

	fclose(fp);

	free(buffer);

	return 0;
}