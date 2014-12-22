#include<stdio.h>


int main()
{
	printf("pid: %d uid : %d gid : %d\n",getppid(), getuid(),getgid());
}
