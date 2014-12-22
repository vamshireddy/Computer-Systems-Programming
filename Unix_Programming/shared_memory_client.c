
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
	int shm_id = 1234;
	int sh_mem_id = shmget(shm_id,20,IPC_CREAT|0600);
	char* shared_memory = (char*) shmat(sh_mem_id,NULL,0);
	printf("%s",shared_memory);
	*shared_memory = '*';
	return 0;
}
