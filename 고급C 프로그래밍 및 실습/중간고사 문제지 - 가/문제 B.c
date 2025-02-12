#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char s1[30];
	char s2[30];
	int count = 0;

	memset(s2, NULL, sizeof(char) * 30);

	scanf("%s", s1);

	for (int i = 0; i < strlen(s1); i++)
	{
		for (int j = i + 1; j < strlen(s1); j++)
		{
			if (s1[i] == s1[j])
				s1[j] = ' ';
		}
	}

	for (int i = 0; i < strlen(s1); i++)
	{
		if (s1[i] != ' ')
		{
			s2[count] = s1[i];
			count++;
		}
	}

	printf("%s\n", s2);

	return 0;
}