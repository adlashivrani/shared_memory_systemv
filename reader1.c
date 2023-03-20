#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SIZE 200

int main()
{
	// ftok to generate unique key
	//key_t key = ftok("shmfile",65);
	key_t key = 1000;
	// shmget returns an identifier in shmid
	int shmid = shmget(key, SIZE, 0666);

	// shmat to attach to shared memory
	char *str = (char*) shmat(shmid, NULL, SHM_RDONLY);

	//reading first 10 bytes of data
	printf("Data read from memory: %s\n", str);
	
	//detach from shared memory
	shmdt(str);

	//shmctl(shmid,IPC_RMID,NULL);
	
	return 0;
}

