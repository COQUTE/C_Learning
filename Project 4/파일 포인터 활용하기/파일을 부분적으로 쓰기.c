#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char* s1 = "abcd";
	char buffer[20] = { 0, };

	FILE* fp = fopen("hello.txt", "r+");

	fseek(fp, 3, SEEK_SET);
	fwrite(s1, strlen(s1), 1, fp);

	rewind(fp);
	fread(buffer, 20, 1, fp);
	
	printf("%s\n", buffer);

	fclose(fp);

	return 0;
}