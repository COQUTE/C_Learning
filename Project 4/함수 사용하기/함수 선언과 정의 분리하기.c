#include <stdio.h>

void hello(); // hello 함수 원형 선언

int main()
{
	hello();

	return 0;
}

void hello() // hello 함수 정의
{
	printf("Hello, world\n");
}