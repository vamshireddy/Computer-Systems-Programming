#include<stdio.h>
#include<sys/wait.h>

void sig_chld()
{
	printf("Caught sig child\n\n");
}

int main()
{
	int a = fork();
	if( a > 0 )
	{
		// Parent
		signal(SIGCHLD,sig_chld);
		sleep(5);
		printf("Slept for child\n");
		wait(NULL);
	}	
	else
	{
		sleep(2);
		// Child	
		exit(0);
	}
}
