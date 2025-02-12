#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE {
	struct NODE* next;
	int Element;
}NODE, *NODE_PTR, **NODE_DPTR;

void InvalidRank()
{
	printf("invalid position\n");	//입력된 rank가 범위 밖일 경우 예외 발생
}

void InvalidType()
{
	printf("invalid type\n"); //입력된 type과 맞는 함수가 존재하지 않을 경우 예외 발생
}

NODE_PTR getnode(int Element)
{
	NODE_PTR ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->next = NULL;
	ptr->Element = Element;

	return ptr;
}

NODE_PTR initial(int FirstElement, int* NodeCount) // 초기화 함수
{
	NODE_PTR ptr = getnode(FirstElement);

	(*NodeCount)++; // 포인터의 참조값으로 노드의 개수를 셈

	return ptr;
}

NODE_PTR MoveNode(NODE_PTR ptr, int Rank) // Rank만큼 노드의 위치를 순방향으로 이동
{
	for (int i = 0; i < Rank; i++)
	{
		ptr = ptr->next;
	}

	return ptr;
}

void add(NODE_PTR L, int Rank, int Element, int* NodeCount) // 노드 추가 함수
{
	NODE_PTR ptr = L;
	NODE_PTR newnode;
	
	if (Rank < 1 || Rank > *NodeCount) // 1 <= Rank <= NodeCount (처음에 노드 추가하는 addfirst 제외 즉, Rank는 2부터 유효)
		InvalidRank();
	else // 만약 add 안에 addfirst를 포함하고 싶다면 else if를 활용해서 Rank == 1일 경우에 addfirst를 실행하면 됨
	{
		ptr = MoveNode(ptr, Rank - 2); // 추가해야할 노드 위치 바로 앞 노드를 알고 싶기 때문에 Rank - 2 만큼 움직임

		newnode = getnode(Element);

		newnode->next = ptr->next;
		ptr->next = newnode;

		(*NodeCount)++;
	}
}

void addfirst(NODE_DPTR L, int Element , int* NodeCount) // 단일 연결리스트에서 처음에 노드를 추가하기 위해서는 L의 값이 바뀌어야 하기 때문에 add와 구분
{
	NODE_PTR newnode = getnode(Element);

	newnode->next = *L;
	*L = newnode;

	(*NodeCount)++;
}

int get(NODE_PTR L, int Rank, int NodeCount) // Rank 위치 노드의 요소를 반환하는 함수
{
	NODE_PTR ptr = L;

	if (Rank < 1 || Rank > NodeCount)
		InvalidRank();
	else
	{
		ptr = MoveNode(ptr, Rank - 1);

		printf("%d\n", ptr->Element);

		return ptr->Element;
	}
}

void Remove(NODE_PTR L, int Rank, int* NodeCount) // 노드 제거 함수
{
	NODE_PTR ptr, before;

	if (Rank < 0 || Rank > (*NodeCount))
		InvalidRank();
	else
	{
		ptr = MoveNode(L, Rank - 1);

		before = MoveNode(L, Rank - 2);
		
		before->next = ptr->next;

		free(ptr);

		(*NodeCount)--;
	}
}

void removefirst(NODE_DPTR L, int* NodeCount) // 단일 연결리스트에서 처음에 노드를 제거하기 위해서는 L의 값이 바뀌어야 하기 때문에 remove와 구분
{
	NODE_PTR tmp = *L;
	
	*L = (*L)->next;

	free(tmp);

	(*NodeCount)--;
}

void set(NODE_PTR L, int Rank, int Element) // Rank 위치 노드에 Element 값을 대입하는 함수
{
	NODE_PTR ptr = L;

	ptr = MoveNode(ptr, Rank - 1);

	ptr->Element = Element;
}

void traverse(NODE_PTR L) // 모든 노드를 순회하는 함수
{
	NODE_PTR ptr = L;

	while (ptr != NULL)
	{
		printf(" %d", ptr->Element);

		ptr = ptr->next;
	}

	printf("\n");
}

void putnode(NODE_PTR L)
{
	NODE_PTR ptr = L;
	NODE_PTR tmp;

	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;

		free(tmp);
	}
}

void TotalFunction()
{
	NODE_PTR L;
	int NodeCount = 0; // 일단, 전체 노드의 개수를 함수에 저장
	int N, Rank, Element;
	char Type[3];

	L = initial(1, &NodeCount);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		getchar();

		scanf("%s", Type);

		if (strcmp(Type, "A") == 0)
		{
			scanf("%d %d", &Rank, &Element);

			add(L, Rank, Element, &NodeCount);
		}
		else if (strcmp(Type, "AF") == 0)
		{
			scanf("%d", &Element);

			addfirst(&L, Element, &NodeCount);
		}
		else if (strcmp(Type, "G") == 0)
		{
			scanf("%d", &Rank);

			Element = get(L, Rank, NodeCount);
		}
		else if (strcmp(Type, "S") == 0)
		{
			scanf("%d %d", &Rank, &Element);

			set(L, Rank, Element);
		}
		else if (strcmp(Type, "R") == 0)
		{
			scanf("%d", &Rank);

			Remove(L, Rank, &NodeCount);
		}
		else if (strcmp(Type, "RF") == 0)
		{
			removefirst(&L, &NodeCount);
		}
		else if (strcmp(Type, "P") == 0)
		{
			traverse(L);
		}
		else
			InvalidType();
	}

	putnode(L);
}

int main()
{
	TotalFunction();

	return 0;
}