#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

#define MSGSIZE 16

int main(int argc, const char *argv[])
{
    FILE *in;
    int pid, p[2];

    if (pipe(p) < 0)
    {
        perror("Unable to create pipe");
        exit(1);
    }

    if (!(in = fopen(argv[1], "r")))
    {
        perror("Unable to open file");
        exit(1);
    }

    if (pid = fork())
    {
        char buffer[MSGSIZE];
        printf("I am the parent process. Going to read from %s\n", argv[1]);
        while (fgets(buffer, MSGSIZE, in))
        {
            printf("Read %s. %d Which is the biggest char ? n", buffer, pid);

            write(p[1], buffer, MSGSIZE);
        }
        close(p[1]);
        printf("Parent process is done reading\n");
        printf("Parent process is waiting for child process to finish\n");
        wait(NULL);
        fclose(in);
    }
    else
    {
        close(p[1]);
        printf("I am the child process. Going to read from %s\n", argv[1]);
        char buffer[MSGSIZE], max;
        while (read(p[0], buffer, MSGSIZE))
        {
            printf("Read %s from the pipe \n", buffer);
            max = buffer[0];
            for (int i = 0; i < MSGSIZE; i++)
            {
                if (buffer[i] > max)
                {
                    max = buffer[i];
                }
            }
            printf("The biggest char is %c\n", max);
        }
    }

    return 0;
}