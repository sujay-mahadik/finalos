#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX 1024

int main(){
	int fd1[2], fd2[2];
	pid_t p;
	FILE *fp;

	

	if((pipe(fd1) == -1) || (pipe(fd2) == -1)){
		printf("Pipe Failed\n");
	}
	 if((p = fork())<0){
	 	printf("Fork Failed\n");
	 }
	 else if(p == 0){
	 	char file_path[MAX], buff1[MAX];
	 	//close(fd1[1]);
	 	read(fd1[0], file_path, sizeof(file_path));
	 	//close(fd1[0]);

	 	fp = fopen(file_path, "r");
	 	fgets(buff1, sizeof(buff1), fp);

	 	//close(fd2[0]);
	 	write(fd2[1], buff1, strlen(buff1)+1);
	 	//close(fd2[1]);



	 }
	 else{
	 	char file_data[MAX], buff[MAX];
	 	//close(fd1[0]);
	 	printf("Enter the path of the file\n");
	 	scanf("%s", buff);
	 	write(fd1[1], buff, strlen(buff)+1);
	 	//close(fd1[1]);

	 	//close(fd2[1]);
	 	read(fd2[0], file_data, sizeof(file_data));
	 	//close(fd2[0]);

	 	printf("%s\n", file_data);

	 }

	 return 0;
}