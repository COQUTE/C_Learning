#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TREE {
	char elem;
	struct TREE* left, * right;
} TREE;

typedef struct STACK {
	TREE* ptr;
	struct STACK* next;
} STACK;

typedef struct NODE {
	char opt;
	struct NODE* next;
} NODE;

TREE* getroot(char elem)
{
	TREE* ptr = (TREE*)malloc(sizeof(TREE));

	ptr->elem = elem;
	ptr->left = NULL;
	ptr->right = NULL;

	return ptr;
}

STACK* getnode(TREE* ptr)
{
	STACK* node = (STACK*)malloc(sizeof(STACK));

	node->ptr = ptr;
	node->next = NULL;

	return node;
}

NODE* get(char opt)
{
	NODE* ptr = (NODE*)malloc(sizeof(NODE));

	ptr->next = NULL;
	ptr->opt = opt;

	return ptr;
}

void stock(NODE** top, char opt)
{
	NODE* newnode = get(opt);

	newnode->next = *top;
	*top = newnode;
}

char distract(NODE** top)
{
	NODE* tmp;
	char opt;

	if (*top == NULL)
		return '\0';

	opt = (*top)->opt;
	tmp = *top;
	*top = (*top)->next;

	free(tmp);

	return opt;
}

int Operator(char opt)
{
	if (opt == '*' || opt == '/')
		return 2;
	else if (opt == '+' || opt == '-')
		return 1;
	else if (opt == '(')
		return 0;
}

void convert(char* arr, char* convert_arr, NODE* top)
{
	int index = 0;

	while (*arr != '\0')
	{
		if (*arr >= 'A' && *arr <= 'Z')
		{
			convert_arr[index] = *arr;
			index++;
		}
		else if (*arr == '(')
			stock(&top, *arr);
		else if (*arr == ')')
		{
			while (top->opt != '(')
			{
				convert_arr[index] = distract(&top);
				index++;
			}
			distract(&top);
		}
		else
		{
			while (top != NULL && Operator(top->opt) >= Operator(*arr))
			{
				convert_arr[index] = distract(&top);
				index++;
			}
			stock(&top, *arr);
		}
		arr++;
	}

	while (top != NULL)
	{
		convert_arr[index] = distract(&top);
		index++;
	}

	convert_arr[index] = '\0';
}

void push(STACK** top, TREE* ptr)
{
	STACK* newnode = getnode(ptr);

	newnode->next = *top;
	*top = newnode;
}

TREE* pop(STACK** top)
{
	TREE* ptr;
	STACK* tmp;

	if (*top == NULL)
		return NULL;

	ptr = (*top)->ptr;
	tmp = *top;
	*top = (*top)->next;

	free(tmp);

	return ptr;
}

TREE* root(char* convert_arr)
{
	STACK* top = NULL;
	TREE* node, * a, * b;

	while (*convert_arr != '\0')
	{
		node = getroot(*convert_arr);

		if (*convert_arr < 'A' || *convert_arr > 'Z')
		{
			a = pop(&top);
			b = pop(&top);

			node->left = b;
			node->right = a;
		}

		push(&top, node);

		convert_arr++;
	}

	return pop(&top);
}

void inorder_print(TREE* node, TREE* root_node)
{
	/* root일 경우 괄호를 적지 않는다*/

	if (node == NULL)
		return;


	if (node->left != NULL && node->right != NULL)
	{
		if (node != root_node)
			printf("(");
		inorder_print(node->left, root_node);
	}

	printf("%c", node->elem);

	if (node->left != NULL && node->right != NULL)
	{
		inorder_print(node->right, root_node);
		if (node != root_node)
			printf(")");
	}
}

void FreeTree(TREE* node)
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
	NODE* top = NULL;
	TREE* node = NULL;
	char arr[101], convert_arr[101];
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		getchar();
		scanf("%s", arr);

		convert(arr, convert_arr, top);
		
		node = root(convert_arr);

		inorder_print(node, node);
		printf("\n");

		FreeTree(node);
	}

	return 0;
}