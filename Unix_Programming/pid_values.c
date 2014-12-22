#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

int main()
{
	pid_t p,p1;
	printf("the parent = %d",getpid());
	
	p = fork();
	if( p == 0 )
	{

	printf("the child = %d",getpid());
		p1 = getpid();
		printf(" The pid are %d %d \n",p,p1);
	}
	else if( p>0 )
	{
		p1 = getpid();
		printf(" The pid are %d %d \n",p,p1);
		int a;
		wait(&a);
		printf("\n\n a = %d",a);
	}
	return 0;
}
