#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	char * src = "hello.txt";
	char * dest = "h.txt";
	
	int fd[2];

	if(pipe(fd)==-1)
	{
		printf("Pipe Failure\n");
		return;
	}

	int src_file = open(src,O_RDWR);
	char c;
	close(fd[0]);
	
	pid_t p = fork();
	if(p==0)
	{
		close(fd[1]);
		char str[1000];
		read(fd[0],str,1000);
		printf("%s",str);
		//int dest_file = open(dest,O_RDWR|O_CREAT);
	}
	else
	{
		wait(NULL);
	}
}
