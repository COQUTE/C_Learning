#include <stdio.h>

int main()
{
	char s1[10] = "Hello";

	s1[0] = 'A'; // 배열 형태의 문자열은 인덱스로 접근하여 내용을 변경할 수 있다.

	printf("%s\n", s1);

	return 0;
}