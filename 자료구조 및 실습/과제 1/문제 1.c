#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void is_prime(int N)
{
	int i;				

	for (i = 2; i < N; i++)	
	{
		if (N % i == 0)		
			break;
	}

	if (i == N)				
		printf("prime\n");
	else					
		printf("composite\n");
}

/* 소수는 1과 자신 사이에 어떤 수로도 나누어 떨어지면 안되기 때문에
   정수 i를 (1과 자기 자신을 제외)2부터 시작해서 N - 1까지 증가하는
   for문으로 돌렸고, 불필요한 반복을 줄이기 위해 N이 i로 나누어
   떨어지는 순간 break를 활용해서 for문을 빠져나왔다. 그 이후
   i가 N과 같아지면 소수이고(for문을 break하지 않고 다 통과했기 때문에),
   나머지 경우에는 i가 합성수가 된다.

   가장 최악의 실행시간은 i가 소수일 경우 for문을 N - 2번 반복하기 때문에
   O(N)이 된다.*/

int main()
{
	int n;

	scanf("%d", &n);

	is_prime(n);
	
	return 0;
}