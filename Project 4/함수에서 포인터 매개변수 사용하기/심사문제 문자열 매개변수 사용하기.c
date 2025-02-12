#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void printFullName(char* s1, char* s2)
{
    printf("%s%s\n", s1, s2);
}

int main()
{
    char familyName[31];
    char givenName[31];

    scanf("%s %s", familyName, givenName);

    printFullName(familyName, givenName);

    return 0;
}