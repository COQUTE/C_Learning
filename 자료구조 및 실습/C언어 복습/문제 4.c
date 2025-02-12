#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char str[101];
	char tmp;
	int length;

	scanf("%s", str);

	length = strlen(str);

	for (int i = 0; i < length; i++)
	{
		printf("%s\n", str);

		for (int j = 0; j < length - 1; j++)
		{
			tmp = str[j];
			str[j] = str[j + 1];
			str[j + 1] = tmp;
		}
	}

	return 0;
}