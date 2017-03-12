#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <string.h>

int main () {

	key_t key = 123;
	const int size = 1024;
	int shm_id;
	int* array;
	
	shm_id = shmget(key, size, IPC_CREAT | IPC_EXCL | 0666);

	if (shm_id < 0) {
		perror("shmget");
		exit(1);
	}

	array = (int*) shmat(shm_id,0,0);
	printf("Shared memory id: %d\n", shm_id);
	
	int i = 0;
	array[0] = 5;

	/*int j = 0;
	for (j=0; j < 3; j++) {
		printf("%d", array[j]);
	}*/

	printf("%d", array[0]);

	shmdt(array); 

	shmctl(shm_id, IPC_RMID, NULL);

	return 0;
	
}
