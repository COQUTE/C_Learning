#include <stdio.h>

struct Phone {
	int areacode;
	unsigned long long number;
};

struct Person {
	char name[20];
	int age;
	struct Phone phone;
};

int main()
{
	struct Person p1;

	p1.phone.areacode = 82;
	p1.phone.number = 3045671234;

	printf("%d %llu\n", p1.phone.areacode, p1.phone.number);

	return 0;
}