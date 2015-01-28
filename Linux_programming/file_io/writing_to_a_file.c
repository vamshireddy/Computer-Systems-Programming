#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main()
{
	int fd = open("hello.txt",O_WRONLY|O_APPEND);

	char* buff = "Hey how are you man!";

	int wb = write(fd,buff,strlen(buff));

	if( wb == strlen(buff))
	{
		printf("Written succesfully\n");
	}
	else
	{
		perror("Write");
	}
	sync();
}
