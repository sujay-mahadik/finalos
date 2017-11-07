#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void bubblesortA(int arr[], int n){
	int i, j;

	for (int i = 0; i < n-1; i++)
		for (j = 0; j<n-i-1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}
void bubblesortD(int arr[], int n){
	int i, j;

	for (int i = 0; i < n-1; i++)
		for (j = 0; j<n-i-1; j++)
			if (arr[j] < arr[j+1])
				swap(&arr[j], &arr[j+1]);
}
void display(int arr[],int n){
	printf("Sorted Array\n");
	for (int i = 0; i < n; i++)
	{	
		printf("%d ,", arr[i]);
	}
	printf("\n");
}
int main(int argc, char const *argv[])
{
	int n,nc, pid, i, array[100], arrayc[100];

	printf("Enter the number of elements\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for(i=0; i<n; i++){
		scanf("%d", &array[i]);
	}

	pid = fork();
	if (pid == 0)
	{	

		//uncomment for orphan .. check ps -ax through another terminal for changed ppid
		//sleep(20);

		printf("In Child.. Pid:%d ..PPid:%d\n", getpid(), getppid() );
		bubblesortA(array, n);
		display(array, n);
		printf("Sorted by Child\n");

		//uncomment for zombie
		//exit(0);

		/* code */
	}
	else if(pid > 0){

		//wait for all the child proceses to execute .. comment while using zombie or orphan changes
		wait(NULL);

		//uncomment for zombie
		//sleep(20);

		printf("In Parent.. Pid:%d\n", getpid());
		bubblesortD(array, n);
		display(array, n);
		printf("Sorted by Parent\n");
		
	}
	return 0;
}