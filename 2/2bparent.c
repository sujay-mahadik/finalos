#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
#include<sys/wait.h>
#define MAX 20

void swap(int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubblesort(int array[], int n){
	int i, j;
	for (int i = 0; i < n-1; i++)
	{
		/* code */
		for (int j= 0; j < n-i-1; j++)
		{
			if (array[j] >= array[j+1])
			{
				swap(&array[j], &array[j+1]);
				/* code */
			}
			/* code */
		}
	}
}

void display(int arr[], int n){
	int i;

	for (int i = 0; i < n; i++)
	{
		printf("%d\t", arr[i] );
		/* code */
	}
}

int main()
{
	int i, n, array[MAX];
	char *arg[MAX], str[MAX];
	pid_t pid;

	printf("Enter the number of elements\n");
	scanf("%d", &n);
	printf("Enter the elements\n");
	for(i=0;i<n; i++){
		scanf("%d", &array[i]);
	}

	bubblesort(array, n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", array[i] );
		/* code */
	}
	printf("Sorted array by parent\n");
	
	for(i=0; i<n;i++){
		sprintf(str, "%d", array[i]);
		arg[i] = malloc(sizeof(str));
		strcpy(arg[i], str);
	}

	pid = fork();

	if (pid == 0)
	{	
		printf("In child pid : %d ppid : %d\n", getpid(), getppid());
		execve("./b", arg, NULL);
		/* code */
	}
	else{
		wait(NULL);
	}
	return 0;
}