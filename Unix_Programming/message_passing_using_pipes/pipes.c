#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

//pass message back and forth between two processes using pipes 

int main()
{
	int fd[2];
	pipe(fd);

	int pid = fork();
	if(pid==0)
	{
		int i;
		//child
		char buffer[10];
		read(fd[0],buffer,6);
		for(i=0;i<5;i++)
		{
			buffer[i] = buffer[i]+i;
		}
		write(fd[1],buffer,6);
		close(fd[1]);
		close(fd[0]);
	}
	else if(pid>0)
	{	
		char buff[10];
		write(fd[1],"hello",6);
		wait(NULL);
		read(fd[0],buff,6);
		printf("%s",buff);
		//parent
	}
}

