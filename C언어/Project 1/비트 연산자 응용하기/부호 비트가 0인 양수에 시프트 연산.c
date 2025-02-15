#include <stdio.h>

int main()
{
	char num1 = 67;
	char num2;

	num2 = num1 >> 5;

	printf("%d\n", num2); // 2: 0000 0010: 모자라는 공간은 부호 비트의 값인 0으로 채워지므로 0000 0010이 됨

	return 0;
}