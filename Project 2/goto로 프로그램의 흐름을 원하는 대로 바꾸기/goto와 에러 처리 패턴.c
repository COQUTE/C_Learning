#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int gender;
	int age;
	int isOwner;

	scanf("%d %d %d", &gender, &age, &isOwner);

	printf("안녕하세요.\n");
	printf("문을 연다.\n");

	// goto를 사용하면 중복 코드를 없앨 수 있고, 코드의 의도도 명확해짐.

	if (gender == 2)
	{
		printf("안녕히계세요.\n");
		printf("문을 닫는다.\n");
		return 0;
	}

	if (age < 30)
	{
		printf("안녕히계세요\n");
		printf("문을 닫는다.\n");
		return 0;
	}

	if (isOwner == 0)
	{
		printf("안녕히계세요.\n");
		printf("문을 닫는다.\n");
		return 0;
	}

	return 0;
}