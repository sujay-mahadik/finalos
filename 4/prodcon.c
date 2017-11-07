#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>

void * producer(void * n);
void * consumer(void * n);
sem_t f, e;
pthread_mutex_t buffmutex;
int buff[10], buffindex;

int main(){
	int i, n= 10, thread_no[10];
	pthread_t tid[10];
	sem_init(&f, 0, 5);
	sem_init(&e, 0, 0);
	pthread_mutex_init(&buffmutex, NULL);

	for(i=0; i< n; i++){
		thread_no[i]=i;
		pthread_create(&tid[i], NULL, producer, &thread_no[i]);
		i++;
		thread_no[i]=i;
		pthread_create(&tid[i], NULL, consumer, &thread_no[i]);
	}

	for(i=0; i<10; i++){
		pthread_join(tid[i], NULL);
	}

	sem_destroy(&f);
	sem_destroy(&e);
	pthread_mutex_destroy(&buffmutex);
	return 0;
}

void * producer (void * n){
	int t_no = *(int *)n;
	int value = rand()%90;

	sem_wait(&f);
		pthread_mutex_lock(&buffmutex);
			buff[buffindex++]= value;
			printf("thread_no %d produced >> %d\n", t_no, value );
		pthread_mutex_unlock(&buffmutex);
	sem_post(&e);

	pthread_exit(NULL);
}

void * consumer (void * n){
	int t_no = *(int *)n;
	int value;

	sem_wait(&e);
		pthread_mutex_lock(&buffmutex);
			value = buff[--buffindex];
			printf("thread_no %d consumed << %d\n", t_no, value);
		pthread_mutex_unlock(&buffmutex);
	sem_post(&f);

	pthread_exit(NULL);
}