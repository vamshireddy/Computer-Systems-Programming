#include<stdio.h>


int main()
{
	int a = fork();
	if( a == 0 )
	{
		// Child
		while( getppid() != 1 )
		{
			printf("%d : My parent has not changed yet\n",getpid());
			sleep(1);
		}
		printf("My parent is init now\n");
		sleep(15);
	}
	else
	{
		sleep(10);
		exit(0);
	}
}
