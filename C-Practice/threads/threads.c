#include<stdio.h>
#include<pthread.h>

int main()
{
	pthread_t p;
	p = pthread_self();
	printf("%d",p);
	if( pthread_equal(p,p) == 1 )
	{
		printf("Equal\n");
	}
	else
	{
		printf("Not equal\n");
	}
}
