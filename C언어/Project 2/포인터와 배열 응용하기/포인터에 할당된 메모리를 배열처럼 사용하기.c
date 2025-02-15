#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr = malloc(sizeof(int) * 10);

	numPtr[0] = 10;
	numPtr[9] = 20;

	printf("%d\n", numPtr[0]);
	printf("%d\n", numPtr[9]);

	free(numPtr);

	return 0;
}