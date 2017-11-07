#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAX 20

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubsort(int arr[], int n){
	int i, j;

	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if (arr[j]>arr[j+1]){
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
}
void display(int arr[], int n){
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);		/* code */
	}
}

int main()
{	
	pid_t pid, cpid;
	int i, n, *array, status;
	char no[MAX];
	void *ptr[MAX];

	printf("Enter the number of Elements\n");
	scanf("%d", &n);
	array = (int *) malloc(n * sizeof(int));
	printf("Enter the Elements\n");
	for (int i = 0; i < n; i++)
	{	
		scanf("%d", &array[i]);
		
	}
	bubsort(array, n);
		for(i=0;i<n;i++){
			ptr[i]=(char *)array[i];
			printf("%d\n", (int *)ptr[i] );
		}
	char *const argv[] = {"/home/sujay/Desktop/b", (char*) ptr, NULL};
	char *const envp[] = {NULL};

	pid = fork();
	if (pid ==0){
		printf("Child Process\n");
		execve("./b", argv, envp);
	}
	else{
		printf("In Parent Process\n");
		
		cpid = wait(&status);
	}



	return 0;
}