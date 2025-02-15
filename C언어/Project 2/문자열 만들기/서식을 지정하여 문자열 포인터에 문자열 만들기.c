#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	char* s1 = malloc(sizeof(char) * 20);
	char* s2 = malloc(sizeof(char) * 30);

	sprintf(s1, "Hello, %s", "world!");

	printf("%s\n", s1);

	sprintf(s2, "%c %d %f %e", 'a', 10, 3.2f, 1.123456e-21f);

	printf("%s\n", s2);

	free(s1);
	free(s2);

	return 0;
}