#include "stdio.h"
#include "sys/ipc.h"
#include "sys/shm.h"
#include "sys/types.h"

int main(){
	key_t key;
	key = ftok("./newfile", 'S');

	printf("%d\n", key);
	return 0;
}
