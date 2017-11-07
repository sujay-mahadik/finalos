#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<sys/types.h>

sem_t room;
sem_t forks[5]; // 5 forks
int i=0;

void* philosopher(void*);


//-----------------------------------------------------
void main(){
	
	pthread_t tid[5]; //5 philosophers
	int thread_no[5];
	
	sem_init(&room, 0, 4); // 4 slots in a room coz spagetti requires 2 forks
	
	int j=0;
	for(j=0; j<5; j++){
		sem_init(&forks[j], 0, 1); // 5 plates therefore 5 forks, 1 of each
	}
	
	for(j=0; j<5; j++){
		thread_no[j] = j;
		pthread_create(&tid[j], NULL, philosopher, &thread_no[j]);
	}
	//printf("Here 1\n");
	
	for(j=0; j<5; j++){
		pthread_join(tid[j], NULL);
	}
	
}

//-----------------------------------------------------
void* philosopher(void* a){
	int thread_no = *(int*) a;
	int count=3;
	
	while(count > 0){
		sem_wait(&room);
			printf("Philosopher %d entered room , count = %d ...\n", thread_no, count);
			int forkNo = i++;
			
			sem_wait(&forks[forkNo % 5]); //dedicated left fork
				
				sem_wait(&forks[(forkNo+1) % 5]); //available right fork
					printf("Philosopher %d Eating :)\n", thread_no);
					sleep(1);
				sem_post(&forks[(forkNo+1) % 5]);
					printf("Philosopher %d done eating *_*\n", thread_no);
			sem_post(&forks[forkNo % 5]);
		sem_post(&room);
		
		count--;
	}
	pthread_exit(NULL);
}
