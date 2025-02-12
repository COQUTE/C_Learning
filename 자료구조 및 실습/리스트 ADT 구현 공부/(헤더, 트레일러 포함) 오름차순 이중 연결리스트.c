#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int elem;
	struct NODE* prev, * next;
} NODE;

NODE* getnode(int elem)
{
	NODE* ptr = (NODE*)malloc(sizeof(NODE));

	ptr->elem = elem;
	ptr->prev = ptr->next = NULL;

	return ptr;
}

void Initial(NODE** H, NODE** T)
{
	*H = getnode(0);
	*T = getnode(0);

	(*H)->next = *T;
	(*T)->prev = *H;
}

void add(NODE* H, NODE* T, int elem)
{
	NODE* ptr = H->next;
	NODE* newnode = getnode(elem);

	while (ptr->elem < elem && ptr != T)
		ptr = ptr->next;

	newnode->next = ptr;
	newnode->prev = ptr->prev;
	(ptr->prev)->next = newnode;
	ptr->prev = newnode;

	(H->elem)++;
	(T->elem)++;
}

void Remove(NODE* H, NODE* T, int Rank)
{

}

int main()
{


	return 0;
}