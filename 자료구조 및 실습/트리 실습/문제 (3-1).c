#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
	int num;
	struct Tree* left, * right;
} Tree;

Tree* getnode(int num)
{
	Tree* ptr = (Tree*)malloc(sizeof(Tree));

	ptr->left = NULL;
	ptr->right = NULL;
	ptr->num = num;

	return ptr;
}

Tree* make_tree()
{
	Tree* node;

	int num, left_num, right_num;

	scanf("%d %d %d", &num, &left_num, &right_num);

	node = getnode(num);

	if (left_num != 0)
		node->left = make_tree();

	if (right_num != 0)
		node->right = make_tree();

	return node;
}

Tree* find_node(Tree* node, int x)
{
	Tree* L = NULL,* R = NULL;

	if (node == NULL)
		return NULL;

	if (node->num == x)
		return node;

	L = find_node(node->left, x);
	if (L != NULL)
		return L;

	R = find_node(node->right, x);
	return R;
}

void make_tree2(int node_count, Tree** node)
{
	Tree* ptr;
	int x, y, z;

	for (int i = 0; i < node_count; i++)
	{
		scanf("%d %d %d", &x, &y, &z);

		if (*node == NULL)
		{
			*node = getnode(x);
			(*node)->left = getnode(y);
			(*node)->right = getnode(z);

			continue;
		}

		ptr = find_node(*node, x);
		ptr->left = getnode(y);
		ptr->right = getnode(z);
	}
}

void search_node(int search_count, Tree* root)
{
	Tree* node;
	char direction[100];
	char* ptr;

	for (int i = 0; i < search_count; i++)
	{
		scanf("%s", direction);

		node = root;
		ptr = direction;
		printf(" %d", node->num);

		while (*ptr != '\0')
		{ 
			if (*ptr == 'L')
				node = node->left;
			else
				node = node->right;

			printf(" %d", node->num);

			ptr++;
		}

		printf("\n");
	}
}

void search_node2(char* str, Tree* node)
{
	printf(" %d", node->num);

	if (*str == 'R')
		search_node2(str + 1, node->right);
	else if (*str == 'L')
		search_node2(str + 1, node->left);
}

void FreeTree(Tree* node)
{
	/* root 노드를 받아서 postorder로 순회하여 트리에 동적할당된 메모리를 해제함*/
	if (node == NULL)
		return;

	FreeTree(node->left);
	FreeTree(node->right);
	free(node);
}

int main()
{
	Tree* root = NULL;
	int node_count, search_count;
	char str[100];

	scanf("%d", &node_count);

	make_tree2(node_count, &root);

	scanf("%d", &search_count);

	for (int i = 0; i < search_count; i++)
	{
		scanf("%s", str);

		search_node2(str, root);

		printf("\n");
	}

	FreeTree(root);

	return 0;
}