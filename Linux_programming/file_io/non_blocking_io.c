#include<stdio.h>
#include<fcntl.h>
#include<errno.h>

int main()
{
	int fd = open("/dev/sda",O_RDONLY | O_NONBLOCK);
	if( fd == -1 )
	{
		perror("open");
		exit(0);
	}
	char buff[10];
	int len = 10;

	int c = read(fd, buff, len);
	if( c == -1  && errno == EAGAIN )
	{
		printf("Successfully non blocked\n");
	}
	else
	{
		printf("C is %d\n",c);
	}
}
