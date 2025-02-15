#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Person {
    char name[30];
    int age;
};

int main()
{
    struct Person* p[5];

    int index = 0, most = 0;

    for (int i = 0; i < sizeof(p) / sizeof(struct Person*); i++)
    {
        p[i] = malloc(sizeof(struct Person));
    }

    for (int i = 0; i < sizeof(p) / sizeof(struct Person*); i++)
        scanf("%s %d", p[i]->name, &p[i]->age);

    for (int i = 0; i < sizeof(p) / sizeof(struct Person*); i++)
    {
        if (most <= p[i]->age)
        {
            most = p[i]->age;
            index = i;
        }
    }

    printf("%s\n", p[index]->name);

    for (int i = 0; i < sizeof(p) / sizeof(struct Person*); i++)
    {
        free(p[i]);
    }

    return 0;
}