#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


void printids(char* c)
{
	pid_t p;
	pthread_t t;
	p = getpid();
	t = pthread_self();
	printf("%s  Thread = %u and Process = %u\n",c,(unsigned int)t,(unsigned int)p);
}

void* thr_fn()
{
	printids("New thread: ");
	return ((void*)0);
}

int main()
{
	int err;
	pthread_t tid;
	err = pthread_create(&tid, NULL, thr_fn, NULL);
	
	if( err != 0 )
	{
		exit(0);
	}
	sleep(1);
	printids("Main thread");
	exit(0);
}
