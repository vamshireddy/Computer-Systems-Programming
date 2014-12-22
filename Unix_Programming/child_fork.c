#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	int pid = fork();
	if(pid == 0)
	{
		//child
		execlp("/bin/ps","ps -el",NULL);
	}
	else
	{
		
		int ret = wait(NULL);
		printf("The child is %d and ret code is %d \n",pid,ret);
		printf("I am Parent \n\n");
	}
}
