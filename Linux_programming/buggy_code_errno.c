#include<stdio.h>
#include<errno.h>
#include<fcntl.h>

/*
	This code is buggy because, the fprintf statment can also modify errno
	and can overwrite the errno of the failed fd, and nothing prints
*/

int main()
{
	int fd = open("hello",O_RDONLY);
	if( fd == -1 )
	{
		// Errno is set for open fail
		// This can modify the errno value
		fprintf(stdin,"Open error\n");
		// errno is changed to printf failed
		if( errno == ENOENT )
		{
			// Not executed
			perror("fd");
		}
	}
}
