#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isPalindrome(char* arr, int FirstIndex, int LastIndex)
{
	if (FirstIndex >= LastIndex)
		return true;
	else if (arr[FirstIndex] == arr[LastIndex])
		return isPalindrome(arr, FirstIndex + 1, LastIndex - 1);
	else
		return false;
}

int main()
{
	char* arr;
	int N;

	scanf("%d", &N);

	arr = malloc(sizeof(char) * (N + 1));

	getchar();

	scanf("%[^\n]s", arr);

	printf("%d\n", isPalindrome(arr, 0, strlen(arr) - 1));

	free(arr);

	return 0;
}