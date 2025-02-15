#include <stdio.h>

#pragma pack(push, 1)
struct PacketHeader {
	char flags;
	int seq;
};
#pragma pack(pop)

int main()
{
	struct PacketHeader header;

	printf("%d\n", sizeof(header.flags));
	printf("%d\n", sizeof(header.seq));
	printf("%d\n", sizeof(header));

	return 0;
}