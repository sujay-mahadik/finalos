
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>

int accept(char array[50])
{
	int i;
	for(i=0;i<50;i++)
	{
		char c;
		if(c=='.')
			break;
		else{
			scanf("%c",&c);
			array[i]=c;
		}
	}
	printf("String entered successfully!\n");
	return i;
}

int main()
{
	int fd1,fd2;
	int N=0;
	char msg[50];
	
	printf("Enter your String:\t");
	N=accept(msg);

	char *t1="myfifo1";
	mkfifo(t1,0666);	
	fd1=open(t1,O_WRONLY);		
	write(fd1,msg,N);	
	close(fd1);			
	
	sleep(15);
	
	int result[3];
	char *t2="myfifo2";
	fd2=open(t2,O_RDONLY);		
	read(fd2,result,sizeof(result));		
	
	printf("No. of Alphabets = %d\n",result[0]);	
	printf("No. of Words = %d\n",result[1]);
	printf("No. of Lines = %d\n",result[2]);	
	close(fd2);		
	return 0;
}
