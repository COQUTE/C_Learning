#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int height = 0;

	scanf("%d", &height);

	// 먼저 피라미드를 절반으로 나누어서 생각함 (먼저 가로, 세로를 보면 둘 다 높이와 같다.) 높이를 기준으로 중첩 루프를 작성

	for (int i = 0; i < height; i++)
	{
		for (int j = height - 1; j >= 0; j--) /* 1) 공백을 기준으로 작성하는데 공백이 감소함 (j를 감소하는 형태로 만듬)
											     2) 첫줄은 공백 4개, 별 1개이므로 시작을 height - 1로 잡음										
												 3) 마지막은 공백 0개, 별 5개이므로 마지막을 0으로 잡음*/
		{
			if (j > i)
				printf(" ");
			else
				printf("*");
		}

		for (int j = 0; j < i; j++) // 마찬가지로 별을 기준으로 작성하면 된다.
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}