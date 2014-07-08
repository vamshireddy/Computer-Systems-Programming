#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/signal.h>

int main()
{
	signal(SIGCHLD,SIG_IGN);
	int p = fork();
	fork();
	fork();
}

