#include<stdio.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	int seg_id = shmget(1234,10,0600);
	struct shmid_ds seg;
	shmctl(seg_id,IPC_STAT,&seg);
	printf("Segment id = %lf\n",seg_id);
	printf("Key = %lf\n",seg.shm_perm.__key);
	printf("Mode = %lf\n",seg.shm_perm.mode);
	printf("Owner ID = %lf\n",seg.shm_perm.uid);
	printf("Size = %lf\n",seg.shm_segsz);
	printf("Number of Attaches = %lf\n",seg.shm_nattch);
}
