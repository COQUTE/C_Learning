#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char buffer[20];

	FILE* fp = fopen("hello.txt", "r");

	fgets(buffer, sizeof(buffer), fp);

	printf("%s\n", buffer);

	fclose(fp);

	return 0;
}