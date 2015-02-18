#include<stdio.h>
#include<sys/wait.h>


int main()
{
	pid_t pid;
	if( ( pid = fork() ) == 0 )
	{
		// 1st child
		pid_t hey = fork();
		if( hey == 0 )
		{
			// 2nd child
			sleep(2);
			printf("I am 2nd child and my parent is %d\n", getppid());
			exit(0);
		}
		exit(0);
	}
	else
	{
		if( waitpid(pid, NULL, 0) != pid )
		{
			perror("Error\n");
		}
		exit(0);
	}
	
}
