#include<stdio.h>


int main()
{
	int i;
	for(i=0;i<3;i++)
	{
		int a = fork();
	}
	printf("i am  %d\n",getpid());
}
