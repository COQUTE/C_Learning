#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	srand(time(NULL));

	int i = 0;

	do
	{
		i = rand() % 10;

		printf("%d\n", i);
	} while (i != 3);

	return 0;
}