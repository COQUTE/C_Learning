#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE { // 항의 계수, 항의 차수, 이전&다음 노드를 가리키는 링크를 가지는 노드 구조체 선언
	int coef, exp;
	struct NODE* prev, * next;
} NODE;

void initial(NODE** H, NODE** T) // 헤더와 트레일러의 이중 포인터를 인자로 받아 NODE만큼 메모리를 할당하고 각각의 링크를 초기화
{
	*H = (NODE*)malloc(sizeof(NODE));
	*T = (NODE*)malloc(sizeof(NODE));

	(*H)->next = *T;
	(*T)->prev = *H;

	(*H)->prev = NULL;
	(*T)->next = NULL;
}

NODE* getnode(int coef, int exp) // 노드 생성
{
	NODE* ptr = (NODE*)malloc(sizeof(NODE));

	ptr->prev = NULL;
	ptr->next = NULL;
	ptr->coef = coef;
	ptr->exp = exp;

	return ptr;
}

void arrayAddTerm(NODE* H, NODE* T, int coef, int exp) // 입력되는 노드의 exp 값과 기존 노드에 있던 exp 값을 비교하며 next로 나아가서 원하는 위치에 노드를 삽입하는 함수
{
	NODE* ptr = H->next; // 헤더에는 값이 없기 때문에 next부터 비교하기 위한 변수 선언
	NODE* newnode;

	while (exp <= ptr->exp && ptr != T) // ptr의 차수와 입력된 차수를 비교해서 ptr을 최대 트레일러를 넘지 않는 선에서 이동시킴
	{
		if (exp == ptr->exp) // 차수가 같을 경우 계수를 더함
		{
			ptr->coef = ptr->coef + coef;

			if (ptr->coef == 0) // 더했을 때 계수가 0이 되면 노드의 링크를 조정하고 메모리 해제
			{
				(ptr->prev)->next = ptr->next;
				(ptr->next)->prev = ptr->prev;

				free(ptr);
			}

			return; // 차수가 같으면 더 진행할 필요가 없기 때문에 리턴
		}

		ptr = ptr->next;
	}

	newnode = getnode(coef, exp); // 차수가 같을 경우가 있기 때문에 나중에 메모리 할당 및 값 입력

	newnode->next = ptr;
	newnode->prev = ptr->prev;
	(ptr->prev)->next = newnode;
	ptr->prev = newnode;
}

void Print(NODE* L) // L부터 프린트를 시작
{
	while (L != NULL)
	{
		printf(" %d %d", L->coef, L->exp);

		L = L->next;
	}

	printf("\n");
}

void FreeMemory(NODE* H) // H부터 시작해서 NULL이 될 때까지 next로 옮겨가며 메모리를 해제해주는 함수
{
	NODE* tmp;

	while (H != NULL)
	{
		tmp = H;

		H = H->next;

		free(tmp);
	}
}

void compareAddTerm(NODE** start, NODE** cur, int coef, int exp) // 현재 노드와 입력된 계수를 비교해서 (계수가 같다면 차수로 비교해서) 원하는 위치에 새로운 노드 삽입하는 함수
{
	NODE* newnode = getnode(coef, exp);

	if (*start == NULL) // 아무 노드도 없는 경우
	{
		*start = newnode;
		*cur = *start;

		return;
	}

	if ((*cur)->coef < newnode->coef) // 입력된 계수가 기존 계수보다 큰 경우
	{
		newnode->next = *cur; // 현재 노드의 이전 노드가 무조건 NULL이 됨 (시작 노드를 새로운 노드로 변경)
		(*cur)->prev = newnode;
		*start = newnode;
	}
	else if ((*cur)->coef > newnode->coef) // 입력된 계수가 기존 계수보다 작은 경우
	{
		while ((*cur)->next != NULL) // 현재 노드의 다음 노드가 NULL이 아닐 경우 반복
		{
			if ((*cur)->next->coef < newnode->coef) // 현재 노드의 다음 노드의 계수가 입력된 계수보다 작은 경우, 새로운 노드를 현재 노드 다음에 삽입
			{										
				newnode->next = (*cur)->next;
				newnode->prev = *cur;
				(*cur)->next->prev = newnode;
				(*cur)->next = newnode;

				return;
			}

			*cur = (*cur)->next;
		}

		newnode->prev = *cur; // 현재 노드의 다음 노드가 NULL일 경우 링크 조정
		(*cur)->next = newnode;
	}
	else // 입력된 계수가 기존 계수와 같은 경우
	{
		if ((*cur)->exp > newnode->exp) // 현재 노드의 차수가 입력된 차수보다 클 때
		{
			if ((*cur)->next != NULL) // 현재 노드의 다음 노드가 NULL일 아닐 경우
			{
				newnode->prev = *cur;
				newnode->next = (*cur)->next;
				(*cur)->next->prev = newnode;
				(*cur)->next = newnode;

				return;
			}
			else // 현재 노드의 다음 노드가 NULL일 경우
			{
				newnode->prev = *cur;
				(*cur)->next = newnode;

				return;
			}
		}

		if ((*cur)->exp < newnode->exp) // 현재 노드의 차수가 입력된 차수보다 작을 때
		{
			newnode->next = *cur; // 현재 노드의 이전 노드는 무조건 NULL이 됨 (시작 노드를 새로운 노드로 변경)
			(*cur)->prev = newnode;
			*start = newnode;
		}
	}
}

NODE* extract(NODE* H, NODE* T) // 계수를 기준으로 내림차순으로 정렬한 후 정렬된 이중연결리스트의 헤드 노드를 반환하는 함수
{
	NODE* start = NULL, * cur = NULL; // 시작 노드와 유동적인 노드를 각각 선언
	NODE* ptr = H->next; // H->next 부터 시작해서 값을 비교해주는 ptr선언
	
	while (ptr != T)
	{
		compareAddTerm(&start, &cur, ptr->coef, ptr->exp);

		cur = start; // 비교하기 전에 유동적인 노드 cur 값이 항상 첫 노드로 설정되기 때문에
					 // 비교할 때 cur 보다 계수가 크거나, 계수가 같으면서 차수가 큰 항은 무조건 cur 왼쪽에 위치하게 됨
		ptr = ptr->next;
	}

	return start;
}

int main()
{
	NODE* H, * T;
	NODE* L; // 헤더 트레일러가 없는 이중연결리스트의 헤드 노드 L
	int count, coef, exp;

	initial(&H, &T);

	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		scanf("%d %d", &coef, &exp);

		arrayAddTerm(H, T, coef, exp);
	}

	L = extract(H, T);

	Print(L);

	FreeMemory(H);
	FreeMemory(L);

	return 0;
}