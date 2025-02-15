#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int korea = 0, english = 0, math = 0, sciense = 0;
	int arg = 0;

	scanf("%d %d %d %d", &korea, &english, &math, &sciense);

	arg = (korea + english + math + sciense) / 4;

	if (korea < 0 || korea > 100 || english < 0 || english > 100 || math < 0 || math > 100 || sciense < 0 || sciense > 100)
		printf("잘못된 점수\n");

	else
	{
		if (arg >= 85)
		{
			printf("합격\n");
		}

		else
		{
			printf("불합격\n");
		}
	}

	return 0;
}