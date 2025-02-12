#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct NODE {
	char main;
	struct NODE* left, * right;
}NODE;

typedef struct Value {
	char main, left, right;
	bool isRoot;
	NODE* node;
}Value;

typedef struct Stack {
	int n;
	struct Stack* next;
} Stack;

Stack* getstack(int n){
	Stack* ptr = (Stack*)malloc(sizeof(Stack));

	ptr->n = n;
	ptr->next = NULL;

	return ptr;
}

void push(Stack** top, int n)
{
	Stack* node = getstack(n);

	node->next = *top;
	*top = node;
}

int pop(Stack** top)
{
	Stack* ptr;
	int elem;

	ptr = *top;
	elem = (*top)->n;

	*top = (*top)->next;

	free(ptr);

	return elem;
}

NODE* getnode(char elem) {
	NODE* ptr = (NODE*)malloc(sizeof(NODE));

	ptr->left = ptr->right = NULL;
	ptr->main = elem;

	return ptr;
}

NODE* makeTree(int size) {
	Value* arr;
	NODE* ptr = NULL;

	arr = (Value*)malloc(sizeof(Value) * size);

	for (int i = 0; i < size; i++)
	{
		scanf("%c %c %c", &arr[i].main, &arr[i].left, &arr[i].right);

		arr[i].node = getnode(arr[i].main);
		arr[i].isRoot = true;

		getchar();
	}

	for (int i = 0; i < size; i++)
	{
		if (arr[i].left != '0')
		{
			for (int j = 0; j < size; j++)
			{
				if (i != j && arr[j].isRoot != false && arr[i].left == arr[j].main)
				{
					arr[i].node->left = arr[j].node;
					arr[j].isRoot = false;
				}
			}
		}

		if (arr[i].right != '0')
		{
			for (int j = 0; j < size; j++)
			{
				if (i != j && arr[j].isRoot != false && arr[i].right == arr[j].main)
				{
					arr[i].node->right = arr[j].node;
					arr[j].isRoot = false;
				}
			}
		}
	}

	for (int i = 0; i < size; i++)
		if (arr[i].isRoot == true)
			ptr = arr[i].node;

	free(arr);

	return ptr;
}

void change(NODE* node)
{
	if (node == NULL)
		return;

	change(node->left);

	if (node->main >= 'a' && node->main <= 'g')
		node->main = '*';
	else if (node->main >= 'h' && node->main <= 'l')
		node->main = '/';
	else if (node->main >= 'm' && node->main <= 's')
		node->main = '+';
	else if (node->main >= 't' && node->main <= 'z')
		node->main = '-';

	change(node->right);
}

void print(NODE* node)
{
	if (node == NULL)
		return;

	print(node->left);
	print(node->right);
	printf("%c", node->main);
}


// 이 부분만 해결 못했습니다.
void result(NODE* node, Stack** top)
{
	int a, b;

	if (node == NULL)
		return;

	result(node->left, top);
	result(node->right, top);
	if (node->main != '*' && node->main != '/' && node->main != '+' && node->main != '-')
		push(top, node->main);
	else
	{
		a = pop(top);
		b = pop(top);

		if (node->main == '*')
			push(top, b * a);
		else if (node->main == '/')
			push(top, b / a);
		if (node->main == '+')
			push(top, b + a);
		else if (node->main == '-')
			push(top, b - a);
	}
}

void freeTree(NODE* node)
{
	if (node == NULL)
		return;

	freeTree(node->left);
	freeTree(node->right);
	free(node);
}

int main()
{
	NODE* root;
	Stack* top;
	int size;

	scanf("%d", &size);

	getchar();

	root = makeTree(size);

	change(root);

	print(root);

	result(root, &top);

	printf("%d\n", pop(&top));

	freeTree(root);

	return 0;
}