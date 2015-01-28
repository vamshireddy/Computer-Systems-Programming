#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

/*
	Create system call will open the file for writing, if file exists already, then it iwll truncate the file
*/

/*int create(char* name, int mode)
{	
	printf("I am in the user defined create call\n");
	return open(name, O_WRONLY|O_TRUNC|O_CREAT, mode);
}
*/
int main()
{
	int fd = creat("hello.txt",0777);
	if( fd == -1 )
	{
		perror("Create");
	}
}
