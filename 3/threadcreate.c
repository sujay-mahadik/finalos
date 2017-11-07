#include <pthread.h>
#include <stdio.h>

void *thread_function(void *a){
	char *lmsg = a;
	printf("%s\n", lmsg);
	//return NULL;
}
int main(){
	pthread_t tid[2];
	char *msg = "Hello New World";
	char *msg1 = "bye World";
	pthread_create(&tid[0], NULL, thread_function, (void *) msg);
	pthread_create(&tid[1], NULL, thread_function, (void *) msg1);

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
	return 0;
}

