#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n;
	char** s;

	scanf("%d %d", &m, &n);

	s = malloc(sizeof(char*) * m);

	for (int i = 0; i <	m; i++)
	{
		s[i] = malloc(sizeof(char) * (n + 1));

		scanf("%s", s[i]);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (s[i][j] == '*')
			{
				printf("%c", s[i][j]);
				continue;
			}
			else
				s[i][j] = 48;

			for (int ck1 = i - 1; ck1 <= i + 1; ck1++)
			{
				for (int ck2 = j - 1; ck2 <= j + 1; ck2++)
				{
					if (ck1 < 0 || ck1 == m || ck2 < 0 || ck2 == n)
						continue;
					else if (s[ck1][ck2] == '*')
						s[i][j]++;
				}
			}

			printf("%c", s[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < m; i++)
	{
		free(s[i]);
	}

	free(s);

	return 0;
}