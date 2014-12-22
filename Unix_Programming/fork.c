#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/signal.h>
#include<fcntl.h>
#include<errno.h>
#include<sys/wait.h>
int main()
{
	pid_t id;
	int rv;

	switch(id = fork())
	{
		case 0 : printf("CHILD : This is a child process\n");
			printf("CHILD : My pid is %d\n",getpid());
			printf("CHILD : My parent pid is %d\n",getppid());
			printf("CHILD : My exit status is 1i\n");
			exit(1);
		case -1 : perror("fork");
			exit(1);
		default: printf("PARENT : this is parent !\n");
			printf("PARENT : my pid is %d\nPARENT : my child pid is %d\n",getpid(),id);
			printf("PARENT : I am waiting for my child to exit \n");
			wait(&rv);
			printf("PARENT : My child exit is %d\n",WEXITSTATUS(rv));
			printf("PARENT : I AM OUTA HERE \n");
	}
	return 0;
}
