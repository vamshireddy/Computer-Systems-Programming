#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void* print_func(void* atr)
{
	char* msg;
	msg = (char*)atr;
	printf("%s.. Im gone..  \n",msg);
}

int main()
{
	pthread_t t1,t2;
	const char* msg1 = "Thread 1";
	const char* msg2 = "Thread 2";
	int iret1,iret2;

	iret1 = pthread_create(&t1,NULL,print_func,(void *) msg1);
	iret2 = pthread_create(&t2,NULL,print_func,(void *) msg2);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("\nThread 1 returdes = %d\n thread 2 returned = %d\n",iret1,iret2);
	exit(0);
}



