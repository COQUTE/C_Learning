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

void AddLast(NODE** start, NODE** cur, int elem) // 입력된 원소를 집합 가장 오른쪽에 추가해주는 함수 (함수 내에서 주솟값을 바꿔주기 위해서 이중포인터 사용)
{
	NODE* newnode = getnode(elem);

	if (*start == NULL) // 집합이 비어있을 경우 start와 cur를 초기화
	{
		*start = *cur = newnode;

		return;
	}
	
	(*cur)->next = newnode; // cur를 활용하여 가장 마지막에 새로운 노드를 삽입, 링크 조정 후 cur를 새로운 노드 위치로 바꿔줌
	*cur = newnode;
}

NODE* Set() // 집합 크기 N을 입력받고 N 크기의 집합을 만들어주는 함수
{
	NODE* start = NULL, * cur = NULL;

	int N, elem;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &elem);

		AddLast(&start, &cur, elem);
	}

	return start;
}

int subset(NODE* A, NODE* B) // A가 B의 부분집합인지 판단하는 함수
{
	while (A != NULL && B != NULL) // B가 NULL이거나 A가 NULL일 때까지 반복
	{
		if (A->elem == B->elem) // A와 B의 원소가 같을 경우 A, B 모두 next로 이동
		{
			A = A->next;
			B = B->next;
		}
		else					// 그렇지 않은 경우 B만 next로 이동
			B = B->next;
	}

	// A와 B가 모두 비교된 이후 A가 NULL인지 아닌지 판단

	if (A != NULL) // A가 NULL이 아니면 이미 B와 같다고 판명난 원소들은 지나쳤기 때문에 B에 포함되지 않은 현재 A의 위치에 있는 원소 출력
		return A->elem;
	else		   // NULL이면 A가 B의 부분집합이니까 0 출력
		return 0;
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
	NODE* A = NULL, * B = NULL;
	int result;

	A = Set();
	B = Set();

	result = subset(A, B);

	printf("%d\n", result);

	FreeMemory(A);
	FreeMemory(B);

	return 0;
}