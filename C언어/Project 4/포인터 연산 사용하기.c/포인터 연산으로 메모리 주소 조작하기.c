#include <stdio.h>

int main()
{
	int numArr[5] = { 11, 22, 33, 44, 55 };
	int* numPtrA;
	int* numPtrB;
	int* numPtrC;

	numPtrA = numArr;

	numPtrB = numPtrA + 1;
	numPtrC = numPtrA + 2;

	printf("%p\n", numPtrA);
	printf("%p\n", numPtrB);
	printf("%p\n", numPtrC);

	return 0;
}