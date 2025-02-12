#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int opr;
	struct Stack* next;
}Stack;

Stack* getnode(char opr)
{
	Stack* ptr = (Stack*)malloc(sizeof(Stack));

	ptr->opr = (int)opr;
	ptr->next = NULL;

	return ptr;
}

void push(Stack** top, char opr)
{
	Stack* newnode = getnode(opr);

	newnode->next = *top;
	*top = newnode;
}

char pop(Stack** top)
{
	Stack* ptr;
	char opr;

	if (*top == NULL)
	{
		printf("Stack Empty\n");

		return '\0';
	}

	opr = (*top)->opr;
	ptr = *top;
	*top = (*top)->next;
	free(ptr);

	return opr;
}

int doOperator(Stack** top, char opt)
{
	int a, b, result;

	a = pop(top);
	b = pop(top);

	switch (opt)
	{
	case'*':
		return b * a;
	case'/':
		return b / a;
	case'+':
		return b + a;
	case'-':
		return b - a;
	}
}

int operate(char* str)
{
	Stack* top = NULL;
	int result;

	while (*str != '\0')
	{
		if (*str >= '0' && *str <= '9')
			push(&top, (*str) - 48);
		else
		{
			push(&top, doOperator(&top, *str));
		}

		str++;
	}

	result = pop(&top);

	return result;
}

int main()
{
	int N;
	char str[101];

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%s", str);
		printf("%d\n", operate(str));
	}

	return 0;
}