#include<stdio.h>
#include<limits.h>

int main()
{
	char num1 = CHAR_MAX;
	short num2 = SHRT_MAX;
	int num3 = INT_MAX;
	long num4 = LONG_MAX;
	long long num5 = LLONG_MAX;

	printf("%d %d %d %ld %lld\n", num1, num2, num3, num4, num5);

	return 0;
}