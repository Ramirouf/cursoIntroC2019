#include <stdio.h>
#include <stdlib.h>

typedef struct person
{
    char name[20];
    unsigned int age;
} Person;

int main(int argc, const char *argv[])
{

    FILE *out;
    char buffer[100];
    if (argc < 2)
    {
        printf("Enter name of file to write to\n");
        return 1;
    }
    if (!(out = fopen(argv[1], "w")))
    {
        printf("Error opening file\n");
        return 1;
    }

    Person p;
    do
    {
        printf("Enter name: ");
        scanf("%s", p.name);
        printf("Enter age: ");
        scanf("%d", &p.age);
        fwrite(&p, sizeof(Person), 1, out);
        printf("Enter another person? (y/n): ");
        scanf("%1s", buffer);
    } while (buffer[0] == 'y');

    fclose(out);

    return 0;
}