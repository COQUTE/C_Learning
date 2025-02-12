#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE {
	int elem;
	struct NODE* next;
}NODE, *NODE_PTR, **NODE_DPTR;

NODE_PTR getnode(int elem)
{
	NODE_PTR ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->elem = elem;
	ptr->next = NULL;

	return ptr;
}

void initial(NODE_DPTR L, int elem, int* size)
{
	*L = getnode(elem);

	(*size)++;
}

NODE_PTR MoveNode(NODE_PTR L, int Rank)
{
	NODE_PTR ptr = L;

	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	return ptr;
}

void add(NODE_DPTR L, int Rank, int elem, int* size)
{
	NODE_PTR ptr;
	NODE_PTR newnode;

	if (Rank < 1 || Rank > (*size) + 1) // add 함수 : 1 <= Rank <= (총 노드 개수 + 1)
		printf("invalid position\n");
	else if (Rank == 1) // Rank가 1일 경우, L의 포인터 값이 변경돼야함
	{
		newnode = getnode(elem);

		newnode->next = *L;
		*L = newnode;

		(*size)++;
	}
	else
	{
		ptr = MoveNode(*L, Rank - 2); // ptr 오른쪽에 노드 삽입

		newnode = getnode(elem);

		newnode->next = ptr->next;
		ptr->next = newnode;

		(*size)++;
	}
}

bool equal1(NODE_PTR L1, NODE_PTR L2) // 비재귀
{
	NODE_PTR cmp1 = L1, cmp2 = L2;

	while (cmp1 != NULL)
	{
		if (cmp1->elem != cmp2->elem)
			return false;
		else
		{
			cmp1 = cmp1->next;
			cmp2 = cmp2->next;
		}
	}

	return true;
}

bool equal2(NODE_PTR L1, NODE_PTR L2) // 재귀
{
	if (L1 == NULL)
		return true;
	else if (L1->elem != L2->elem)
		return false;
	else
		return equal2(L1->next, L2->next);
}

void FreeMemory(NODE_PTR L)
{
	NODE_PTR ptr = L, tmp;

	while (ptr != NULL)
	{
		tmp = ptr;

		ptr = ptr->next;

		free(tmp);
	}
}

int main()
{
	NODE_PTR L1, L2;
	int size1 = 0, size2 = 0;
	bool isEqual;

	initial(&L1, 1, &size1);
	initial(&L2, 1, &size2);

	add(&L1, 1, 2, &size1);
	add(&L2, 1, 2, &size2);

	if (size1 != size2)
		isEqual = false;
	else
	{
		isEqual = equal1(L1, L2);
		printf("%d\n", isEqual);

		isEqual = equal2(L1, L2);
		printf("%d\n", isEqual);
	}
	FreeMemory(L1);
	FreeMemory(L2);

	return 0;
}