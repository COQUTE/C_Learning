#include <stdio.h>

int main()
{
	int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

	for (int i = 0; i < sizeof(numArr) / sizeof(int); i++) /* 역순으로 반복하려면
														   for (int i = sizeof(numArr) / sizeof(int) - 1; i >= 0; i--) 이런 식으로 작성 */
	{
		printf("%d\n", numArr[i]);
	}

	return 0;
}