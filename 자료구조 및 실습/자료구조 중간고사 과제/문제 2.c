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

	newnode = (NODE*)malloc(sizeof(NODE)); // 차수가 같을 경우가 있기 때문에 나중에 메모리 할당 및 값 입력

	newnode->coef = coef;
	newnode->exp = exp;

	newnode->next = ptr;
	newnode->prev = ptr->prev;
	(ptr->prev)->next = newnode;
	ptr->prev = newnode;
}

void Print(NODE* H, NODE* T) // 헤더 next부터 프린트를 시작
{
	NODE* ptr = H->next;

	while (ptr != T)
	{
		printf(" %d %d", ptr->coef, ptr->exp);

		ptr = ptr->next;
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

int main()
{
	NODE* H, * T;
	int count, coef, exp;

	initial(&H, &T);

	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		scanf("%d %d", &coef, &exp);

		arrayAddTerm(H, T, coef, exp);
	}

	Print(H, T);

	FreeMemory(H);

	return 0;
}