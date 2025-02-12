#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int size(int N, int f, int l)
{
	if (l == -1)
		return 0;

	return (N + l - f + 1) % N;
}

int get(int* arr, int Rank, int N, int f, int l)
{
	if (Rank < 0 || Rank >= size(N, f, l))
		printf("invalid position\n");
	else
	{
		printf("%d\n", arr[(f + Rank) % N]);

		return arr[(f + Rank) % N];
	}
}

void set(int* arr, int Rank, int element, int N, int f, int l)
{
	if (Rank < 0 || Rank >= size(N, f, l))
		printf("invalid position\n");
	else
		arr[(f + Rank) % N] = element;
}

void Add(int* arr, int Rank, int element, int N, int* f, int* l)
{
	int n = size(N, *f, *l);

	if (n == N - 1)
		printf("list is full\n");
	else if (Rank < 0 || Rank > n)
		printf("invalid position\n");
	else if (Rank < n / 2)
	{
		for (int i = 0; i < Rank; i++) // 0 0 1 2 3 4 0 0 : Rank가 1이면 0 1 1 2 3 4 0 0 이 되고 두 번째 1자리에 새로운 element 값이 입력됨
		{							   // 즉, f부터 Rank번 좌로 값을 복사

			// (*f + i - 1) % N 으로 하면 f = 0 일 때, 인덱스가 -1인 경우가 생겨서 오류 발생
			arr[(N + *f + i - 1) % N] = arr[(*f + i) % N];
		}

		// (*f + Rank - 1) % N 으로 하면 f = 0 일 때, 인덱스가 -1인 경우가 생겨서 오류 발생
		arr[(N + *f + Rank - 1) % N] = element;

		// (*f - 1) % N 으로 하면 f = 0 일 때, 인덱스가 -1인 경우가 생겨서 오류 발생
		*f = (N + *f - 1) % N;
	}
	else
	{
		for (int i = n - 1; i >= Rank; i--) // 실제 인덱스의 최대값은 n - 1이므로 arr[n - 1] 부터 arr[Rank]까지 우로 값을 복사하고 arr[Rank]에 element 값 입력
			arr[(*f + i + 1) % N] = arr[(*f + i) % N];

		arr[(*f + Rank) % N] = element;

		*l = (*l + 1) % N;
	}
}

void Remove(int* arr, int Rank, int N, int* f, int* l)
{
	int n = size(N, *f, *l);
	
	if (n == 0)
		printf("list is empty\n");
	else if (Rank < 0 || Rank >= n)
		printf("invalid position\n");
	else
	{
		if (Rank < n / 2)
		{
			for (int i = Rank - 1; i >= 0; i--)
				arr[(*f + i + 1) % N] = arr[(*f + i) % N];
			
			arr[*f] = 0;
			*f = (*f + 1) % N;
		}
		else
		{
			for (int i = Rank + 1; i < n; i++)
				arr[(*f + i - 1) % N] = arr[(*f + i) % N];

			arr[*l] = 0;

			// (*l - 1) % N 으로 하면 l = 0 일 때, 인덱스가 -1인 경우가 생겨서 오류 발생
			*l = (N + *l - 1) % N;
		}
	}
}

int main()
{
	int arr[10] = { 0, };
	int N = 10, f = 0, l = -1;
	int count, Rank, element;
	char Type;

	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		getchar();

		scanf("%c", &Type);

		if (Type == 'A')
		{
			scanf("%d %d", &Rank, &element);

			Add(arr, Rank, element, N, &f, &l);
		}
		else if (Type == 'R')
		{
			scanf("%d", &Rank);

			Remove(arr, Rank, N, &f, &l);
		}
		else if (Type == 'G')
		{
			scanf("%d", &Rank);

			element = get(arr, Rank, N, f, l);
		}
		else if (Type == 'S')
		{
			scanf("%d %d", &Rank, &element);

			set(arr, Rank, element, N, f, l);
		}
		else
		{
			printf("invalid type\n");
			continue;
		}

		for (int i = 0; i < N; i++)
		{
			printf(" %d", arr[i]);
		}

		printf("\n");
	}

	return 0;
}