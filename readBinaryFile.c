#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    char name[20];
    unsigned int age;
} Person;

int main(int argc, const char *argv[])
{

    FILE *in;
    char buffer[100];
    if (argc < 2)
    {
        printf("Enter name of file to read\n");
        return 1;
    }
    if (!(in = fopen(argv[1], "r")))
    {
        printf("Error opening file\n");
        return 1;
    }

    Person p;
    while (fread(&p, sizeof(Person), 1, in))
    {
        printf("%s is %d years old\n", p.name, p.age);
    }

    fclose(in);

    return 0;
}