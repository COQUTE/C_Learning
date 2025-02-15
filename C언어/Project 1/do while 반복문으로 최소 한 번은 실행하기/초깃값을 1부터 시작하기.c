#include <stdio.h>

int main()
{
	int i = 1;

	do
	{
		printf("Hello, world! %d\n", i);
		i++;
	} while (i <= 100);

	return 0;
}