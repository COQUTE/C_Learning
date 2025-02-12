#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int substr1(char* str, char* sub)
{
	if (strstr(str, sub) != NULL)
		return strstr(str, sub) - str;
	else
		return -1;
}

int substr2(char* str, char* sub)
{
	int count = 0;
	char* cmpstr, * cmpsub; // str과 sub의 첫 문자가 같아졌을 경우, 그 위치부터 하나씩 비교하는 임의의 포인터 cmpstr, cmpsub를 사용했다.

	if (*sub == NULL)
		return -1;

	while (*str != NULL)
	{
		if (*str == *sub)
		{
			cmpstr = str + 1;
			cmpsub = sub + 1;

			while (1)
			{
				if (*cmpsub == NULL)
					return count;
				else if (*cmpstr != *cmpsub)
					break;
				else
				{
					cmpstr++;
					cmpsub++;
				}
			}
		}

		str++;
		count++;
	}

	return -1;
}

int main()
{
	printf("%d\n", substr1("maximum", "ax"));

	printf("%d\n", substr1("over the rainbow", "rain"));

	printf("%d\n", substr2("over the rainbow", "r t"));

	printf("%d\n", substr2("bacacarcary", "car"));

	printf("%d\n", substr2("bacacarcary", "cam"));

	return 0;
}