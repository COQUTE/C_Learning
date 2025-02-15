#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main()
{
	char sinput[31];
	char scpy[31];

	char* tokens[20] = { NULL, };
	char* token;

	int count = 0;
	int begin;
	int end;

	bool ox = true;

	scanf("%[^\n]s", sinput);

	token = strtok(sinput, " ");

	while (token != NULL)
	{
		tokens[count] = token;
		count++;

		token = strtok(NULL, " ");
	}

	strcpy(scpy, tokens[0]);

	for (int i = 1; i < count; i++)
		strcat(scpy, tokens[i]);

	begin = 0;
	end = strlen(scpy) - 1;

	while (begin < end)
	{
		if (scpy[begin] != scpy[end])
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