#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
char *file_path;
char *t = "temp";

typedef struct Student
{
	int roll;
	char name[100];
	float per;
}Student;

void insertstudent(Student s){
	int fd = open(file_path, O_WRONLY | O_APPEND);
	write(fd, &s, sizeof(s));
	close(fd);
	printf("Insert Success\n");
}

void readdatabase(){
	Student s;
	int fd = open(file_path, O_RDONLY);
	while(read(fd, &s, sizeof(s))){
		printf("Roll: %d\nName: %s\nPerce: %f\n", s.roll, s.name, s.per);
	}
	close(fd);
	printf("Read Success\n");
}

void searchstudent(int rno){
	Student s;
	int found;
	int fd = open(file_path, O_RDONLY);
	while(read(fd, &s, sizeof(s))){
		if(s.roll == rno){
			printf("Record Found\n");
			printf("R: %d\nN: %s\nP: %f", s.roll, s.name, s.per );
		}
		else{

		}
	}
	close(fd);
}

void deletestudent(int rno){
	Student s;
	int fd = open(file_path, O_RDWR);
	int fdt = open(t, O_CREAT | O_WRONLY);

	while(read(fd, &s, sizeof(s))){
		if(s.roll == rno){

		}
		else{
			write(fdt, &s, sizeof(s));
		}
	}

	remove(file_path);
	rename(t, file_path);

	close(fd);
	close(fdt);
	printf("Delete Success\n");
}
int main(){
	Student s;
	int ch, rno;
	int fd, fdt;
	char database_name[100];

	
	while(ch != 99){
		printf("1.Create or Open Existing\n2.Insert\n3.Read\n4.Search\n5.Delete\n99.Exit\n>>");
	scanf("%d", &ch);
		switch(ch){
		case 1:
		printf("Enter database name\n");
		scanf("%s", database_name);
		file_path = database_name;
		fd = open(file_path, O_CREAT);
		if(fd<0)
			printf("Error while creating db\n");
		close(fd);
		break;

		case 2:
		printf("Enter the details of the student\n");
		scanf("%d%s%f", &s.roll, s.name, &s.per);
		insertstudent(s);
		break;

		case 3:
		printf("Reading db\n");
		readdatabase();
		break;

		case 4:
		printf("Enter the roll to be searched\n");
		scanf("%d", &rno);
		searchstudent(rno);
		break;

		case 5:
		printf("Enter the roll to be deleted\n");
		scanf("%d", &rno);
		deletestudent(rno);
		break;

		case 99:
		exit(0);
		break;

	}
	}
	
}