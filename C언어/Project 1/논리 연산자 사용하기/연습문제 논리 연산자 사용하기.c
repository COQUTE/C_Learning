#include <stdio.h>

int main()
{
	int num1 = 10;
	int num2 = 0;

	if (num1 && num1)
		printf("Âü\n");
	else
		printf("°ÅÁş\n");

	if (num1 || num2)
		printf("Âü\n");
	else
		printf("°ÅÁş\n");

	printf("%s\n", !num2 ? "Âü" : "°ÅÁş");

	return 0;
}