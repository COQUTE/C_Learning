#include <stdio.h>
#include <stdbool.h>

int main()
{
	int num1 = 0;

	bool exitOuterLoop = false;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (num1 == 20)
			{
				exitOuterLoop = true;
				break;
			}

			num1++;
		}

		if (exitOuterLoop == true)
			break;
	}

	printf("%d\n", num1);

	return 0;
}