#include <stdio.h>
#include <stdlib.h>

void allocMemory(void** ptr, int size)
{
	*ptr = malloc(size);
}

int main()
{
	long long* numPtr;

	allocMemory(&numPtr, sizeof(long long));

	*numPtr = 10;
	printf("%lld\n", numPtr);

	free(numPtr);

	return 0;
}