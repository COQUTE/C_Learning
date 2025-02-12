#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1 = 10;
	char c1 = 'a';
	int* numPtr1 = &num1;
	char* cPtr1 = &c1;

	void* ptr;

	ptr = numPtr1;
	ptr = cPtr1;

	numPtr1 = ptr;
	cPtr1 = ptr;

	return 0;
}