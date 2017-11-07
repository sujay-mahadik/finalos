#include <stdio.h>
#define MAX 10

int binarys(int a[MAX], int n, int key){
	int low, high, mid;
	low=0;
	high= n-1;
	while(low<high){
		mid = (low +high)/2;
		if(a[mid] == key) return mid;
		else if (key<a[mid])
			high = mid -1;
		else
			low = mid+1;
	}
	return -1;
}

int main(int argc, char *argv[], char *envp[])
{
	int r, key, a[MAX], n=5;

	void *c = argv[1];
	int *p = (int*)c;
	printf("Number is %d", *p);
	printf("\nHello\n");
	for(r=0;r<n;r++){
		a[r]= atoi(c);
		printf("%d\n", a[r] );
		c++;
	}
	printf("Enter the number to be searched\n");
	scanf("%d", &key);

	r = binarys(a, n, key);
	printf("%d\n", r);

	return 0;
}