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

void print(NODE* node)
{
	if (node == NULL)
		return;

	printf("%c", node->main);
	print(node->left);
	print(node->right);
}

int main()
{
	NODE* root;
	int size;

	scanf("%d", &size);

	getchar();

	root = makeTree(size);

	print(root);

	return 0;
}