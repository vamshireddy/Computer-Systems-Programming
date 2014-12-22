#include<stdio.h>
#include<fcntl.h>

int main()
{
	int fd = open("hello",O_RDWR|O_TRUNC);
	int fd2 = dup(fd);
	printf("%d %d\n",fd,fd2);
	char buffer[10];
	int a = read(fd,buffer,4);
	printf("%d %s\n",a,buffer);
	a = read(fd2,buffer,4);
	printf("%d %s\n",a,buffer);
}
