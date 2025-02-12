#include <stdio.h>

enum DayOfWeek {
	Sunday = 0,
	Monday,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday
};

int main()
{
	enum DayOfWeek week;

	week = Tuesday;

	printf("%d\n", week);

	return 0;
}