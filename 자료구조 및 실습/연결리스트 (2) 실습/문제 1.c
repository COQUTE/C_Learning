#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int coef, exp;
	struct NODE* next;
}NODE, *NODE_PTR, **NODE_DPTR;

NODE_PTR getnode(int coef, int exp)
{
	NODE_PTR ptr = (NODE_PTR)malloc(sizeof(NODE));

	ptr->coef = coef;
	ptr->exp = exp;
	ptr->next = NULL;

	return ptr;
}

void initial(NODE_DPTR H)
{
	NODE_PTR ptr = getnode(0, 0);

	(*H) = ptr;
}

void appendTerm(NODE_DPTR k, int coef, int exp)
{
	NODE_PTR ptr = getnode(coef, exp);

	(*k)->next = ptr;
	*k = ptr;
}

void MakePolly(NODE_PTR H)
{
	NODE_PTR tmp = H;
	int N, coef, exp;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d %d", &coef, &exp);

		if (coef != 0)
			appendTerm(&tmp, coef, exp);
	}
}

NODE_PTR addPolly(NODE_PTR First_Polly, NODE_PTR Second_Polly)
{
	NODE_PTR Result, tmp, F_P, S_P;

	initial(&Result);

	tmp = Result;
	F_P = First_Polly->next;
	S_P = Second_Polly->next;

	while (F_P != NULL && S_P != NULL)
	{
		if (F_P->exp > S_P->exp)
		{
			appendTerm(&tmp, F_P->coef, F_P->exp);

			F_P = F_P->next;
		}
		else if (F_P->exp < S_P->exp)
		{
			appendTerm(&tmp, S_P->coef, S_P->exp);

			S_P = S_P->next;
		}
		else
		{
			if (F_P->coef + S_P->coef != 0)
			{
				appendTerm(&tmp, F_P->coef + S_P->coef, F_P->exp);
			}

			F_P = F_P->next;
			S_P = S_P->next;
		}
	}

	while (F_P != NULL)
	{
		appendTerm(&tmp, F_P->coef, F_P->exp);

		F_P = F_P->next;
	}

	while (S_P != NULL)
	{
		appendTerm(&tmp, S_P->coef, S_P->exp);

		S_P = S_P->next;
	}

	return Result;
}

void Print(NODE_PTR H)
{
	for (NODE_PTR ptr = H->next; ptr != NULL; ptr = ptr->next)
	{
		printf(" %d %d", ptr->coef, ptr->exp);
	}

	printf("\n");
}

void FreeMemory(NODE_PTR H)
{
	NODE_PTR tmp, ptr;

	ptr = H;

	while (ptr != NULL)
	{
		tmp = ptr;
		ptr = ptr->next;

		free(tmp);
	}
}

int main()
{
	NODE_PTR First_Polly, Second_Polly, Result;

	initial(&First_Polly);
	initial(&Second_Polly);

	MakePolly(First_Polly);
	MakePolly(Second_Polly);

	Result = addPolly(First_Polly, Second_Polly);

	Print(Result);

	FreeMemory(First_Polly);
	FreeMemory(Second_Polly);
	FreeMemory(Result);

	return 0;
}