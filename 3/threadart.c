#include <stdio.h>
#include <pthread.h>

typedef struct v
{
	int num1;
	int num2;
}S;

void *add(void * arg){
	
	S *op = arg;
	int result;
	result = op->num1 + op->num2;
	printf("%d\n", result);
	return NULL;
}

int main(){
	
	S number;
	pthread_t tid;
	int a, b, sum;
	

	printf("Enter number 1\n");
	scanf("%d", &a);
	printf("Enter number 2\n");
	scanf("%d", &b);

	number.num1 = a;
	number.num2 = b;

	pthread_create(&tid, NULL, add, (void *) &number);
	pthread_join(tid, NULL);
	return 0;
}