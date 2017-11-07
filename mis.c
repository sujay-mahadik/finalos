#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int fd[2] = {0,0};
	int fd1[2] = {0,0};

	printf("%d..%d\n", fd[0], fd[1]);
	printf("%d..%d\n", fd1[0], fd1[1]);

	pipe(fd);
	pipe(fd1);

	printf("%d..%d\n", fd[0], fd[1]);
	printf("%d..%d\n", fd1[0], fd1[1]);
}