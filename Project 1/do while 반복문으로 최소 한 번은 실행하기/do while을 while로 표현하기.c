#include <stdio.h>

int main()
{
	int i = 0;

	// do에 해당하는 부분
	printf("Hello, world! %d\n", i); // 처음 한 번은 실행
	i++;							 // 처음 한 번은 실행

	while (i < 100)
	{
		printf("Hello, world! %d\n", i);
		i++;
	}

	return 0;
}