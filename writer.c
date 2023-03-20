#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#define SIZE 200

int main()
{
	//unique public key
	key_t key = 1000;
	// shmget returns an identifier in shmid
	int shmid = shmget(key, SIZE, 0666 | IPC_CREAT);

	// shmat to attach to shared memory
	char *str = (char*) shmat(shmid, NULL, 0);

	printf("\nWrite data..\n");
	fgets(str, SIZE, stdin);
	
	printf("Data written in memory: %s\n", str);
	
	//detach from shared memory
	shmdt(str);

	return 0;
}

