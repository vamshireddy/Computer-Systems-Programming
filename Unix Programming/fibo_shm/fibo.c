#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<sys/stat.h>
	// This program demonstrates how to use shared memory to pass the data between child and parent processes
#define MAX_SIZE 10

typedef struct fib_mem
{
	int array[MAX_SIZE];
	int size;
}fib_mem;

int main()
{
	printf("Enter the limit : ");	
	int a;
	scanf("%d",&a);
	if(a > MAX_SIZE)
	{
		printf("Error in the size\n");
		return ;
	}

	//int shared_mem = shmget(IPC_PRIVATE,sizeof(fib_mem),S_IRUSR|S_IWUSR);
	
	int shared_mem = shmget(1234,sizeof(fib_mem),IPC_CREAT|0600);

	fib_mem* mem_ptr = (fib_mem*)shmat(shared_mem,NULL,0);
	mem_ptr->size = a;
	int pid = fork();
	if( pid == 0)
	{
		//child
		int i;
		int temp1=0,temp2=1;
		if(mem_ptr->size==1)
		{
			mem_ptr->array[0] = 0;
		}
		else if(mem_ptr->size==2)
		{
			mem_ptr->array[1] = 1;
			mem_ptr->array[0] = 0;
		}
		else
		{

			mem_ptr->array[1] = 1;
			mem_ptr->array[0] = 0;
			for(i=0;i<mem_ptr->size;i++)
			{
				int temp = temp1+temp2;
				mem_ptr->array[i+2] = temp;
				temp1 = temp2;
				temp2 = temp;
			}
		}
		return 0;
	}
	else if(pid>0)
	{
		//parent
		wait(NULL);
		int i;
		for(i=0;i<mem_ptr->size;i++)
		{
			printf("%d  ",mem_ptr->array[i]);
		}
	}
	else
	{
		//error
		printf("Error in forking\n");
		return;
	}
}
