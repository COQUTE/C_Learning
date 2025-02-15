#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	char s[31];

	int begin;
	int end;

	bool ox = true;

	scanf("%[^\n]s", s);

	begin = 0;
	end = strlen(s) - 1;

	while (begin < end)
	{
		while (s[begin] == ' ')
			begin++;

		while (s[end] == ' ')
			end--;

		if (s[begin] != s[end])
		{
			ox = false;
			break;
		}

		begin++;
		end--;
	}

	printf("%d\n", ox);

	return 0;
}