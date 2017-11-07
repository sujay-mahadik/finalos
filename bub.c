#include<stdio.h>
#include<unistd.h>

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

int main(int argc, char const *argv[])
{	
	int n, array[100], i;
	printf("Enter the number of element\n");
	scanf("%d", &n);
	printf("Enter element\n");
	for (i = 0; i < n; i++)		
	{	
		scanf("%d", &array[i]);
		/* code */
	}

	bubblesort(array, n);
	display(array, n);

	return 0;
}