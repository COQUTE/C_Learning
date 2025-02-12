/* 정수 i를 2부터 N의 제곱근까지 증가하는 for문으로 돌려서
   만약 N이 i로 나누어 떨어진다면 break했다.
   for문을 break없이 for문을 나왔다면 i는 소수이고, N의 제곱근보다
   커진다. 그렇기 때문에 i > sqrt(N)일 경우 소수임을 출력했다.
   그 이외 경우는 모두 break로 for문을 나온 것이기 때문에
   합성수임을 출력했다.

   나누는 수와 몫은 반비례 관계이기 때문에 16을 예로 들면
   2*8 4*4 8*2 이렇게 그 수의 제곱근을 기준으로 반드시 대칭이 된다.
   그렇기 때문에 for문에서 N의 제곱근 이하까지만 확인을 했다.

   N이 소수가 되면 for문을 처음부터 끝까지 전부 확인하기 때문에
   최악의 실행시간이 되고, 그 때의 실행시간은 O(N의 제곱근)이 된다.*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void is_prime(int N)
{
	int i;

	for (i = 2; i <= sqrt(N); i++)
	{
		if (N % i == 0)
			break;
	}

	if (i > sqrt(N))
		printf("prime\n");
	else
		printf("composite\n");
}

int main()
{
	int N;

	scanf("%d", &N);

	is_prime(N);

	return 0;
}