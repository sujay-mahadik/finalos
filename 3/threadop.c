#include <stdio.h>
#include <pthread.h>

void *thread_function(void *arg){
	int *a =  arg;
	int b = 5 + *a;
	return (void *) b;
}

int main(){
	pthread_t tid;
	int num = 5, value;

	pthread_create(&tid, NULL, thread_function, (void *) &num);
	pthread_join(tid, (void *) &value);
	printf("%d\n", value);
	return 0;
}