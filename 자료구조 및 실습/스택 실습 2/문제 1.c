#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
	int rank;
	char opt;
	struct Stack* next;
} Stack;

Stack* getnode(char opt)
{
	Stack* newnode = (Stack*)malloc(sizeof(Stack));

	newnode->next = NULL;
	newnode->opt = opt;

	return newnode;
}

int rank(char* str, int i)
{
	if (str[i] == '!' || ((str[i] == '+' || str[i] == '-') && (i == 0 || ((str[i - 1] < 'A' || str[i - 1] > 'Z') && str[i - 1] != ')'))))
		return 6;
	else if (str[i] == '*' || str[i] == '/')
		return 5;
	else if (str[i] == '+' || str[i] == '-')
		return 4;
	else if (str[i] == '>' || str[i] == '<')
		return 3;
	else if (str[i] == '&')
		return 2;
	else if (str[i] == '|')
		return 1;
	else if (str[i] == '(')
		return 0;
}

void push(Stack** top, char* str, int i)
{
	Stack* newnode = getnode(str[i]);

	newnode->rank = rank(str, i);

	newnode->next = *top;
	*top = newnode;
}

char pop(Stack** top)
{
	Stack* tmp;
	char opt;

	if (*top == NULL)
		return '\0';

	tmp = *top;
	opt = (*top)->opt;
	*top = (*top)->next;

	free(tmp);

	return opt;
}

void isLogic(char opt)
{
	if (opt == '&' || opt == '|')
		printf("%c%c", opt, opt);
	else
		printf("%c", opt);
}

void convert(char* str)
{
	Stack* top = NULL;
	
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			printf("%c", str[i]);
		else if (str[i] == '(')
			push(&top, str, i);
		else if (str[i] == ')')
		{
			while (top->opt != '(')
				isLogic(pop(&top));
			pop(&top);
		}
		else
		{
			while (top != NULL && rank(str, i) <= top->rank)
				isLogic(pop(&top));
			push(&top, str, i);

			if (str[i] == '&' || str[i] == '|')
				i++;
		}
	}

	while (top != NULL)
		isLogic(pop(&top));

	printf("\n");
}

int main()
{
	char str[101];
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);

		convert(str);
	}

	return 0;
}