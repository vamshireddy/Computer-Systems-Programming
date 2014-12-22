#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int value = 5;

int main()
{
	pid_t p;
	p = fork();
	if( p==0 )
	{
		value+=15;
		return 0;
	}
	else if( p>0 )
	{
		wait(NULL);
		printf("The value is : %d\n",value);
		return 0;
	}
}
