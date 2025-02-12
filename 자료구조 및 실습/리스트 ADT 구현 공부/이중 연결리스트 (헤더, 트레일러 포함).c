#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	struct NODE* prev, * next;
	char Alpabet;
}NODE, *NODE_PTR, **NODE_DPTR;

NODE_PTR getnode(char Alpabet)
{
	NODE_PTR ptr;
	
	ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->Alpabet = Alpabet;

	return ptr;
}

void initial(NODE_DPTR H, NODE_DPTR T)
{
	*H = getnode('0');
	*T = getnode('0');

	(*H)->next = *T;
	(*T)->prev = *H;

	(*H)->Alpabet = (*H)->Alpabet - 48; // ASCII 코드를 사용해서 헤더와 트레일러의 요소 Alpabet을 노드의 개수(헤더와 트레일러를 제외한)로 활용
	(*T)->Alpabet = (*T)->Alpabet - 48;
}

NODE_PTR MoveNextNode(NODE_PTR H, int Rank) // 헤더에서 시작해서 next로 계속 이동하여 노드를 반환
{
	NODE_PTR ptr = H;

	for (int i = 0; i < Rank; i++)
		ptr = ptr->next;

	return ptr;
}

NODE_PTR MovePrevNode(NODE_PTR T, int Rank) // 트레일러에서 시작해서 prev로 계속 이동하여 노드를 반환
{
	NODE_PTR ptr = T;

	for (int i = 0; i < (T->Alpabet + 1) - Rank; i++) // (전체 노드 개수 + 1) - 원하는 위치 = 트레일러로 부터 이동 횟수
		ptr = ptr->prev;							  // add : 추가하고 싶은 위치 다음 노드로 이동, delete : 삭제하고 싶은 위치 노드로 이동

	return ptr;
}

NODE_PTR isHalf(NODE_PTR H, NODE_PTR T, int Rank, int RankRange) // Rank가 절반 이하인지 이상인지 확인해주는 함수
{
	if (Rank <= RankRange / 2)		// 절반 이하 순위에 추가할 경우 헤더 활용
		return MoveNextNode(H, Rank);
	else							// 절반 이상 순위에 추가할 경우 트레일러 활용
		return MovePrevNode(T, Rank);
}

void Add(NODE_PTR H, NODE_PTR T, int Rank, char Alpabet) // 기준되는 노드(ptr) 좌측에 노드 삽입
{
	NODE_PTR ptr;
	NODE_PTR newnode;

	if (Rank < 1 || Rank > (H->Alpabet) + 1)
		printf("invalid position\n");
	else
	{
		ptr = isHalf(H, T, Rank, (H->Alpabet) + 1);

		newnode = getnode(Alpabet);

		newnode->next = ptr;
		newnode->prev = ptr->prev;
		(ptr->prev)->next = newnode;
		ptr->prev = newnode;

		(H->Alpabet)++;
		(T->Alpabet)++;
	}
}

void Delete(NODE_PTR H, NODE_PTR T, int Rank)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > (H->Alpabet))
		printf("invalid position\n");
	else
	{
		ptr = isHalf(H, T, Rank, H->Alpabet);

		(ptr->prev)->next = ptr->next;
		(ptr->next)->prev = ptr->prev;

		free(ptr);

		(H->Alpabet)--;
		(T->Alpabet)--;
	}
}

char Get(NODE_PTR H, NODE_PTR T, int Rank)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > (H->Alpabet))
		printf("invalid position\n");
	else
	{
		ptr = isHalf(H, T, Rank, H->Alpabet);

		printf("%c\n", ptr->Alpabet);

		return ptr->Alpabet;
	}
}

void Set(NODE_PTR H, NODE_PTR T, int Rank, char Alpabet)
{
	NODE_PTR ptr;

	if (Rank < 1 || Rank > (H->Alpabet))
		printf("invalid position\n");
	else
	{
		ptr = isHalf(H, T, Rank, H->Alpabet);

		ptr->Alpabet = Alpabet;
	}
}

void Print(NODE_PTR H, NODE_PTR T)
{
	NODE_PTR ptr = H->next;

	while (ptr != T)
	{
		printf("%c", ptr->Alpabet);

		ptr = ptr->next;
	}

	printf("\n");
}

void FreeMemory(NODE_PTR H) //메모리 해제 함수 
{
	NODE_PTR ptr = H, tmp;

	while (ptr != NULL)
	{
		tmp = ptr;

		ptr = ptr->next;

		free(tmp);
	}
}

void TotalFunction()
{
	NODE_PTR H, T;
	int N, Rank;
	char Type, Alpabet;

	initial(&H, &T);

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		getchar();

		scanf("%c", &Type);

		if (Type == 'A')
		{
			scanf("%d %c", &Rank, &Alpabet);

			Add(H, T, Rank, Alpabet);
		}
		else if (Type == 'D')
		{
			scanf("%d", &Rank);

			Delete(H, T, Rank);
		}
		else if (Type == 'G')
		{
			scanf("%d", &Rank);

			Alpabet = Get(H, T, Rank);
		}
		else if (Type == 'P')
		{
			Print(H, T);
		}
		else
			printf("invalid type\n");
	}

	FreeMemory(H);
}

int main()
{
	TotalFunction();

	return 0;
}