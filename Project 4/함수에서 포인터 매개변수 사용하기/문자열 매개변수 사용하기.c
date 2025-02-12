#include <stdio.h>

void helloString(char* s1)	// void helloString(char s1[]): 이런 식으로 char 배열을 매개변수로 지정해도
							// 배열뿐만 아니라 문자열이나 메모리가 할당된 포인터도 전달할 수 있다.
{
	printf("Hello, %s\n", s1);
}

int main()
{
	helloString("world!");

	return 0;
}