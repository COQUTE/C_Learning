#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int elem;
	struct NODE* next;
}NODE, * NODE_PTR, ** NODE_DPTR;

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

	if (Rank < 1 || Rank >(*size) + 1) // add 함수 : 1 <= Rank <= (총 노드 개수 + 1)
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

NODE_PTR concat1(NODE_PTR L1, NODE_PTR L2, int* size1, int* size2) // 비재귀 O(size1) = L1의 크기만큼 실행시간 소요
{
	NODE_PTR ptr = L1;

	while (ptr->next != NULL)
		ptr = ptr->next;

	if (*size1 == 0)
		return L2;
	else if (*size2 == 0)
		return L1;
	else
	{
		ptr->next = L2;

		(*size1) = (*size1) + (*size2);

		return L1;
	}
}

NODE_PTR concat2(NODE_PTR L1, NODE_PTR L2, int* size1, int* size2) // 재귀
{
	if (*size1 == 0)
		return L2;
	else if (*size2 == 0)
		return L1;

	if (L1->next != NULL)
	{
		concat2(L1->next, L2, &size1, &size2);

		return L1;
	}
	else
	{
		L1->next = L2;

		(*size1) = (*size1) + (*size2);
	}
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
	NODE_PTR ptr;
	int size1 = 0, size2 = 0;

	initial(&L1, 2, &size1);
	initial(&L2, 4, &size2);

	add(&L1, 1, 1, &size1);
	add(&L2, 1, 3, &size2);

	ptr = concat2(&L1, &L2, &size1, &size2);

	for (; ptr != NULL; ptr = ptr->next)
		printf(" %d", ptr->elem);

	printf("\n%d %d\n", size1, size2);

	FreeMemory(L1);

	return 0;
}