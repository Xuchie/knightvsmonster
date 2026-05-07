#include <stdio.h>

struct Address
{
    char city[30];
    int zip;
};

struct Student
{
    char name[30];
    int age;
    struct Address addr;
};

int main()
{
    struct Student mengheng;

    printf("enter your name :");
    scanf("%s", &mengheng.name);

    printf("enter your age :");
    scanf("%d", &mengheng.age);

    printf("enter your city :");
    scanf("%s", &mengheng.addr.city);

    printf("enter your zip :");
    scanf("%d", &mengheng.addr.zip);

    printf("Student info\n");
    printf("%s\n", mengheng.name);
    printf("%d\n", mengheng.age);
    printf("%s\n", mengheng.addr.city);
    printf("%d\n", mengheng.addr.zip);

    return 0;
}