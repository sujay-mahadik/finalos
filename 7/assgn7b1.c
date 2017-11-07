
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<ctype.h>

int alphabet_Count(char array[50])	
{
	int i=0,K=0;
	while(array[i]!='\0')
	{
		if(isalnum(array[i]))
			K++;
		i++;
	}
	return K;
}

int lines_Count(char array[50])	
{
	int i,K=0;
	for(i=0;array[i]!='\0';i++)
	{
		if(array[i]=='\n' || array[i]=='.')
			K++;	
	}
	return K;
}

int word_Count(char array[50])		
{
	int i=0,K=0;
	while(array[i]!='\0')
	{
		if(array[i]==' ' || array[i]=='\n' || array[i]=='.')
			K++;
		i++;
	}
	return K;
}

int main()
{
	int fd1,fd2;
	int counts[3];
	char buffer[50];
	char *t1="myfifo1";
	fd1=open(t1,O_RDONLY);		
	read(fd1,buffer,sizeof(buffer));		
	
	printf("Accepted String:\n");		
	printf("%s",buffer);
	printf("\n");
	
	counts[0]=alphabet_Count(buffer);		
	counts[1]=word_Count(buffer);
	counts[2]=lines_Count(buffer);
	close(fd1);		
	
	char *t2="myfifo2";
	mkfifo(t2,0666);		
	fd2=open(t2,O_WRONLY);		
	write(fd2,counts,sizeof(counts));		
	close(fd2);		
	return 0;
}
