#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int m, n;

	scanf("%d %d", &m, &n);

	char** matrix = malloc(sizeof(char*) * m);

	for (int i = 0; i < m; i++)
	{
		matrix[i] = malloc(sizeof(char) * (n + 1));

		memset(matrix[i], 0, sizeof(char) * (n + 1));

		scanf("%s", matrix[i]);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] == '*')
			{
				printf("%c", matrix[i][j]);
				continue;
			}
			else
				matrix[i][j] = 48;

			for (int chk1 = i - 1; chk1 <= i + 1; chk1++)
			{
				for (int chk2 = j - 1; chk2 <= j + 1; chk2++)
				{
					if (chk1 < 0 || chk1 >= m || chk2 < 0 || chk2 >= n)
						continue;
					else if (matrix[chk1][chk2] == '*')
						matrix[i][j]++;
				}
			}

			printf("%c", matrix[i][j]);
		}

		printf("\n");
	}

	for (int i = 0; i < m; i++)
	{
		free(matrix[i]);
	}

	free(matrix);

	return 0;
}