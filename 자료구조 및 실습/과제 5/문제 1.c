#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	char opt;
	struct NODE* next;
} NODE;

NODE* getnode(char opt)
{
	NODE* ptr = (NODE*)malloc(sizeof(NODE));

	ptr->next = NULL;
	ptr->opt = opt;

	return ptr;
}

void push(NODE** top, char opt)
{
	NODE* newnode = getnode(opt);

	newnode->next = *top;
	*top = newnode;
}

char pop(NODE** top)
{
	NODE* tmp;
	char opt;

	if (*top == NULL)
		return '\0';

	opt = (*top)->opt;
	tmp = *top;
	*top = (*top)->next;

	free(tmp);

	return opt;
}

int Operator(char opt)
{
	if (opt == '*' || opt == '/')
		return 2;
	else if (opt == '+' || opt == '-')
		return 1;
	else if (opt == '(')
		return 0;
}

void convert(char* arr, NODE* top)
{
	while (*arr != '\0')
	{
		if (*arr >= 'A' && *arr <= 'Z')
			printf("%c", *arr);
		else if (*arr == '(')
			push(&top, *arr);
		else if (*arr == ')')
		{
			while (top->opt != '(')
				printf("%c", pop(&top));
			pop(&top);
		}
		else
		{
			while (top != NULL && Operator(top->opt) >= Operator(*arr))
				printf("%c", pop(&top));
			push(&top, *arr);
		}
		arr++;
	}

	while (top != NULL)
		printf("%c", pop(&top));

	printf("\n");
}

int main()
{
	NODE* top = NULL;
	char arr[101];
	int num;

	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		getchar();
		scanf("%s", arr);

		convert(arr, top);
	}

	return 0;
}