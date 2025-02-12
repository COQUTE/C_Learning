#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	char* str;
	struct NODE* next;
} NODE;

NODE* getnode(char str[]) {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));

	ptr->next = NULL;
	ptr->str = str;

	return ptr;
}

void push(NODE** top, char str[]) {
	NODE* newnode = getnode(str);

	newnode->next = *top;
	*top = newnode;
}

void pop(NODE** top, char** result) {
	NODE* ptr;
	if (*top == NULL)
	{
		printf("Empty\n");

		return;
	}
	*result = (*top)->str;
	ptr = *top;
	*top = (*top)->next;
	free(ptr);
}

int main()
{
	NODE* top = NULL;
	char str[16], * result;

	while (strcmp(str, "*") != 0)
	{
		scanf("%s", str);

		if (strcmp(str, "*") != 0)
			push(&top, str);
	}

	while (top != NULL)
	{
		pop(&top, &result);

		printf("%s\n", result);
	}

	return 0;
}