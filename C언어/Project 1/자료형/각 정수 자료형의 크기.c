#include<stdio.h>

int main()
{
	printf("char: %d, short: %d, int: %d, long: %d, long long: %d\n",
		sizeof(char),
		sizeof(short),
		sizeof(int),
		sizeof(long),
		sizeof(long long)
	);

	return 0;
}