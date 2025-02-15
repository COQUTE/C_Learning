#include <stdio.h>

int main()
{
	int num1 = 1;
	int num2 = 0;

	if (num1 && num2)
		printf("Âü\n");
	else
		printf("°ÅÁş\n");

	if (num1 || num2)
		printf("Âü\n");
	else
		printf("°ÅÁş\n");

	if (!num1)
		printf("Âü\n");
	else
		printf("°ÅÁş\n");

	return 0;
}