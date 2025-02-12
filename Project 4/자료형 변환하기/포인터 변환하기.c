#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* numPtr = malloc(sizeof(int));
	char* cPtr;

	*numPtr = 0x12345678;

	cPtr = (char*)numPtr;

	printf("0x%x\n\n", *cPtr);

	free(numPtr);

	short* numPtr1 = malloc(sizeof(short));
	int* numPtr2;

	*numPtr1 = 0x1234;

	numPtr2 = (int*)numPtr1;

	printf("0x%x\n", *numPtr2);

	free(numPtr1);

	return 0;
}