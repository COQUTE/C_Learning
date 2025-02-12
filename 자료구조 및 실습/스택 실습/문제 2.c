#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Stack {
	char elem;
	struct Stack* next;
}Stack;

void push(Stack** top, char elem)
{
	Stack* newnode = (Stack*)malloc(sizeof(Stack));

	newnode->elem = elem;
	newnode->next = *top;
	*top = newnode;
}

char pop(Stack** top)
{
	Stack* ptr;
	char elem;

	if (*top == NULL)
	{
		printf("Stack Empty\n");

		return '\0';
	}

	ptr = *top;
	elem = ptr->elem;

	*top = (*top)->next;

	free(ptr);

	return elem;
}

bool TopCheck(Stack** top, char x, int* cnt)
{
	(*cnt)++;

	if (*top == NULL)
		return false;
	else if (pop(top) != x)
		return false;
	
	return true;
}

void FreeMemory(Stack* top)
{
	Stack* tmp;
	
	while (top != NULL)
	{
		tmp = top;

		top = top->next;

		free(tmp);
	}
}

void evaluate(Stack* top, char* str)
{
	bool flag = true;
	int cnt = 0;

	while (*str != '\0')
	{
		if (flag == true)
		{
			if (*str == '(' || *str == '[' || *str == '{')
			{
				push(&top, *str);
				cnt++;
			}
			else if (*str == ')')
				flag = TopCheck(&top, '(', &cnt);
			else if (*str == ']')
				flag = TopCheck(&top, '[', &cnt);
			else if (*str == '}')
				flag = TopCheck(&top, '{', &cnt);
		}
		else
			if (*str == '(' || *str == '[' || *str == '{' || *str == ')' || *str == ']' || *str == '}')
				cnt++;
		str++;
	}

	if (flag == true && top == NULL)
		printf("OK_%d\n", cnt);
	else
		printf("Wrong_%d\n", cnt);
	
	if (top != NULL)
		FreeMemory(top);
}

int main()
{
	char str[1001];
	Stack* top = NULL;

	gets_s(str, sizeof(str));

	evaluate(top, str);

	return 0;
}