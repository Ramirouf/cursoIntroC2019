#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char *argv[])
{
    FILE *out;
    char buffer[100];

    if ((out = fopen(argv[1], "w")) == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }

    do
    {
        printf("Enter a string: ");
        scanf("%99s", buffer);
        fputs(buffer, out);
        fputs("\n", out);
        fflush(stdin);
        printf("Do you want to enter another string? (y/n) ");
        scanf("%1s", buffer);

    } while (buffer[0] != 'n');

    fclose(out);
    return 0;
}