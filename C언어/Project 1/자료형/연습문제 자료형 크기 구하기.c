#include<stdio.h>

int main()
{
	long long num1;
	short num2;
	
	printf("%d\n", sizeof(num1) + sizeof(num2) + sizeof(int));

	return 0;
}