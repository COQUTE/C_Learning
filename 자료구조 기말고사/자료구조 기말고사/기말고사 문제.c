#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Tree {
	int num;
	struct Tree* left, * right;
} Tree;

typedef struct Value {
	int num, left, right;
	bool isRoot;
	Tree* node;
} Value;

Tree* getnode(int num) {
	Tree* ptr = (Tree*)malloc(sizeof(Tree));

	ptr->num = num;
	ptr->left = ptr->right = NULL;

	return ptr;
}

Tree* makeTree(int size) {
	Value* arr = NULL;
	Tree* ptr = NULL;

	arr = (Value*)malloc(sizeof(Value) * size);

	for (int i = 0; i < size; i++) {
		scanf("%d %d %d", &arr[i].num, &arr[i].left, &arr[i].right);

		arr[i].isRoot = true;
		arr[i].node = getnode(arr[i].num);
	}

	for (int i = 0; i < size; i++) {
		if (arr[i].left != 0) {
			for (int j = 0; j < size; j++) {
				if (i != j && arr[j].isRoot != false && arr[i].left == arr[j].num) {
					arr[i].node->left = arr[j].node;
					arr[j].isRoot = false;
				}
			}
		}
		if (arr[i].right != 0) {
			for (int j = 0; j < size; j++) {
				if (i != j && arr[j].isRoot != false && arr[i].right == arr[j].num) {
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

int main() {
	Tree* root = NULL;
	int size;

	scanf("%d", &size);

	root = makeTree(size);

	printf("%d\n", root->num);

	return 0;
}