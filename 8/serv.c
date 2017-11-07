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

	shmid = shmget(key, sz, IPC_CREAT  | 0666);

	shm = shmat(shmid, NULL, 0);

	printf("Enter data\n");
	s= shm;
	scanf("%s", s);

	while(*shm != '*');
	exit(0);


}