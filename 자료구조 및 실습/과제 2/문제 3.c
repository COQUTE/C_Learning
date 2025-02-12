#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isPalindrome(char* str, int FirstIndex, int LastIndex)
{
	if (FirstIndex >= LastIndex)
		return -1;
	else if (str[FirstIndex] == str[LastIndex])
		return isPalindrome(str, FirstIndex + 1, LastIndex - 1);
	else
		return 0;
}

int main()
{
	char str[101];
	int YorN;

	scanf("%[^\n]s", str);

	printf("%d\n", strlen(str));

	YorN = isPalindrome(str, 0, strlen(str) - 1);

	if (YorN == -1)
		printf("Yes\n");
	else
		printf("No\n");

	return 0;
}