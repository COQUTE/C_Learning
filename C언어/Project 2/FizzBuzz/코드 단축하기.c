#include <stdio.h>

int main()
{
	for (int i = 0; ++i <= 100;)
		printf(i % 3 ? (i % 5 ? "%d\n" : "Buzz\n") : (i % 5 ? "Fizz\n" : "FizzBuzz\n"), i);

	return 0;
}