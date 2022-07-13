#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, const char *argv[])
{
    int pid = fork();

    if (pid)
    {
        printf("I am the parent process\n");
        printf("My pid is %d\n", getpid());
        printf("My parent pid is %d\n", getppid());
        printf("My child pid is %d\n", pid);
    }
    else
    {
        printf("I am the child process\n");
        printf("My pid is %d\n", getpid());
        printf("My parent pid is %d\n", getppid());
        printf("My child pid is %d\n", pid);
    }
    while (1)
        ;
    return 0;
}