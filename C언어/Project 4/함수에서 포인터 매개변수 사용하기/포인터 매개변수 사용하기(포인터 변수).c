#define OUT
#include <stdio.h>

void swapNumber(OUT int* first,OUT int* second)
{
	int temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

int main()
{
	int num1 = 10;
	int num2 = 20;

	swapNumber(&num1, &num2);

	printf("%d %d\n", num1, num2);

	return 0;
}