#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	char s[31];
	bool tf = true;
	int start, end;

	scanf("%[^\n]s", s);

	start = 0;
	end = strlen(s) - 1;

	while (start < end)
	{
		if (s[start] == ' ' && s[end] == ' ')
		{
			start++;
			end--;
		}
		else if (s[start] == ' ')
			start++;
		else if (s[end] == ' ')
			end--;
		else if (s[start] != s[end])
		{
			tf = false;
			break;
		}

		start++;
		end--;
	}

	printf("%d\n", tf);

	return 0;
}