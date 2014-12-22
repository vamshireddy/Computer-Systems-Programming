#include<stdio.h>
#include<fcntl.h>

/*
	Program to test the reading of a file created by creat system call 
*/

int main()
{
	int fd = creat("vamshi.txt",0777);
	
	write(fd,"vamshi",6);

	char buf[10];

	// We can never read a file which is opened for writing. creat system call opens the file for writing only.
	int f = read(fd,buf,6);
	
	if( f == -1 )
	{
		perror("read failed");
	}

	close(fd);

	fd = open("vamshi.txt",O_RDONLY);
	if( fd == -1 )
	{
		perror("Open file");
	}
	
	read(fd,buf,6);

	write(0,"Writing ",9);
	write(0,buf,6);
}
