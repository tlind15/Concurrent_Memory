#include <stdio.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>

int main () {

	key_t key = 123;
	const int size = 1024;
	int shm_id;
	int* shaddr, *ptr;
	
	shm_id = shmget(key, size, IPC_CREAT);
	
	shaddr = (int*) shmat(shm_id,0,0);

	printf("Shared memory attached at: %p\n", shaddr);

	shmdt(shaddr); 

	shmctl(shm_id, IPC_RMID, 0);

	return 0;
	
}
