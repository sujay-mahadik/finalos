#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include<stdlib.h>

/*
int binsearch(int arr[], int n, int k){
	int i, mid, first, last;
	for(i=0;i<n;i++){
//
	}
}
*/

int main(int argc, char *argv[])
{
	int i,key, found = 0, f=0, l=argc, m=0, array[20];
	bool flag= false;
	printf("argc : %d\n", argc);

	//printf("%d\n", (int *)argv[0] );

	for(i=0; i<argc; i++){
		array[i] = atoi(argv[i]);
	} 
	printf("In binary search pid : %d ppid : %d\n", getpid(), getppid());
	printf("Enter the element to be searched\n");
	scanf("%d", &key);

	while(f<l){
		m = (f+l)/2;
		if(array[m] == key){
			found = m+1;
			printf("Enter found at %d position\n", found);
			flag=true;
			break;
		}
		else if(key<array[m])
			l=m-1;
		else
			f=m+1;
	}
	if (flag == false)
	{
		printf("no such element\n");
	}
	return 0;
}