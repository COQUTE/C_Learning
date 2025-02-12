#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(int x, int M);

int main() {
	int* table;
	int x, M, n;
	int index, value;
	int insert_count = 0;
	char type;

	scanf("%d %d", &M, &n);

	table = (int*)malloc(sizeof(int) * M);
	memset(table, 0, sizeof(int) * M);

	do {
		scanf("%c", &type);

		switch (type) {
		case 'i':
			scanf("%d", &x);
			getchar();

			index = hash(x, M);
			value = table[index];

			if (insert_count < n) {
				while (value != 0) {
					index = (index + 1) % M;
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

			index = hash(x, M);
			value = table[index];

			while (value != 0 && value != x) {
				index = (index + 1) % M;
				value = table[index];
			}
			// n이 M보다 작기 때문에 x가 table 속에 없다면 반드시 0에 도착하게 됨
			if (value == 0)
				printf("%d\n", -1);
			else if (value == x)
				printf("%d %d\n", index, value);

			break;
		}
	} while (type != 'e');

	free(table);

	return 0;
}

int hash(int x, int M) {
	return x % M;
}