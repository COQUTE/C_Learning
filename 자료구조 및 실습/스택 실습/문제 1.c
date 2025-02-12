#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push(char* Stack, int N, int* top, char data)
{
	if (*top == N - 1)
	{
		printf("Stack FULL\n");

		return;
	}
	*top = *top + 1;
	Stack[*top] = data;
}

char pop(char* Stack, int* top)
{
	char data;

	if (*top == -1)
	{
		printf("Stack Empty\n");

		return '\0';
	}
	data = Stack[*top];
	*top = *top - 1;

	return data;
}

void peek(char* Stack, int top)
{
	if (top == -1)
	{
		printf("Stack Empty\n");

		return;
	}
	printf("%c\n", Stack[top]);
}

void duplicate(char* Stack, int N, int* top)
{
	char data;

	if (*top == N - 1)
	{
		printf("Stack FULL\n");

		return;
	}
	data = pop(Stack, top);

	push(Stack, N, top, data);
	push(Stack, N, top, data);
}

void upRotate1(char* Stack, int n, int top) // 배열 인덱스를 활용한 UpR
{
	char tmp;

	if (n > top + 1)
		return;

	for (int i = top; i > top - n + 1; i--)
	{
		tmp = Stack[i];
		Stack[i] = Stack[i - 1];
		Stack[i - 1] = tmp;
	}
}

void upRotate2(char* Stack, int N, int n, int top) // push, pop을 활용한 UpR
{
	char* arr;

	if (n > top + 1)
		return;

	arr = (char*)malloc(sizeof(char) * n);

	for (int i = 0; i < n; i++)
		arr[i] = pop(Stack, &top);

	for (int i = n; i >= 1; i--)
		push(Stack, N, &top, arr[i % n]);

	free(arr);
}

void downRotate1(char* Stack, int n, int top) // 배열 인덱스를 활용한 DownR
{
	char tmp;

	if (n > top + 1)
		return;

	for (int i = top - n + 1; i < top; i++)
	{
		tmp = Stack[i];
		Stack[i] = Stack[i + 1];
		Stack[i + 1] = tmp;
	}
}

void downRotate2(char* Stack, int N, int n, int top) // push, pop을 활용한 DownR
{
	char* arr;
	
	if (n > top + 1)
		return;

	arr = (char*)malloc(sizeof(char) * n);

	for (int i = 0; i < n; i++)
		arr[i] = pop(Stack, &top);

	for (int i = n - 2; i >= -1; i--)
		push(Stack, N, &top, arr[(i + n) % n]);

	free(arr);
}

void print(char* Stack, int top)
{
	for (int i = top; i >= 0; i--)
	{
		printf("%c", Stack[i]);
	}
	printf("\n");
}

int main()
{
	char* Stack, Type[6];
	int N, count, top = -1, n;
	char data;

	scanf("%d", &N);

	Stack = (char*)malloc(sizeof(char) * N);

	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		scanf("%s", Type);

		getchar();

		if (strcmp(Type, "POP") == 0)
			data = pop(Stack, &top);
		else if (strcmp(Type, "PUSH") == 0)
		{
			scanf("%c", &data);

			push(Stack, N, &top, data);
		}
		else if (strcmp(Type, "PEEK") == 0)
			peek(Stack, top);
		else if (strcmp(Type, "DUP") == 0)
			duplicate(Stack, N, &top);
		else if (strcmp(Type, "UpR") == 0)
		{
			scanf("%d", &n);

			upRotate2(Stack, N, n, top);
		}
		else if (strcmp(Type, "DownR") == 0)
		{
			scanf("%d", &n);

			downRotate2(Stack, N, n, top);
		}
		else if (strcmp(Type, "PRINT") == 0)
			print(Stack, top);
		else
			printf("invalid type\n");
	}

	free(Stack);

	return 0;
}