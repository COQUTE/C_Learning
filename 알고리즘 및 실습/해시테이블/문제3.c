#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash_1(int x, int M);
int hash_2(int x, int q);

int main() {
	int* table;
	int x, M, n, q;
	int index, value;
	int insert_count = 0, search_count = 0;
	char type;

	scanf("%d %d %d", &M, &n, &q);

	table = (int*)malloc(sizeof(int) * M);
	memset(table, 0, sizeof(int) * M);

	do {
		scanf("%c", &type);

		switch (type) {
		case 'i':
			scanf("%d", &x);
			getchar();

			index = hash_1(x, M);
			value = table[index];

			if (insert_count < n) {
				while (value != 0) {
					index = (index + hash_2(x, q)) % M;
					value = table[index];

					printf("C");
				}
				table[index] = x;
				printf("%d\n", index);

				insert_count++;
			}

			break;
		case 's':
			scanf("%d", &x);
			getchar();

			index = hash_1(x, M);
			value = table[index];

			while (value != 0 && value != x) {
				index = (index + hash_2(x, q)) % M;
				value = table[index];

				search_count++;
				if (search_count == M)
					break;
			}
			if (value == 0)
				printf("%d\n", -1);
			else if (value == x)
				printf("%d %d\n", index, value);

			search_count = 0;
			break;
		case 'p':
			for (int i = 0; i < M; i++)
				printf(" %d", table[i]);
			printf("\n");
			break;
		case 'e':
			for (int i = 0; i < M; i++)
				printf(" %d", table[i]);
			printf("\n");
			break;
		}
	} while (type != 'e');

	free(table);

	return 0;
}

int hash_1(int x, int M) {
	return x % M;
}

int hash_2(int x, int q) {
	return q - (x % q);
}