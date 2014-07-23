#include<stdio.h>
#include<fcntl.h>
int main()
{
	int a = open("hello",O_RDWR);

	int val;

	if( ( val = fcntl(a,F_GETFL,0)) < 0 )
	{
		perror("");
	}

	switch ( val & O_ACCMODE )
	{
		case O_RDONLY:
				printf("Read only\n");
				break;
		case O_WRONLY:
				printf("Write only\n");
				break;
		case O_RDWR:	printf("read and write\n");
				break;
	}
	if( val & O_NONBLOCK )
	{
		printf("non block\n");
	}

}
