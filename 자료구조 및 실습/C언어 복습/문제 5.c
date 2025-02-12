#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct time {
	int hour;
	int minute;
	int second;
};

int main()
{
	struct time t1, t2;
	struct time dif;

	scanf("%d %d %d", &t1.hour, &t1.minute, &t1.second);
	scanf("%d %d %d", &t2.hour, &t2.minute, &t2.second);

	dif.hour = t2.hour - t1.hour;
	dif.minute = t2.minute - t1.minute;
	dif.second = t2.second - t1.second;

	if (t1.minute > t2.minute && t1.second > t2.second)
	{
		dif.hour -= 1;
		dif.minute += 60 - 1;
		dif.second += 60;
	}
	else if (t1.minute > t2.minute)
	{
		dif.hour -= 1;
		dif.minute += 60;
	}
	else if (t1.second > t2.second)
	{
		dif.minute -= 1;
		dif.second += 60;
	}

	printf("%d %d %d\n", dif.hour, dif.minute, dif.second);

	return 0;
}