#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	FILE* fp = fopen("hello.txt", "w");

	fputs("Hello, world!", fp);

	fclose(fp);

	return 0;
}