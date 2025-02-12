#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int m, n;

	scanf("%d %d", &m, &n);

	char **matrix = malloc(sizeof(char*) * m);

	for (int i = 0; i < m; i++)
	{
		matrix[i] = malloc(sizeof(char) * (n + 1));
	
		scanf("%s", matrix[i]);
	}

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (matrix[i][j] != '*')
			{
				matrix[i][j] = 48;

				for (int chk1 = i - 1; chk1 <= i + 1; chk1++)
				{
					for (int chk2 = j - 1; chk2 <= j + 1; chk2++)
					{
						if (chk1 < 0 && chk2 < 0)
						{
							chk1++;
							chk2++;
						}
						else if (chk1 > m - 1)
							break;
						else if (chk1 < 0)
							chk1++;
						else if (chk2 < 0)
							chk2++;
						else if (chk2 > n - 1)
							continue;
						
						if (matrix[chk1][chk2] == '*')
							matrix[i][j]++;
					}
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