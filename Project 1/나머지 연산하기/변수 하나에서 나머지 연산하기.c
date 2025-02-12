#include <stdio.h>

int main()
{
	int num1 = 7;

	num1 = num1 % 2; // num1 %= 2;와 같다. (num1에 2를 나눈 뒤 나머지를 구하여 다시 num1에 저장)

	printf("%d\n", num1);

	return 0;
}