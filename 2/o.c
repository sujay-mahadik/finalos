#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
 
int main()
{
    int p = fork();
 
    if (p > 0)
        printf("in parent process pid: %d", getpid());
 
    else if (p == 0)
    {
        sleep(30);
        printf("in child process ppid: %d ", getppid());
    }
 
    return 0;
}