#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    int shared = 2;
    int pid = fork();

    if (pid)
    {
        shared = 1;
        printf("I am the parent process\n");
        printf("My pid is %d\n", getpid());
        printf("My parent pid is %d\n", getppid());
        printf("My child pid is %d\n", pid);
        printf("Shared = %d\n", shared);
        wait(NULL);
        printf("Im the parent again... Shared = %d\n", shared);
    }
    else
    {
        shared = 0;
        printf("I am the child process\n");
        printf("My pid is %d\n", getpid());
        printf("My parent pid is %d\n", getppid());
        printf("My child pid is %d\n", pid);
        printf("Shared = %d\n", shared);
        sleep(2);
    }
    return 0;
}