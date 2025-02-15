#include <stdio.h>

int main()
{
	char s1[10] = "Hello"; // 배열을 선언한 즉시 문자열로 초기화
						   // 배열을 미리 선언해놓고 문자열을 나중에 할당할 수 없다.

	printf("%s\n", s1);

	char s2[] = "Hello"; // 문자열을 할당할 때 배열의 크기를 생략하는 방법

	printf("%s\n", s2);

	return 0;
}