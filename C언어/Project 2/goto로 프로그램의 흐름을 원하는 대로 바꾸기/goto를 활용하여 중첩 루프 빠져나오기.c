#include <stdio.h>

int main()
{
	int num1 = 0;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (num1 == 20)
				goto EXIT;

			num1++;
		}
	}

EXIT:
	printf("%d\n", num1);

	return 0;
}