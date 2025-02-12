#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	char Alpabet;
	struct NODE* next;
}NODE, *NODE_PTR, **NODE_DPTR;

NODE_PTR getnode(char Alpabet)
{
	NODE_PTR ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->Alpabet = Alpabet;
	ptr->next = NULL;

	return ptr;
}

void initial(NODE_DPTR H)
{
	*H = getnode('0');
}

NODE_PTR copy(NODE_PTR H)
{
	NODE_PTR OldH = H;
	NODE_PTR NewH = getnode(H->Alpabet);
	NODE_PTR newnode, tmp = NewH;

	while (OldH->next != NULL)
	{
		OldH = OldH->next;

		newnode = getnode(OldH->Alpabet);

		tmp->next = newnode;

		tmp = tmp->next;
	}

	return NewH;
}

void add(NODE_PTR H, int Rank, char element, int* size)
{
	NODE_PTR ptr = H;
	NODE_PTR newnode;

	if (Rank < 1 || Rank > (*size) + 1)
		printf("invalid position\n");
	else
	{
		for (int i = 0; i < Rank - 1; i++)
			ptr = ptr->next;

		newnode = getnode(element);

		newnode->next = ptr->next;
		ptr->next = newnode;

		(*size)++;
	}
}

void FreeMemory(NODE_PTR H)
{
	NODE_PTR ptr = H;
	NODE_PTR tmp;

	while (ptr != NULL)
	{
		tmp = ptr;

		ptr = ptr->next;

		free(tmp);
	}
}

int main()
{
	NODE_PTR H, H_copy;
	int size = 0;

	initial(&H);

	add(H, 1, 'a', &size);
	add(H, 2, 'b', &size);
	add(H, 3, 'c', &size);

	for (NODE_PTR ptr = H->next; ptr != NULL; ptr = ptr->next)
	{
		printf(" %c", ptr->Alpabet);
	}

	printf("\n");

	H_copy = copy(H);

	for (NODE_PTR ptr = H_copy->next; ptr != NULL; ptr = ptr->next)
	{
		printf(" %c", ptr->Alpabet);
	}

	printf("\n");

	FreeMemory(H);
	FreeMemory(H_copy);

	return 0;
}