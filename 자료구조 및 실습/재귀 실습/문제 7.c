#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int CheckText(char Text, char CheckText)
{
	if (Text == CheckText)
		return 1;
	else
		return 0;
}

int CountText(char str[], char Text, int Length)
{
	if (Length == 1)
		return CheckText(str[0], Text);
	else
		return CheckText(str[Length - 1], Text) + CountText(str, Text, Length - 1);
}

int main()
{
	char str[101];
	char Text;

	scanf("%s %c", str, &Text);

	printf("%d\n", CountText(str, Text, strlen(str)));

	return 0;
}