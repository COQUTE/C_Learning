#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int elem;
	struct NODE* next;
} NODE;

NODE* getnode(int elem)
{
	NODE* ptr = (NODE*)malloc(sizeof(NODE));

	ptr->elem = elem;
	ptr->next = NULL;

	return ptr;
}

void AddLast(NODE** cur, int elem) // 입력된 원소를 집합 가장 오른쪽에 추가해주는 함수 (함수 내에서 주솟값을 바꿔주기 위해서 이중포인터 사용)
{
	NODE* newnode = getnode(elem);

	(*cur)->next = newnode; // cur를 활용하여 가장 마지막에 새로운 노드를 삽입, 링크 조정 후 cur를 새로운 노드 위치로 바꿔줌
	*cur = newnode;
}

NODE* Set() // 집합 크기 N을 입력받고 N 크기의 집합을 만들어주는 함수
{
	NODE* H = getnode(0), * cur = H;

	int N, elem;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &elem);

		AddLast(&cur, elem);
	}

	return H;
}

NODE* Union(NODE* A_H, NODE* B_H) // 합집합의 헤더를 반환하는 함수
{
	NODE* H = getnode(0), * cur = H;

	while (A_H != NULL && B_H != NULL) // 둘 중 하나라도 NULL이 되면 종료
	{
		if (A_H->elem < B_H->elem) // A가 작으면 AddLast하고 A만 next 이동
		{
			AddLast(&cur, A_H->elem);

			A_H = A_H->next;
		}
		else if (A_H->elem > B_H->elem) // B가 작으면 AddLast하고 B만 next 이동
		{
			AddLast(&cur, B_H->elem);

			B_H = B_H->next;
		}
		else							// 같으면 AddLast하고 둘다 next 이동
		{
			AddLast(&cur, A_H->elem);

			A_H = A_H->next;
			B_H = B_H->next;
		}
	}

	// 남은 A 혹은 B를 끝까지 AddLast 해주고 종료

	while (A_H != NULL)
	{
		AddLast(&cur, A_H->elem);

		A_H = A_H->next;
	}

	while (B_H != NULL)
	{
		AddLast(&cur, B_H->elem);

		B_H = B_H->next;
	}

	return H;
}

NODE* Intersect(NODE* A_H, NODE* B_H) // 교집합의 헤더를 반환하는 함수
{
	NODE* H = getnode(0), * cur = H;

	while (A_H != NULL && B_H != NULL) // 둘 중 하나라도 NULL이 되면 종료
	{
		if (A_H->elem < B_H->elem) // A가 작으면 A만 next로 이동
			A_H = A_H->next;
		else if (A_H->elem > B_H->elem) // B가 작으면 B만 next로 이동
			B_H = B_H->next;
		else							// 같으면 AddLast하고 둘다 next로 이동
		{
			AddLast(&cur, A_H->elem);

			A_H = A_H->next;
			B_H = B_H->next;
		}
	}

	return H;
}

void Print_Result(NODE* H) // 공집합이면 0, 아니면 집합 전체를 출력하는 함수
{
	if (H->next == NULL)
		printf("0\n");
	else
	{
		while (H->next != NULL)
		{
			H = H->next;

			printf(" %d", H->elem);
		}

		printf("\n");
	}
}

void FreeMemory(NODE* L) // 메모리 해제 함수
{
	NODE* ptr = L, * tmp;

	while (ptr != NULL)
	{
		tmp = ptr;

		ptr = ptr->next;

		free(tmp);
	}
}

int main()
{
	NODE* A_H, * B_H;
	NODE* ptr;

	A_H = Set();
	B_H = Set();

	ptr = Union(A_H->next, B_H->next);

	Print_Result(ptr);
	FreeMemory(ptr);

	ptr = Intersect(A_H->next, B_H->next);

	Print_Result(ptr);
	FreeMemory(ptr);

	FreeMemory(A_H);
	FreeMemory(B_H);

	return 0;
}