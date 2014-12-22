
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/types.h>

int main()
{
	int common_id = 1234;
	int shared_memory_id = shmget(common_id,20,0600);
	char* shared_memory = (char*)shmat(shared_memory_id,NULL,0);
	char* s = shared_memory;
	*shared_memory++ = 'v';
	*shared_memory++ = 'a';
	*shared_memory++ = 'm';
	shared_memory = NULL;
	while(*s!='*')
	{
		
	}
	return 0;
}
