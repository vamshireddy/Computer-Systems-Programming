#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd = open("vamshi.txt",O_RDONLY);

	int size = lseek(fd,0,SEEK_END);

	int start = size/2;

	lseek(fd,start,SEEK_SET);
	
	char c;

	while( read(fd,&c,1) != 0 )
	{
		write(1,&c,1);
	}
}
