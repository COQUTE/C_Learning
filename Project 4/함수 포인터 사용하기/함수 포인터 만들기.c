#include <stdio.h>

void hello()
{
	printf("Hello, world!\n");
}

void bonjour()
{
	printf("bonjour le monde!\n");
}

int main()
{
	void (*fp)();

	fp = hello;
	fp();

	fp = bonjour;
	fp();

	return 0;
}