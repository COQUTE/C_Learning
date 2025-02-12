#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE {
	int data, id;
	struct NODE* left, * right;
} NODE;

NODE* getnode(int data, int id)
{
	NODE* ptr = (NODE*)malloc(sizeof(NODE));

	ptr->left = NULL;
	ptr->right = NULL;
	ptr->data = data;
	ptr->id = id;

	return ptr;
}

NODE* preorder_data(NODE* F, int id)
{
	NODE* L = NULL, * R = NULL;

	if (F == NULL)
		return NULL;

	if (F->id == id)
		return F;

	L = preorder_data(F->left, id);
	if (L != NULL)
		return L;

	R = preorder_data(F->right, id);
	return R;
}

int main()
{
	NODE* F1, * F2, * F3, * F4, *F5, *F6, *F7, *F8;
	NODE* result;
	int id;

	F1 = getnode(20, 1);
	F2 = getnode(30, 2);
	F3 = getnode(50, 3);
	F4 = getnode(70, 4);
	F5 = getnode(90, 5);
	F6 = getnode(120, 6);
	F7 = getnode(130, 7);
	F8 = getnode(80, 8);

	F1->left = F2;
	F1->right = F3;

	F2->left = F4;
	F2->right = F5;

	F3->right = F6;

	F6->left = F7;
	F6->right = F8;

	scanf("%d", &id);

	result = preorder_data(F1, id);

	if (result == NULL)
		printf("-1\n");
	else
	{
		printf("%d", result->data);

		if (result->left != NULL)
			printf(" %d", result->left->data);
		if (result->right != NULL)
			printf(" %d", result->right->data);

		printf("\n");
	}

	free(F1);
	free(F2);
	free(F3);
	free(F4);
	free(F5);
	free(F6);
	free(F7);
	free(F8);

	return 0;
}