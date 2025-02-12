#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE { // 항의 계수, 항의 차수, 이전&다음 노드를 가리키는 링크를 가지는 노드 구조체 선언
	int coef, exp; 
	struct NODE* prev, *next;
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

void appendTerm(NODE* T, int coef, int exp) // 리스트의 맨 뒤에 추가하기 위해서 트레일러를 활용
{
	NODE* newnode = (NODE*)malloc(sizeof(NODE)); // newnode에 노드를 생성하고 coef와 exp 값을 입력

	newnode->coef = coef;
	newnode->exp = exp;

	newnode->next = T; // 링크들을 순서대로 이어줌
	newnode->prev = T->prev;
	(T->prev)->next = newnode;
	T->prev = newnode;
}

void Print(NODE* H, NODE* T) // 헤더 next부터 프린트를 시작
{
	NODE* ptr = H->next;

	while (ptr != T) // 트레일러에 도착하면 반복문 종료
	{
		printf(" %d %d", ptr->coef, ptr->exp);

		ptr = ptr->next;
	}

	printf("\n");
}

int reversePrint(NODE* H, NODE* T) // 트레일러의 prev부터 시작해서 coef, exp를 출력함 
{
	if (T->prev == H) // T->prev가 헤더에 도착하면 0을 리턴하는 베이스
		return 0;
	else
	{
		printf(" %d %d", (T->prev)->coef, (T->prev)->exp); // 인자로 입력된 T 이전 노드의 coef, exp를 출력

		return 1 + reversePrint(H, T->prev); // 출력 이후에 노드 개수 1 + 그 이전 노드를 리턴해서 노드의 개수를 세어나감
	}
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

int main()
{
	NODE* H, *T;
	int count, coef, exp;

	initial(&H, &T);

	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		scanf("%d %d", &coef, &exp);

		appendTerm(T, coef, exp);
	}
	
	Print(H, T);

	count = reversePrint(H, T);

	printf("\n%d\n", count);

	FreeMemory(H);

	return 0;
}