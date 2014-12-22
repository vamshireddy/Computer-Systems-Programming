#include<stdio.h>

int main()
{
	printf("The current process id is %d\n",getpid());
	printf("The parent process id is %d\n",getppid());
	printf("The user id is %d\n",getuid());
	
	int* a = (int*)malloc(sizeof(int));
	
	*a = 12;

	printf(" A value from the parent is %d\n",*a);

	int f = fork();

	printf(" A value from id = %d is %d\n",getpid(),*a);

	exit(0);
}
