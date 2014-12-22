#include<stdio.h>
#include<fcntl.h>

/*
	O_TRUNC flag truncated the exisiting file 
	*/

int main()
{
	int fd = open("vamshi.txt",O_RDONLY|O_TRUNC);

	close(fd);
}
