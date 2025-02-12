#include <stdio.h>
#include <string.h>

int main()
{
	char* s1 = "Hello";
	char s2[10] = "Hello";

	printf("%d\n", strlen(s1));
	printf("%d\n", strlen(s2));

	return 0;
}