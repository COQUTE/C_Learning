#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[10] = { 0, };

	FILE* fp = fopen("hello.txt", "r");

	fseek(fp, 2, SEEK_SET);
	fread(buffer, 3, 1, fp);

	printf("%s\n", buffer);

	memset(buffer, 0, 10);

	fseek(fp, 3, SEEK_CUR);
	fread(buffer, 4, 1, fp);

	printf("%s\n", buffer);

	fclose(fp);

	return 0;
}