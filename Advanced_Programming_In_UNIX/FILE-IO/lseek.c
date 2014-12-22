#include<stdio.h>
#include<fcntl.h>
/*
	Program to find the current file offset 
*/

int main()
{
	int fd = open("vamshi.txt",O_RDONLY);

	int off = lseek(fd,0,SEEK_CUR);
	
	int size = lseek(fd,0,SEEK_END);

	printf("off is %d\nSize of the file is %d\n",off,size);

	close(fd);

	fd = open("vamshi.txt",O_RDONLY|O_APPEND);

	off = lseek(fd,0,SEEK_CUR);

	printf("off is %d using O_APPEND flag\n",off);

}
