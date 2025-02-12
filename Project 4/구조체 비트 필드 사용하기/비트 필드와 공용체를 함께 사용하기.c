#include <stdio.h>

struct Flags {
	union {
		struct {
			unsigned short a : 3;
			unsigned short b : 2;
			unsigned short c : 7;
			unsigned short d : 4;
		};
		unsigned short e;
	};
};

int main()
{
	struct Flags f1 = { 0, };

	f1.a = 4;
	f1.b = 2;
	f1.c = 80;
	f1.d = 15;

	printf("%u\n", f1.e);

	return 0;
}