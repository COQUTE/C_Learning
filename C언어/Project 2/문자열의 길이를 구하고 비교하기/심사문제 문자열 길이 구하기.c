#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s1[31];

	scanf("%s", s1);

	int length = strlen(s1);

	printf("%d\n", length);

	return 0;
}