#include <stdio.h>

int main()
{
	unsigned char flag = 0;

	flag |= 1; // 마스크와 비트 OR로 여덟 번째 비트를 켬
	flag |= 2; // 마스크와 비트 OR로 일곱 번째 비트를 켬
	flag |= 4; // 마스크와 비트 OR로 여섯 번째 비트를 켬

	printf("%u\n", flag);

	if (flag & 1)
		printf("0000 0001은 켜져 있음\n");
	else
		printf("0000 0001은 꺼져 있음\n");

	if (flag & 2)
		printf("0000 0010은 켜져 있음\n");
	else
		printf("0000 0010은 꺼져 있음\n");

	if (flag & 4)
		printf("0000 0100은 켜져 있음\n");
	else
		printf("0000 0100은 꺼져 있음\n");

	return 0;
}