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
		printf("Waiting for child's death\n");
		int status;
		wait(&status);
		if( WIFEXITED(status) )
		{
			// Child exited successfully
			unsigned stat = WEXITSTATUS(status);
			printf("Child has died happily: Lower order 8 bits that child passed : %u\n",stat);
		}
		else if( WIFSIGNALED(status) )
		{	
			// Child dead with signals
			printf("Abnormal death: Caught the signal %d\n", WTERMSIG(status));
		}
	}	
	else
	{
		// Child	
		sleep(2);
		int p = 34/0;
	}
}
