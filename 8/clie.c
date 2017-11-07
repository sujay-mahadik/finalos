#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#define sz 1024
main(){
	key_t key;
	key = ftok("./keyfile", '1');
	int shmid;
	char *shm, *s;

	shmid = shmget(key, sz, 0666);

	shm = shmat(shmid, NULL, 0);

	printf("data read\n");
	
	/*
	for(s=shm; *s != NULL; s++){
          putchar(*s);
     }
     */
	s=shm;
	puts(s);

	*shm = '*';
	int detach = shmdt(shm);
	shmctl(shmid, IPC_RMID, NULL);
	exit(0);

}