
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
    int p = fork();
 
    if (p > 0)
        sleep(50);

    else       
        exit(0);
 
    return 0;
}